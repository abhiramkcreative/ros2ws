// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_pubsub:msg/RobotStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_pubsub/msg/robot_status.hpp"


#ifndef ROS2_PUBSUB__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
#define ROS2_PUBSUB__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_pubsub/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_pubsub
{

namespace msg
{

inline void to_flow_style_yaml(
  const RobotStatus & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_id
  {
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << ", ";
  }

  // member: battery_level
  {
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
    out << ", ";
  }

  // member: status_message
  {
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "robot_id: ";
    rosidl_generator_traits::value_to_yaml(msg.robot_id, out);
    out << "\n";
  }

  // member: battery_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "battery_level: ";
    rosidl_generator_traits::value_to_yaml(msg.battery_level, out);
    out << "\n";
  }

  // member: status_message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status_message: ";
    rosidl_generator_traits::value_to_yaml(msg.status_message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const RobotStatus & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ros2_pubsub

namespace rosidl_generator_traits
{

[[deprecated("use ros2_pubsub::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_pubsub::msg::RobotStatus & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_pubsub::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_pubsub::msg::to_yaml() instead")]]
inline std::string to_yaml(const ros2_pubsub::msg::RobotStatus & msg)
{
  return ros2_pubsub::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_pubsub::msg::RobotStatus>()
{
  return "ros2_pubsub::msg::RobotStatus";
}

template<>
inline const char * name<ros2_pubsub::msg::RobotStatus>()
{
  return "ros2_pubsub/msg/RobotStatus";
}

template<>
struct has_fixed_size<ros2_pubsub::msg::RobotStatus>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_pubsub::msg::RobotStatus>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_pubsub::msg::RobotStatus>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_PUBSUB__MSG__DETAIL__ROBOT_STATUS__TRAITS_HPP_
