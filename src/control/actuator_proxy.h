/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include <string>
#include <atomic>

#ifdef ROS2_IS_ENABLED
#include "rclcpp/node.hpp"
#ifdef GAZEBO_IS_ENABLED
#include "geometry_msgs/msg/twist.hpp"
#else
#include "msg_def/msg/actuator_cmd.hpp"
#endif // GAZEBO
#endif // ROS2

struct SActuatorProxyData
{
    int sensor_ID;
    std::string sensor_name;
    // type?
    std::string command;
};

class CActuatorProxy
{
public:
    CActuatorProxy(std::string name);                               // Constructor
    CActuatorProxy(const CActuatorProxy&) = delete;                 // Copy constructor
    CActuatorProxy(CActuatorProxy&&) = delete;                      // Move constructor
    CActuatorProxy& operator=(const CActuatorProxy&) = delete;      // Copy assignment operator
    CActuatorProxy& operator=(CActuatorProxy&&) = delete;           // Move assignment operator
    ~CActuatorProxy() =default;                                     // Destructor

    void write(const SActuatorProxyData& data);
    std::string getName() { return m_name; }
    void stop() { return; }

private:
    std::string m_name;                                                 ///<
    std::string m_channelName;                                          ///<
    int m_ID;                                                           ///<
    rclcpp::Node::SharedPtr m_node;                                     ///<

#ifdef GAZEBO_IS_ENABLED
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr m_pub2;      ///<
#else
    rclcpp::Publisher<msg_def::msg::ActuatorCmd>::SharedPtr m_pub;      ///<
#endif

};
