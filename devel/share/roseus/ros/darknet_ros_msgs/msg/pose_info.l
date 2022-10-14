;; Auto-generated. Do not edit!


(when (boundp 'darknet_ros_msgs::pose_info)
  (if (not (find-package "DARKNET_ROS_MSGS"))
    (make-package "DARKNET_ROS_MSGS"))
  (shadow 'pose_info (find-package "DARKNET_ROS_MSGS")))
(unless (find-package "DARKNET_ROS_MSGS::POSE_INFO")
  (make-package "DARKNET_ROS_MSGS::POSE_INFO"))

(in-package "ROS")
;;//! \htmlinclude pose_info.msg.html


(defclass darknet_ros_msgs::pose_info
  :super ros::object
  :slots (_rvec_x _rvec_y _rvec_z _trans_x _trans_y _trans_z ))

(defmethod darknet_ros_msgs::pose_info
  (:init
   (&key
    ((:rvec_x __rvec_x) 0.0)
    ((:rvec_y __rvec_y) 0.0)
    ((:rvec_z __rvec_z) 0.0)
    ((:trans_x __trans_x) 0.0)
    ((:trans_y __trans_y) 0.0)
    ((:trans_z __trans_z) 0.0)
    )
   (send-super :init)
   (setq _rvec_x (float __rvec_x))
   (setq _rvec_y (float __rvec_y))
   (setq _rvec_z (float __rvec_z))
   (setq _trans_x (float __trans_x))
   (setq _trans_y (float __trans_y))
   (setq _trans_z (float __trans_z))
   self)
  (:rvec_x
   (&optional __rvec_x)
   (if __rvec_x (setq _rvec_x __rvec_x)) _rvec_x)
  (:rvec_y
   (&optional __rvec_y)
   (if __rvec_y (setq _rvec_y __rvec_y)) _rvec_y)
  (:rvec_z
   (&optional __rvec_z)
   (if __rvec_z (setq _rvec_z __rvec_z)) _rvec_z)
  (:trans_x
   (&optional __trans_x)
   (if __trans_x (setq _trans_x __trans_x)) _trans_x)
  (:trans_y
   (&optional __trans_y)
   (if __trans_y (setq _trans_y __trans_y)) _trans_y)
  (:trans_z
   (&optional __trans_z)
   (if __trans_z (setq _trans_z __trans_z)) _trans_z)
  (:serialization-length
   ()
   (+
    ;; float64 _rvec_x
    8
    ;; float64 _rvec_y
    8
    ;; float64 _rvec_z
    8
    ;; float64 _trans_x
    8
    ;; float64 _trans_y
    8
    ;; float64 _trans_z
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _rvec_x
       (sys::poke _rvec_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _rvec_y
       (sys::poke _rvec_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _rvec_z
       (sys::poke _rvec_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _trans_x
       (sys::poke _trans_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _trans_y
       (sys::poke _trans_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _trans_z
       (sys::poke _trans_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _rvec_x
     (setq _rvec_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _rvec_y
     (setq _rvec_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _rvec_z
     (setq _rvec_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _trans_x
     (setq _trans_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _trans_y
     (setq _trans_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _trans_z
     (setq _trans_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get darknet_ros_msgs::pose_info :md5sum-) "03971dbefaf1ae5a8bc19cc37c05b54e")
(setf (get darknet_ros_msgs::pose_info :datatype-) "darknet_ros_msgs/pose_info")
(setf (get darknet_ros_msgs::pose_info :definition-)
      "float64 rvec_x
float64 rvec_y
float64 rvec_z
float64 trans_x
float64 trans_y
float64 trans_z

")



(provide :darknet_ros_msgs/pose_info "03971dbefaf1ae5a8bc19cc37c05b54e")


