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

    std::string name_left = "Sonar_front_left";
    std::string channel_left = name_left + "_channel";
    std::string name_right = "Sonar_front_right";
    std::string channel_right = name_right + "_channel";


    auto node_left = rclcpp::Node::make_shared(name_left);
    auto chatter_pub_left = node_left->create_publisher<std_msgs::msg::String>(channel_left, 10);
    auto node_right = rclcpp::Node::make_shared(name_right);
    auto chatter_pub_right = node_right->create_publisher<std_msgs::msg::String>(channel_right, 10);


    rclcpp::Rate loop_rate(10);

    int count = 100;
    std_msgs::msg::String msg;

    while (rclcpp::ok())
    {
        msg.data = std::to_string(count);
        count --;

        chatter_pub_left->publish(msg);
        chatter_pub_right->publish(msg);

        rclcpp::spin_some(node_left);
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
