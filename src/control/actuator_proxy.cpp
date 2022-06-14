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
    m_pub = m_node->create_publisher<std_msgs::msg::String>(m_channelName, 10);
#endif
}

void CActuatorProxy::write(const SActuatorProxyData& data)
{
#if ROS2_IS_ENABLED
    std_msgs::msg::String msg;
    msg.data = data.command;
    m_pub->publish(msg);
#else

#endif
}
