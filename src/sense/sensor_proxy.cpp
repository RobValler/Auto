/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "sensor_proxy.h"

#ifdef ROS2_IS_ENABLED
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/node.hpp"
#include "std_msgs/msg/string.hpp"
#endif

#include <chrono>
#include <functional>

CSensorProxy::CSensorProxy(std::string name)                            // Constructor
    : m_name(name)
{
    t_main = std::thread(&CSensorProxy::process, this);
}

CSensorProxy::~CSensorProxy()                                           // Destructor
{
    m_shutdown_request = true;
    t_main.join();
}

void CSensorProxy::read(SSensorProxyData& data)
{
    data.sensor_ID = m_ID;
    data.sensor_name = m_name;
#if ACTUAL_DATA

#else
    data.range_sensor_distance = CSimCore::get_range_sensor_distance();
#endif
}

void CSensorProxy::process()
{
#ifdef ROS2_IS_ENABLED

    auto node = rclcpp::Node::make_shared("sensor_proxy_1");

    std::function<void(const std_msgs::msg::String::SharedPtr msg)> const readFromQFunc =
            [node](const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(node->get_logger(), "%s\n", msg->data.c_str());
    };

    auto chatter_sub = node->create_subscription<std_msgs::msg::String>("sensor_data", 1000, readFromQFunc);

    rclcpp::Rate loop_rate(10);

    while (rclcpp::ok())
    {
        rclcpp::spin_some(node);
        loop_rate.sleep();
    }

#else
    while(!m_shutdown_request)
    {
        std::this_thread::sleep_for( std::chrono::microseconds(1000) );
    }
#endif


}
