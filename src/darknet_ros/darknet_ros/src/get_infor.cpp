#include <iostream>
#include <vector>

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <eigen3/Eigen/Geometry>
#include <cv_bridge/cv_bridge.h>

#include <darknet_ros_msgs/BoundingBox.h>
#include <darknet_ros_msgs/BoundingBoxes.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/PointCloud2.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/PoseStamped.h>
#include <darknet_ros_msgs/pose_info.h>

#include <std_msgs/Float64.h>

using namespace std;
sensor_msgs::PointCloud2 my_pcl;


class aruco_detect
{

    ros::NodeHandle nh;
    ros::Subscriber sub1;
    ros::Subscriber sub2;
    ros::Subscriber sub3;
    image_transport::ImageTransport it;
    image_transport::Subscriber sub_image;
    ros::Publisher pub_, marker_pose_pub_;
    

    int Xmin = 0;
    int Ymin = 0;
    int Xmax = 0;
    int Ymax = 0;

    int center_x = 0;
    int center_y = 0;

    float trans_x1 = 0.0;
    float trans_y1 = 0.0;
    float trans_z1 = 0.0;

    double marker_x_;
    double marker_y_;
    double marker_z_;
    
public:
    aruco_detect()
        :it(nh)
    {
        sub1 = nh.subscribe("/darknet_ros/bounding_boxes", 5, &aruco_detect::boxcallback, this);
        sub_image = it.subscribe("/darknet_ros/detection_image", 5, &aruco_detect::imageCallback, this);
        // sub2 = nh.subscribe("/camera/aligned_depth_to_color/image_raw", 5, &aruco_detect::depthcallback, this);
        sub3 = nh.subscribe("/camera/depth_registered/points", 1, &aruco_detect::depthcallback1, this);
        pub_ = nh.advertise<darknet_ros_msgs::pose_info>("/get_infor/pose", 1);
        marker_pose_pub_ = nh.advertise<geometry_msgs::PoseStamped>("/marker_pose", 5);
        
        marker_x_ = 0.0;
        marker_y_ = 0.0;
        marker_z_ = 0.0;
    }
    ~aruco_detect()
    {
        cv::destroyWindow("view1");
        cv::destroyWindow("view");
    }
    
    void imageCallback(const sensor_msgs::ImageConstPtr& msg){

        cv_bridge::CvImagePtr cam_image;

        try{
            cam_image = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
            
            // cv::imshow("view", cam_image->image);
            // cv::waitKey(30);
        }
        catch(cv_bridge::Exception& e){
            ROS_ERROR("Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
        }
        std::vector<int> markerIds;
        std::vector<std::vector<cv::Point2f>> markerCorners;
        cv::Mat cameraMatrix = cv::Mat::zeros(3,3, CV_32F); 
        cv::Mat distCoeffs = cv::Mat::zeros(1,5, CV_32F);
        std::vector<cv::Vec3d> rvecs, tvecs;

        cv::Matx33d R;
        
        cameraMatrix.at<float>(0, 0) = 954.21086;
        cameraMatrix.at<float>(1, 1) = 962.180001;
        cameraMatrix.at<float>(0, 2) = 623.187792;
        cameraMatrix.at<float>(1, 2) = 366.666945;
        cameraMatrix.at<float>(2, 2) = 1.0;
                
        distCoeffs.at<float>(0, 0) = 0.168433;
        distCoeffs.at<float>(0, 1) = -0.310664;
        distCoeffs.at<float>(0, 2) = 0.005343;
        distCoeffs.at<float>(0, 3) = 0.001095;
        distCoeffs.at<float>(0, 4) = 0.0;
        
        
        // darknet_ros_msgs::pose_info pose_msg;
        
        cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_250);
        cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
        cv::aruco::detectMarkers(cam_image->image, dictionary, markerCorners, markerIds, parameters);
        cv::aruco::estimatePoseSingleMarkers(markerCorners, 0.01, cameraMatrix, distCoeffs, rvecs, tvecs);
        // cv::aruco::drawDetectedMarkers(cam_image->image, markerCorners, markerIds);
        for (int i = 0; i < markerCorners.size(); i++)
        {
            cv::aruco::drawAxis(cam_image->image, cameraMatrix, distCoeffs, rvecs[i], tvecs[i], 0.05);
        }
        // cv::imshow("view3", cam_image->image);
        // cv::waitKey(30);

        if (rvecs.size() != 0)
        {
            double r_x = rvecs[0](0);
            double r_y = rvecs[0](1);
            double r_z = rvecs[0](2);
            double theta = std::sqrt(std::pow(r_x, 2) + std::pow(r_y, 2) + std::pow(r_z, 2));
            r_x = r_x / theta;
            r_y = r_y / theta;
            r_z = r_z / theta;
            cv::Vec3d rod_vec;
            rod_vec(0) = r_x;
            rod_vec(1) = r_y;
            rod_vec(2) = r_z;
            cv::Matx33d I(1.0, 0.0, 0.0,
                          0.0, 1.0, 0.0,
                          0.0, 0.0, 1.0),
                skew(0.0, -r_z, r_y,
                     r_z, 0.0, -r_x,
                     -r_y, r_x, 0.0);
            R = std::cos(theta) * I + (1 - std::cos(theta)) * rod_vec * rod_vec.t() + std::sin(theta) * skew;
            geometry_msgs::PoseStamped marker_pose;
            marker_pose.header.frame_id = "camera_color_optical_frame";
            marker_pose.header.stamp = ros::Time::now();
            marker_pose.pose.position.x = marker_x_;
            marker_pose.pose.position.y = marker_y_;
            marker_pose.pose.position.z = marker_z_;
            double q[4];
            getQuaternion(R, q);
            marker_pose.pose.orientation.x = q[0];
            marker_pose.pose.orientation.y = q[1];
            marker_pose.pose.orientation.z = q[2];
            marker_pose.pose.orientation.w = q[3];
            marker_pose_pub_.publish(marker_pose);
        }

        // rvec = DoubleMatFromVec3d(rvecs);
        // for (size_t i =0; i< rvecs.size(); ++i)
        // {
        //     // cout << rvecs.at(i)[2] << ";" << endl;
        //     pose_msg.rvec_x = rvecs.at(i)[0];
        //     pose_msg.rvec_y = rvecs.at(i)[1];
        //     pose_msg.rvec_y = rvecs.at(i)[2];
        // }
        // for (size_t i =0; i< tvecs.size(); ++i)
        // {
        //     cout << tvecs.at(i) << ";;;" << endl;
        // }
        
        
        // cout<<pose_msg.rvec_y<<endl;
     
        
        
        // pose_msg.trans_x = trans_x1; 
        // pose_msg.trans_y = trans_y1;
        // pose_msg.trans_z = trans_z1;
        // pub_.publish(pose_msg);
    }

    void boxcallback(const darknet_ros_msgs::BoundingBoxes::ConstPtr &msg)
    {
        // cout<<"Bouding Boxes (header):" << msg->header <<endl;
        // cout<<"Bouding Boxes (image_header):" << msg->image_header <<endl;
        // cout<<"Bouding Boxes (Class):" << msg->bounding_boxes[0].Class <<endl;
        // cout<<"Bouding Boxes (xmin):" << msg->bounding_boxes[0].xmin <<endl;
        // cout<<"Bouding Boxes (xmax):" << msg->bounding_boxes[0].xmax <<endl;
        // cout<<"Bouding Boxes (ymin):" << msg->bounding_boxes[0].ymin <<endl;
        // cout<<"Bouding Boxes (ymax):" << msg->bounding_boxes[0].ymax <<endl;

        Xmin = msg->bounding_boxes[0].xmin;
        Ymin = msg->bounding_boxes[0].ymin;
        Xmax = msg->bounding_boxes[0].xmax;
        Ymax = msg->bounding_boxes[0].ymax;
        center_x = (Xmin + Xmax)/2;
        center_y = (Ymin + Ymax)/2;
       
    }

    void depthcallback(const sensor_msgs::ImageConstPtr& msg)
    {
        cv_bridge::CvImagePtr cv_ptr;
        try
        {
            cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::TYPE_16UC1);

        }
        catch(cv_bridge::Exception& e)
        {
            ROS_ERROR("cv_bridge exception: %s", e.what());
            return;
        }
        // cout<<"####"<<endl;
        // cout<<"Bouding Boxes (xmin):" << Xmin <<endl;
        // cout<<"Bouding Boxes (xmax):" << Xmax <<endl;
        // cout<<"Bouding Boxes (ymin):" << Ymin <<endl;
        // cout<<"Bouding Boxes (ymax):" << Ymax <<endl;
        center_x = (Xmin + Xmax)/2;
        center_y = (Ymin + Ymax)/2;

        cv::Mat depth_matrix = cv_ptr->image;
        
        float a = depth_matrix.at<uchar>(center_y, center_x);
        
        // cout<<a<<endl;
        // cv::imshow("view1", cv_ptr->image);
        // cv::waitKey(30);
        }

    void getXYZ(int x, int y)
    {
        int arrayPosition = y*my_pcl.row_step + x*my_pcl.point_step;
        int arrayPosX = arrayPosition + my_pcl.fields[0].offset; // X has an offset of 0
        int arrayPosY = arrayPosition + my_pcl.fields[1].offset; // Y has an offset of 4
        int arrayPosZ = arrayPosition + my_pcl.fields[2].offset; // Z has an offset of 8

        float X = 0.0;
        float Y = 0.0;
        float Z = 0.0;

        memcpy(&X, &my_pcl.data[arrayPosX], sizeof(float));
        memcpy(&Y, &my_pcl.data[arrayPosY], sizeof(float));
        memcpy(&Z, &my_pcl.data[arrayPosZ], sizeof(float));

        geometry_msgs::Point position;
        // position.x = X;
        // position.y = Y;
        // position.z = Z; 
        // trans_x1 = X;
        // trans_y1 = Y;
        // trans_z1 = Z;
        // cout<<"X position: "<<X<<"m"<<endl;
        // cout<<"Y position: "<<Y<<"m"<<endl;
        // cout<<"Z position: "<<Z<<"m"<<endl;

        marker_x_ = X;
        marker_y_ = Y;
        marker_z_ = Z;
    }

    void depthcallback1(const sensor_msgs::PointCloud2ConstPtr& cloud_msg)
    {
        my_pcl = *cloud_msg;
        getXYZ(center_x , center_y);
    }

    void getQuaternion(cv::Matx33d R, double Q[])
    {
        double trace = R(0, 0) + R(1, 1) + R(2, 2);

        if (trace > 0.0)
        {
            double s = sqrt(trace + 1.0);
            Q[3] = (s * 0.5);
            s = 0.5 / s;
            Q[0] = ((R(2, 1) - R(1, 2)) * s);
            Q[1] = ((R(0, 2) - R(2, 0)) * s);
            Q[2] = ((R(1, 0) - R(0, 1)) * s);
        }

        else
        {
            int i = R(0, 0) < R(1, 1) ? (R(1, 1) < R(2, 2) ? 2 : 1) : (R(0, 0) < R(2, 2) ? 2 : 0);
            int j = (i + 1) % 3;
            int k = (i + 2) % 3;

            double s = sqrt(R(i, i) - R(j, j) - R(k, k) + 1.0);
            Q[i] = s * 0.5;
            s = 0.5 / s;

            Q[3] = (R(k, j) - R(j, k)) * s;
            Q[j] = (R(j, i) + R(i, j)) * s;
            Q[k] = (R(k, i) + R(i, k)) * s;
        }
        return;
    };
};


int main(int argc, char **argv){
    
    ros::init(argc, argv, "get_infor");
    aruco_detect ad;
    // cv::namedWindow("view");
    // cv::namedWindow("view1");
    
    ros::spin();
    
}
