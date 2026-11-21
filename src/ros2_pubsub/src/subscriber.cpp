#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "ros2_pubsub/msg/robot_status.hpp"

using std::placeholders::_1;
using RobotStatus = ros2_pubsub::msg::RobotStatus;

class SubscriberNode : public rclcpp::Node {
public:
    SubscriberNode() : Node("subscriber_node") {
        subscriber_ = create_subscription<RobotStatus>("robot_status", 10, std::bind(&SubscriberNode::topic_callback, this,_1));
    }
private:
    void topic_callback(const RobotStatus & message) const {
        if (message.battery_level <= 0.0f) {
            RCLCPP_WARN(get_logger(), "\nRobot %d is at %.1f%% battery. Status: %s\n", message.robot_id, message.battery_level, message.status_message.c_str());
            RCLCPP_ERROR(get_logger(), "\nRobot battery is fully drained and shut down.\n");
            rclcpp::shutdown();
        } else {
            RCLCPP_INFO(get_logger(), "\nRobot %d is at %.1f%% battery. Status: %s\n", message.robot_id, message.battery_level, message.status_message.c_str());
        }
        }
    rclcpp::Subscription<RobotStatus>::SharedPtr subscriber_;
};

int main(int argc, char ** argv) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SubscriberNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}