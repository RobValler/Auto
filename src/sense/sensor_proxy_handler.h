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

struct SAllSensorData;

class CSensorProxyHandler
{
public:
    CSensorProxyHandler()=default;                                          // Constructor
    CSensorProxyHandler(const CSensorProxyHandler&) = delete;               // Copy constructor
    CSensorProxyHandler(CSensorProxyHandler&&) = delete;                    // Move constructor
    CSensorProxyHandler& operator=(const CSensorProxyHandler&) = delete;    // Copy assignment operator
    CSensorProxyHandler& operator=(CSensorProxyHandler&&) = delete;         // Move assignment operator
    ~CSensorProxyHandler()=default;                                         // Destructor

    bool addSensor(std::shared_ptr<CSensorProxy> p_sensor);
    bool removeSensor(std::shared_ptr<CSensorProxy>);
    void readAllSensors(SAllSensorData& allSensorData);

private:
    std::vector<std::shared_ptr<CSensorProxy>> m_sensor_proxy_list;

};
