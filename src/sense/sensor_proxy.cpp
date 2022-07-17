/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "sensor_proxy.h"

#include "sensor_data.h"

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
    m_proxyName = name;
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
#if ROS2_IS_ENABLED
    data.sensor_ID = m_ID;
    data.sensor_name = m_proxyName;
    data.range_sensor_distance = m_distance;
#else
    data.range_sensor_distance = CSimCore::get_range_sensor_distance();
#endif
}

void CSensorProxy::process()
{
#ifdef ROS2_IS_ENABLED
    auto node = rclcpp::Node::make_shared(m_proxyName);

    std::function<void(const sensor_msgs::msg::PointCloud msg)> const readPointcloud =
            [node, this](const sensor_msgs::msg::PointCloud msg)
    {
        int size = msg.points.size();
        //msg.points.at(7753).x
        CLOG(LOGLEV_RUN, "Sensor range = ",
                            msg.points.at(7753).x, ":",
                            msg.points.at(7753).y, ":",
                            msg.points.at(7753).z, ":");


        m_distance = msg.points.at(7753).x;

    };

    std::function<void(const sensor_msgs::msg::Range msg)> const readRange =
            [node, this](const sensor_msgs::msg::Range msg)
    {
        if(msg.range < msg.max_range) {
            m_distance = msg.range;
        }
        else
        {
            m_distance = 100.0f;
        }
    };

    //auto chatter_sub = node->create_subscription<std_msgs::msg::String>(m_name + "_ros2_channel", 10,  readFromQFunc);
    //auto chatter_sub = node->create_subscription<msg_def::msg::SensorData>(m_channelName, 10,  readFromQFunc);

    m_subPointCloud = node->create_subscription<sensor_msgs::msg::PointCloud>("/ray/pointcloud", 10,  readPointcloud);
    m_subRange = node->create_subscription<sensor_msgs::msg::Range>("/ray/range", 10,  readRange);


    rclcpp::Rate loop_rate(3);

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
