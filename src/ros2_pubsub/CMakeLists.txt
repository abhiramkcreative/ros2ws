cmake_minimum_required(VERSION 3.8)
project(ros2_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# 1. Generate custom messages from the msg directory
rosidl_generate_interfaces(${PROJECT_NAME}_msgs
  "msg/RobotStatus.msg"
)

# 2. Define executables for both nodes
add_executable(publisher src/publisher.cpp)
add_executable(subscriber src/subscriber.cpp)

# 3. Link dependencies and custom message typesupport for publisher
ament_target_dependencies(publisher rclcpp std_msgs)
rosidl_get_typesupport_target(cpp_typesupport_target ${PROJECT_NAME}_msgs "rosidl_typesupport_cpp")
target_link_libraries(publisher "${cpp_typesupport_target}")

# 4. Link dependencies and custom message typesupport for subscriber
ament_target_dependencies(subscriber rclcpp std_msgs)
target_link_libraries(subscriber "${cpp_typesupport_target}")

# 5. Install the executable so colcon can locate and run it
install(TARGETS
  publisher
  subscriber
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()