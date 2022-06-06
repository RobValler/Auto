/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "rclcpp/rclcpp.hpp"

#include "std_msgs/msg/string.hpp"
#include "rclcpp/node.hpp"

#include <string>

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    std::string name = "Sonar_front_left";
    auto node = rclcpp::Node::make_shared(name + "_ros2_pub_node");
    auto chatter_pub = node->create_publisher<std_msgs::msg::String>("_ros2_channel", 10);
    //auto chatter_pub = node->create_publisher<std_msgs::msg::String>(name + "_ros2_channel", 10);

    rclcpp::Rate loop_rate(10);

    int count = 200;
    std_msgs::msg::String msg;

    while (rclcpp::ok())
    {
        msg.data = std::to_string(count--);

        chatter_pub->publish(msg);

        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
