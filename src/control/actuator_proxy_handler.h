/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "actuator_proxy.h"

#include "Logger.h"

#include <memory>
#include <vector>

class CActuatorProxyHandler
{
public:
    CActuatorProxyHandler()=default;                                          // Constructor
    CActuatorProxyHandler(const CActuatorProxyHandler&) = delete;               // Copy constructor
    CActuatorProxyHandler(CActuatorProxyHandler&&) = delete;                    // Move constructor
    CActuatorProxyHandler& operator=(const CActuatorProxyHandler&) = delete;    // Copy assignment operator
    CActuatorProxyHandler& operator=(CActuatorProxyHandler&&) = delete;         // Move assignment operator
    ~CActuatorProxyHandler()=default;                                           // Destructor

    bool addActuator(std::shared_ptr<CActuatorProxy> p_sensor) {
        m_actuator_proxy_list.emplace_back(std::move(p_sensor));
        return true;
    }

    bool removeActuator(std::shared_ptr<CActuatorProxy>) {

        return true;
    }

    bool writeToActuator(std::string name, std::string command)
    {
        for(const auto& it: m_actuator_proxy_list) {
            if(it->getName() == name)
            {
                SActuatorProxyData data;
                data.sensor_ID = 123;
                data.sensor_name = name;
                data.command = command;
                it->write(data);
                return true;
            }
        }
        return false;
    }

private:
    std::vector<std::shared_ptr<CActuatorProxy>> m_actuator_proxy_list;

};
