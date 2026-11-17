// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from ros2_pubsub:msg/RobotStatus.idl
// generated code does not contain a copyright notice

#include "ros2_pubsub/msg/detail/robot_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_ros2_pubsub
const rosidl_type_hash_t *
ros2_pubsub__msg__RobotStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x39, 0x4f, 0x88, 0x59, 0x92, 0x88, 0x43, 0xfc,
      0x61, 0x90, 0x9d, 0x7d, 0xc9, 0x33, 0x4a, 0x86,
      0xd4, 0xbd, 0x96, 0x25, 0xde, 0x1f, 0x78, 0x75,
      0x31, 0x07, 0x82, 0x98, 0x07, 0x5a, 0x4e, 0xe6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char ros2_pubsub__msg__RobotStatus__TYPE_NAME[] = "ros2_pubsub/msg/RobotStatus";

// Define type names, field names, and default values
static char ros2_pubsub__msg__RobotStatus__FIELD_NAME__robot_id[] = "robot_id";
static char ros2_pubsub__msg__RobotStatus__FIELD_NAME__battery_level[] = "battery_level";
static char ros2_pubsub__msg__RobotStatus__FIELD_NAME__status_message[] = "status_message";

static rosidl_runtime_c__type_description__Field ros2_pubsub__msg__RobotStatus__FIELDS[] = {
  {
    {ros2_pubsub__msg__RobotStatus__FIELD_NAME__robot_id, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_pubsub__msg__RobotStatus__FIELD_NAME__battery_level, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {ros2_pubsub__msg__RobotStatus__FIELD_NAME__status_message, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
ros2_pubsub__msg__RobotStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {ros2_pubsub__msg__RobotStatus__TYPE_NAME, 27, 27},
      {ros2_pubsub__msg__RobotStatus__FIELDS, 3, 3},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int32 robot_id\n"
  "float32 battery_level\n"
  "string status_message";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
ros2_pubsub__msg__RobotStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {ros2_pubsub__msg__RobotStatus__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 58, 58},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
ros2_pubsub__msg__RobotStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *ros2_pubsub__msg__RobotStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
