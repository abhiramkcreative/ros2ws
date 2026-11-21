#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "ros2_pubsub/msg/robot_status.hpp"

#include <chrono>

using namespace std::chrono_literals;
using RobotStatus = ros2_pubsub::msg::RobotStatus;

class PublisherNode : public rclcpp::Node {
public:
    PublisherNode() : Node("publisher_node"), battery_level_(100.0f) {
        publisher_ = create_publisher<RobotStatus>("robot_status", 10);
        timer_ = create_wall_timer(1000ms, std::bind(&PublisherNode::timer_callback, this));
    }
private:
    void timer_callback() {

        auto message = RobotStatus();
        message.robot_id = 12;
        message.battery_level = battery_level_;
        if (battery_level_ > 0.0f) {
            message.status_message = "Operating";
            publisher_->publish(message);
            RCLCPP_INFO(get_logger(), "\nPublishing status for Robot %d\n", message.robot_id);
            battery_level_ -= 1.0f;
        } else {
            message.status_message = "Stopped";
            publisher_->publish(message);
            rclcpp::shutdown();
        }
    }
    rclcpp::Publisher<RobotStatus>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    float battery_level_;
};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<PublisherNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}