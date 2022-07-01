/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "actuator_proxy.h"

#ifdef ROS2_IS_ENABLED
#include "rclcpp/rclcpp.hpp"
#else
#include "sim_main.h"
#endif

#include "Logger.h"

#include <functional>
#include <string>

CActuatorProxy::CActuatorProxy(std::string name)
{
    m_name = name;
    m_channelName = name + "_channel";
#ifdef ROS2_IS_ENABLED
    m_node = rclcpp::Node::make_shared(m_name);
#ifdef GAZEBO_IS_ENABLED
    m_pub2 = m_node->create_publisher<geometry_msgs::msg::Twist>("demo/cmd_demo", 10);
#else
    m_pub = m_node->create_publisher<msg_def::msg::ActuatorCmd>(m_channelName, 10);
#endif
#endif
}

void CActuatorProxy::write(const SActuatorProxyData& data)
{
#if ROS2_IS_ENABLED
#ifdef GAZEBO_IS_ENABLED
    geometry_msgs::msg::Twist msg;

    if("Accelerate" == data.command)
        msg.linear.x = 1.0;
    else if("Brakes" == data.command)
        msg.linear.x = -1.0;

    m_pub2->publish(msg);
#else
    msg_def::msg::ActuatorCmd msg;
    msg.command = data.command;
    m_pub->publish(msg);
#endif
#else

#endif
}
