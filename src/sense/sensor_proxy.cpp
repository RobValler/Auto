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
#else
#include "sim_main.h"
#endif

#include "Logger.h"

#include <functional>
#include <string>

CSensorProxy::CSensorProxy(std::string name)
{
    m_proxyName = name + "_proxy";
    m_channelName = name + "_channel";
    t_main = std::thread(&CSensorProxy::process, this);
}

CSensorProxy::~CSensorProxy()
{
    m_shutdown_request = true;
    t_main.join();
}

void CSensorProxy::read(SSensorProxyData& data)
{
    data.sensor_ID = m_ID;
    data.sensor_name = m_proxyName;
#if ROS2_IS_ENABLED
    data.range_sensor_distance = m_distance;
#else
    data.range_sensor_distance = CSimCore::get_range_sensor_distance();
#endif
}

void CSensorProxy::process()
{
#ifdef ROS2_IS_ENABLED
    auto node = rclcpp::Node::make_shared(m_proxyName);

    std::function<void(const std_msgs::msg::String::SharedPtr msg)> const readFromQFunc =
            [node, this](const std_msgs::msg::String::SharedPtr msg)
    {
         m_distance = std::stof(msg->data);
    };

    //auto chatter_sub = node->create_subscription<std_msgs::msg::String>(m_name + "_ros2_channel", 10,  readFromQFunc);
    auto chatter_sub = node->create_subscription<std_msgs::msg::String>(m_channelName, 10,  readFromQFunc);

    rclcpp::Rate loop_rate(10);

    while(!m_shutdown_request)
    {
        if(rclcpp::ok()) {
            rclcpp::spin_some(node);
            loop_rate.sleep();
        }
    }

#else
    while(!m_shutdown_request)
    {
        std::this_thread::sleep_for( std::chrono::microseconds(1000) );
    }
#endif

    CLOG(LOGLEV_RUN, "Sensor proxy/node exited");
}
