// Generated by gencpp from file trace/trace.msg
// DO NOT EDIT!


#ifndef TRACE_MESSAGE_TRACE_H
#define TRACE_MESSAGE_TRACE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace trace
{
template <class ContainerAllocator>
struct trace_
{
  typedef trace_<ContainerAllocator> Type;

  trace_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , yaw(0.0)
    , light(0)
    , time(0)  {
    }
  trace_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , yaw(0.0)
    , light(0)
    , time(0)  {
  (void)_alloc;
    }



   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _z_type;
  _z_type z;

   typedef float _yaw_type;
  _yaw_type yaw;

   typedef int32_t _light_type;
  _light_type light;

   typedef int32_t _time_type;
  _time_type time;





  typedef boost::shared_ptr< ::trace::trace_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::trace::trace_<ContainerAllocator> const> ConstPtr;

}; // struct trace_

typedef ::trace::trace_<std::allocator<void> > trace;

typedef boost::shared_ptr< ::trace::trace > tracePtr;
typedef boost::shared_ptr< ::trace::trace const> traceConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::trace::trace_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::trace::trace_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::trace::trace_<ContainerAllocator1> & lhs, const ::trace::trace_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z &&
    lhs.yaw == rhs.yaw &&
    lhs.light == rhs.light &&
    lhs.time == rhs.time;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::trace::trace_<ContainerAllocator1> & lhs, const ::trace::trace_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace trace

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::trace::trace_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::trace::trace_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::trace::trace_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::trace::trace_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::trace::trace_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::trace::trace_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::trace::trace_<ContainerAllocator> >
{
  static const char* value()
  {
    return "894975773312c038b24d0c50e1340948";
  }

  static const char* value(const ::trace::trace_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x894975773312c038ULL;
  static const uint64_t static_value2 = 0xb24d0c50e1340948ULL;
};

template<class ContainerAllocator>
struct DataType< ::trace::trace_<ContainerAllocator> >
{
  static const char* value()
  {
    return "trace/trace";
  }

  static const char* value(const ::trace::trace_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::trace::trace_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 x\n"
"float32 y\n"
"float32 z\n"
"float32 yaw\n"
"int32 light\n"
"int32 time\n"
;
  }

  static const char* value(const ::trace::trace_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::trace::trace_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.yaw);
      stream.next(m.light);
      stream.next(m.time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct trace_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::trace::trace_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::trace::trace_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<float>::stream(s, indent + "  ", v.z);
    s << indent << "yaw: ";
    Printer<float>::stream(s, indent + "  ", v.yaw);
    s << indent << "light: ";
    Printer<int32_t>::stream(s, indent + "  ", v.light);
    s << indent << "time: ";
    Printer<int32_t>::stream(s, indent + "  ", v.time);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TRACE_MESSAGE_TRACE_H
