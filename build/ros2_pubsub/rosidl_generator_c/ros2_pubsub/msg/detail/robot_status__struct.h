// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros2_pubsub:msg/RobotStatus.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_pubsub/msg/robot_status.h"


#ifndef ROS2_PUBSUB__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
#define ROS2_PUBSUB__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'status_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/RobotStatus in the package ros2_pubsub.
typedef struct ros2_pubsub__msg__RobotStatus
{
  int32_t robot_id;
  float battery_level;
  rosidl_runtime_c__String status_message;
} ros2_pubsub__msg__RobotStatus;

// Struct for a sequence of ros2_pubsub__msg__RobotStatus.
typedef struct ros2_pubsub__msg__RobotStatus__Sequence
{
  ros2_pubsub__msg__RobotStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros2_pubsub__msg__RobotStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS2_PUBSUB__MSG__DETAIL__ROBOT_STATUS__STRUCT_H_
