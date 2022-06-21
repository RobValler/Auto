/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "rclcpp/rclcpp.hpp"
#include "rclcpp/node.hpp"
#include "msg_def/msg/actuator_cmd.hpp"

#include <string>

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    std::string name = "main_drive";
    std::string channel = name + "_channel";
    auto node = rclcpp::Node::make_shared(name);

    std::function<void(const msg_def::msg::ActuatorCmd msg)> const readFromQFunc =
            [node](const msg_def::msg::ActuatorCmd msg)
    {
        RCLCPP_INFO(node->get_logger(), "Actuator command = %s/n", msg.command.c_str());
    };

    auto chatter_sub = node->create_subscription<msg_def::msg::ActuatorCmd>(channel, 10,  readFromQFunc);

    rclcpp::Rate loop_rate(10);

    while(rclcpp::ok())
    {
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
