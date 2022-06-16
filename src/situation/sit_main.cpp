/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "sit_main.h"

#include "Logger.h"

bool CSitMain::init()
{
    return true;
}

bool CSitMain::start()
{

    return true;
}

bool CSitMain::process()
{
    bool result = false;
    for(const auto& it : m_currentSensorData.data)
    {
        if("sonar_front_left" == it.sensor_name)
        {
            m_currentDistanceData.distanceToFront = it.range_sensor_distance;
            result = true;
            break;
        }
    }
    return result;
}

bool CSitMain::stop()
{

    return true;
}

bool CSitMain::setData(const SAllSensorData& data)
{
    m_currentSensorData = data;
    return true;
}

bool CSitMain::getData(SSITDistancesData& data)
{
    data = m_currentDistanceData;
    return true;
}
