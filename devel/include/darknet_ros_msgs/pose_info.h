// Generated by gencpp from file darknet_ros_msgs/pose_info.msg
// DO NOT EDIT!


#ifndef DARKNET_ROS_MSGS_MESSAGE_POSE_INFO_H
#define DARKNET_ROS_MSGS_MESSAGE_POSE_INFO_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace darknet_ros_msgs
{
template <class ContainerAllocator>
struct pose_info_
{
  typedef pose_info_<ContainerAllocator> Type;

  pose_info_()
    : rvec_x(0.0)
    , rvec_y(0.0)
    , rvec_z(0.0)
    , trans_x(0.0)
    , trans_y(0.0)
    , trans_z(0.0)  {
    }
  pose_info_(const ContainerAllocator& _alloc)
    : rvec_x(0.0)
    , rvec_y(0.0)
    , rvec_z(0.0)
    , trans_x(0.0)
    , trans_y(0.0)
    , trans_z(0.0)  {
  (void)_alloc;
    }



   typedef double _rvec_x_type;
  _rvec_x_type rvec_x;

   typedef double _rvec_y_type;
  _rvec_y_type rvec_y;

   typedef double _rvec_z_type;
  _rvec_z_type rvec_z;

   typedef double _trans_x_type;
  _trans_x_type trans_x;

   typedef double _trans_y_type;
  _trans_y_type trans_y;

   typedef double _trans_z_type;
  _trans_z_type trans_z;





  typedef boost::shared_ptr< ::darknet_ros_msgs::pose_info_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::darknet_ros_msgs::pose_info_<ContainerAllocator> const> ConstPtr;

}; // struct pose_info_

typedef ::darknet_ros_msgs::pose_info_<std::allocator<void> > pose_info;

typedef boost::shared_ptr< ::darknet_ros_msgs::pose_info > pose_infoPtr;
typedef boost::shared_ptr< ::darknet_ros_msgs::pose_info const> pose_infoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::darknet_ros_msgs::pose_info_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::darknet_ros_msgs::pose_info_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::darknet_ros_msgs::pose_info_<ContainerAllocator1> & lhs, const ::darknet_ros_msgs::pose_info_<ContainerAllocator2> & rhs)
{
  return lhs.rvec_x == rhs.rvec_x &&
    lhs.rvec_y == rhs.rvec_y &&
    lhs.rvec_z == rhs.rvec_z &&
    lhs.trans_x == rhs.trans_x &&
    lhs.trans_y == rhs.trans_y &&
    lhs.trans_z == rhs.trans_z;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::darknet_ros_msgs::pose_info_<ContainerAllocator1> & lhs, const ::darknet_ros_msgs::pose_info_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace darknet_ros_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::darknet_ros_msgs::pose_info_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::darknet_ros_msgs::pose_info_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::darknet_ros_msgs::pose_info_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::darknet_ros_msgs::pose_info_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::darknet_ros_msgs::pose_info_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::darknet_ros_msgs::pose_info_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::darknet_ros_msgs::pose_info_<ContainerAllocator> >
{
  static const char* value()
  {
    return "03971dbefaf1ae5a8bc19cc37c05b54e";
  }

  static const char* value(const ::darknet_ros_msgs::pose_info_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x03971dbefaf1ae5aULL;
  static const uint64_t static_value2 = 0x8bc19cc37c05b54eULL;
};

template<class ContainerAllocator>
struct DataType< ::darknet_ros_msgs::pose_info_<ContainerAllocator> >
{
  static const char* value()
  {
    return "darknet_ros_msgs/pose_info";
  }

  static const char* value(const ::darknet_ros_msgs::pose_info_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::darknet_ros_msgs::pose_info_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64 rvec_x\n"
"float64 rvec_y\n"
"float64 rvec_z\n"
"float64 trans_x\n"
"float64 trans_y\n"
"float64 trans_z\n"
;
  }

  static const char* value(const ::darknet_ros_msgs::pose_info_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::darknet_ros_msgs::pose_info_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.rvec_x);
      stream.next(m.rvec_y);
      stream.next(m.rvec_z);
      stream.next(m.trans_x);
      stream.next(m.trans_y);
      stream.next(m.trans_z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct pose_info_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::darknet_ros_msgs::pose_info_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::darknet_ros_msgs::pose_info_<ContainerAllocator>& v)
  {
    s << indent << "rvec_x: ";
    Printer<double>::stream(s, indent + "  ", v.rvec_x);
    s << indent << "rvec_y: ";
    Printer<double>::stream(s, indent + "  ", v.rvec_y);
    s << indent << "rvec_z: ";
    Printer<double>::stream(s, indent + "  ", v.rvec_z);
    s << indent << "trans_x: ";
    Printer<double>::stream(s, indent + "  ", v.trans_x);
    s << indent << "trans_y: ";
    Printer<double>::stream(s, indent + "  ", v.trans_y);
    s << indent << "trans_z: ";
    Printer<double>::stream(s, indent + "  ", v.trans_z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DARKNET_ROS_MSGS_MESSAGE_POSE_INFO_H
