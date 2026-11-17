// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros2_pubsub:msg/RobotStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_pubsub/msg/robot_status.hpp"


#ifndef ROS2_PUBSUB__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
#define ROS2_PUBSUB__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros2_pubsub/msg/detail/robot_status__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros2_pubsub
{

namespace msg
{

namespace builder
{

class Init_RobotStatus_status_message
{
public:
  explicit Init_RobotStatus_status_message(::ros2_pubsub::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  ::ros2_pubsub::msg::RobotStatus status_message(::ros2_pubsub::msg::RobotStatus::_status_message_type arg)
  {
    msg_.status_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros2_pubsub::msg::RobotStatus msg_;
};

class Init_RobotStatus_battery_level
{
public:
  explicit Init_RobotStatus_battery_level(::ros2_pubsub::msg::RobotStatus & msg)
  : msg_(msg)
  {}
  Init_RobotStatus_status_message battery_level(::ros2_pubsub::msg::RobotStatus::_battery_level_type arg)
  {
    msg_.battery_level = std::move(arg);
    return Init_RobotStatus_status_message(msg_);
  }

private:
  ::ros2_pubsub::msg::RobotStatus msg_;
};

class Init_RobotStatus_robot_id
{
public:
  Init_RobotStatus_robot_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotStatus_battery_level robot_id(::ros2_pubsub::msg::RobotStatus::_robot_id_type arg)
  {
    msg_.robot_id = std::move(arg);
    return Init_RobotStatus_battery_level(msg_);
  }

private:
  ::ros2_pubsub::msg::RobotStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros2_pubsub::msg::RobotStatus>()
{
  return ros2_pubsub::msg::builder::Init_RobotStatus_robot_id();
}

}  // namespace ros2_pubsub

#endif  // ROS2_PUBSUB__MSG__DETAIL__ROBOT_STATUS__BUILDER_HPP_
