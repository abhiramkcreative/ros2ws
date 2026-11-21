#include "rclcpp/rclcpp.hpp"
#include "ros2_srvcli/srv/robot_task.hpp"

#include <memory>
#include <string>

using RobotTask = ros2_srvcli::srv::RobotTask;
using std::placeholders::_1;
using std::placeholders::_2;

class ServiceNode : public rclcpp::Node {
public:
    ServiceNode() : Node("service_node") {
        service_ = create_service<RobotTask>("allocate_robot_task", std::bind(&ServiceNode::handle_task , this, _1, _2));
    }
private:
    void handle_task(const std::shared_ptr<RobotTask::Request> request, std::shared_ptr<RobotTask::Response> response) {
        RCLCPP_INFO(get_logger(), "\n\nIncoming request\n\ntask_id: %d\n\ntask_name: %s" , request->task_id, request->task_name.c_str());
        if (request->task_id % 2 == 0 ) {
            response->success = true;
            response->task_response = "Task " + request->task_name + "\n\nallocated successfully.";
        } else {
            response->success = false;
            response->task_response = "Task " + request->task_name + "\n\nallocation failed.";
        }
    }
    rclcpp::Service<RobotTask>::SharedPtr service_;
};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ServiceNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}