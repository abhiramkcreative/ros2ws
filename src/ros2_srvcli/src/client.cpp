#include "rclcpp/rclcpp.hpp"
#include "ros2_srvcli/srv/robot_task.hpp"

#include <chrono>
#include <memory>
#include <string>

using RobotTask = ros2_srvcli::srv::RobotTask;
using std::placeholders::_1;
using namespace std::chrono_literals;

class ClientNode : public rclcpp::Node {
public:
    ClientNode() : Node("client_node"){
        client_ = create_client<RobotTask>("allocate_robot_task");
        timer_ = create_wall_timer(1s, std::bind(&ClientNode::send_request, this));
    }
private:
    void send_request() {
        if (!client_->wait_for_service(1s)) {
            if (!rclcpp::ok()) {
                RCLCPP_ERROR(get_logger(), "\n\nInterrupted while waiting for the service. Exiting.\n\n");
                rclcpp::shutdown();
            } else {
                RCLCPP_INFO(get_logger(), "\n\nService not available, waiting again...\n\n");
            }
            return;
        }

        timer_->cancel(); 
        auto request = std::make_shared<RobotTask::Request>();
        request->task_id = 42;
        request->task_name = "Move_To_A";
        client_->async_send_request(request, std::bind(&ClientNode::handle_response, this, _1));
    }

    void handle_response(rclcpp::Client<RobotTask>::SharedFuture future) {
        auto response = future.get();
        std::string status_str = response->success ? "True" : "False";
        RCLCPP_INFO(get_logger(), "\n\nTask allocation status: %s. \n\nResponse: %s", status_str.c_str(), response->task_response.c_str());
        rclcpp::shutdown();
    }

    rclcpp::Client<RobotTask>::SharedPtr client_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ClientNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}