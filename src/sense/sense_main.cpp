/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "sense_main.h"
#include "sensor_proxy_handler.h"

#include <memory>

#include "Logger.h"


bool CSenseMain::init()
{
    m_sensor_proxy_handler = std::make_shared<CSensorProxyHandler>();
    m_sensor_proxy_handler->addSensor(std::make_shared<CSensorProxy>("sonar_front_left"));
    m_sensor_proxy_handler->addSensor(std::make_shared<CSensorProxy>("sonar_front_right"));

    return true;
}

bool CSenseMain::start()
{
    CLOG(LOGLEV_RUN, "Sense component started");
    return true;
}

bool CSenseMain::process()
{
    // not needed so far

    return true;
}

bool CSenseMain::stop()
{
    return true;
}

bool CSenseMain::getData(SAllSensorData& data)
{
    m_sensor_proxy_handler->readAllSensors(data);
    return true;
}

