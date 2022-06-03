
#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"
#include "rclcpp/node.hpp"

#include <sstream>

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("sensor_1");
    auto chatter_pub = node->create_publisher<std_msgs::msg::String>("sensor_data", 1000);
    rclcpp::Rate loop_rate(10);

    int count = 0;

    while (rclcpp::ok())
    {
        std_msgs::msg::String msg;
        std::stringstream ss;
        ss << "hello world " << count;
        msg.data = ss.str();
        RCLCPP_INFO(node->get_logger(), "%s\n", msg.data.c_str());
        chatter_pub->publish(msg);

        rclcpp::spin_some(node);
        loop_rate.sleep();
        ++count;
    }
    return 0;
}
