/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include <thread>
#include <string>
#include <atomic>

#ifdef ROS2_IS_ENABLED
#include "rclcpp/node.hpp"
#ifdef GAZEBO_IS_ENABLED
#include "sensor_msgs/msg/range.hpp"
#include "sensor_msgs/msg/point_cloud.hpp"
#endif // GAZEBO
#endif // ROS2


struct SSensorProxyData;

class CSensorProxy
{
public:
    CSensorProxy(std::string name);                           // Constructor
    CSensorProxy(const CSensorProxy&) = delete;               // Copy constructor
    CSensorProxy(CSensorProxy&&) = delete;                    // Move constructor
    CSensorProxy& operator=(const CSensorProxy&) = delete;    // Copy assignment operator
    CSensorProxy& operator=(CSensorProxy&&) = delete;         // Move assignment operator
    ~CSensorProxy();                                          // Destructor

    void read(SSensorProxyData& data);
    std::string getName() { return m_proxyName; }
    void stop() { m_shutdown_request = true; }

private:
    void process();

    std::atomic<bool> m_shutdown_request{false};
    std::thread t_main;
    std::atomic<double> m_distance{100.0f};
    std::string m_proxyName;
    std::string m_SensorName;
    std::string m_channelName;
    int m_ID;

#ifdef GAZEBO_IS_ENABLED
    rclcpp::Subscription<sensor_msgs::msg::PointCloud>::SharedPtr m_subPointCloud;      ///<
    rclcpp::Subscription<sensor_msgs::msg::Range>::SharedPtr m_subRange;                ///<
#endif
};
