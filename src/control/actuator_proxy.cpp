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
    m_pub = m_node->create_publisher<msg_def::msg::ActuatorCmd>(m_channelName, 10);
#endif
}

void CActuatorProxy::write(const SActuatorProxyData& data)
{
#if ROS2_IS_ENABLED
    msg_def::msg::ActuatorCmd msg;
    msg.command = data.command;
    m_pub->publish(msg);
#else

#endif
}
