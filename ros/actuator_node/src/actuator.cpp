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

    std::string name = "main_drive";
    std::string channel = name + "_channel";
    auto node = rclcpp::Node::make_shared(name);

    std::function<void(const std_msgs::msg::String::SharedPtr msg)> const readFromQFunc =
            [node](const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(node->get_logger(), "Actuator command = %s/n", msg->data.c_str());
    };

    auto chatter_sub = node->create_subscription<std_msgs::msg::String>(channel, 10,  readFromQFunc);

    rclcpp::Rate loop_rate(10);

    while(rclcpp::ok())
    {
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
