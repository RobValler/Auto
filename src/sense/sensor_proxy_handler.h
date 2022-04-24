/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "sensor_proxy.h"

#include <memory>
#include <vector>

struct SAllSensorData
{
    std::vector<SSensorProxyData> data;
};

class CSensorProxyHandler
{
public:
    CSensorProxyHandler()=default;                                          // Constructor
    CSensorProxyHandler(const CSensorProxyHandler&) = delete;               // Copy constructor
    CSensorProxyHandler(CSensorProxyHandler&&) = delete;                    // Move constructor
    CSensorProxyHandler& operator=(const CSensorProxyHandler&) = delete;    // Copy assignment operator
    CSensorProxyHandler& operator=(CSensorProxyHandler&&) = delete;         // Move assignment operator
    ~CSensorProxyHandler()=default;                                         // Destructor

    bool addSensor(std::shared_ptr<CSensorProxy> p_sensor) {
        m_sensor_proxy_list.emplace_back(std::move(p_sensor));
        return true;
    }

    bool removeSensor(std::shared_ptr<CSensorProxy> p_sensor) {

        return true;
    }

    void readSensors(SAllSensorData& allSensorData) {
        SSensorProxyData p_sensor;
        for(const auto& it: m_sensor_proxy_list) {            
            it->read(p_sensor);
            allSensorData.data.emplace_back(std::move(p_sensor));
        }
    }

private:
    std::vector<std::shared_ptr<CSensorProxy>> m_sensor_proxy_list;

};
