/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "sensor_proxy_handler.h"
#include "sensor_data.h"

bool CSensorProxyHandler::addSensor(std::shared_ptr<CSensorProxy> p_sensor)
{
    m_sensor_proxy_list.emplace_back(std::move(p_sensor));
    return true;
}

bool CSensorProxyHandler::removeSensor(std::shared_ptr<CSensorProxy>)
{

    return true;
}

void CSensorProxyHandler::readAllSensors(SAllSensorData& allSensorData)
{
    SSensorProxyData sensor;
    for(const auto& it: m_sensor_proxy_list) {
        it->read(sensor);
        allSensorData.data.emplace_back(std::move(sensor));
    }
}
