cmake_minimum_required(VERSION 3.8)
project(ros2_srvcli)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_srvs REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/RobotTask.srv"
  DEPENDENCIES std_srvs
)

rosidl_get_typesupport_target(cpp_typesupport_target "${PROJECT_NAME}" "rosidl_typesupport_cpp")

add_executable(service_node src/service.cpp)
ament_target_dependencies(service_node rclcpp std_srvs)
target_link_libraries(service_node "${cpp_typesupport_target}")

add_executable(client_node src/client.cpp)
ament_target_dependencies(client_node rclcpp std_srvs)
target_link_libraries(client_node "${cpp_typesupport_target}")

install(TARGETS
  service_node
  client_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_lint_cmake_copyright_FOUND TRUE)
  set(ament_lint_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()