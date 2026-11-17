# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target ros2_pubsub::ros2_pubsub
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${ros2_pubsub_TARGETS}.
if(ros2_pubsub_TARGETS AND NOT TARGET ros2_pubsub::ros2_pubsub)
  add_library(ros2_pubsub::ros2_pubsub INTERFACE IMPORTED)
  set_target_properties(ros2_pubsub::ros2_pubsub PROPERTIES
    INTERFACE_LINK_LIBRARIES "${ros2_pubsub_TARGETS}")
endif()
