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
#include "msg_def/msg/sensor_data.hpp"

#include <string>
#include <signal.h>
#include <atomic>

namespace  {
    static std::atomic<bool> l_shutdowndown;
}

void my_handler(int)
{
    l_shutdowndown = true;
}

int main(int argc, char **argv)
{
    l_shutdowndown = false;
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
    sigaction(SIGTERM, &sigIntHandler, NULL);

    rclcpp::init(argc, argv);

    std::string name_left = "sonar_front_left";
    std::string channel_left = name_left + "_channel";
    std::string name_right = "sonar_front_right";
    std::string channel_right = name_right + "_channel";

    auto node_left = rclcpp::Node::make_shared(name_left);
    auto chatter_pub_left = node_left->create_publisher<msg_def::msg::SensorData>(channel_left, 10);
    auto node_right = rclcpp::Node::make_shared(name_right);
    auto chatter_pub_right = node_right->create_publisher<msg_def::msg::SensorData>(channel_right, 10);


    rclcpp::Rate loop_rate(10);

    int count = 100;
    msg_def::msg::SensorData payload;

    while (rclcpp::ok())
    {
        if(count < 10)
            count = 100;

        payload.distance = count--;

        payload.proxy_name = name_left;
        chatter_pub_left->publish(payload);
        RCLCPP_INFO(node_left->get_logger(), "Sensor distance = %d/n", payload.distance);

        payload.proxy_name = name_right;
        chatter_pub_right->publish(payload);

        rclcpp::spin_some(node_left);
        loop_rate.sleep();
        
        if(l_shutdowndown)
	    break;
    }

    rclcpp::shutdown();
    return 0;
}
