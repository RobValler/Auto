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

#include <iostream>

bool CSenseMain::init()
{
    m_sensor_proxy_handler = std::make_shared<CSensorProxyHandler>();

    m_sensor_proxy_handler->addSensor(std::make_shared<CSensorProxy>("Sonar front left"));
    m_sensor_proxy_handler->addSensor(std::make_shared<CSensorProxy>("Sonar front right"));

    return true;
}

bool CSenseMain::start()
{
    std::cout << "Sense component started" << std::endl;

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
    m_sensor_proxy_handler->readSensors(data);
    return true;
}
