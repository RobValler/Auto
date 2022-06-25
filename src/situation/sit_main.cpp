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
    const int x_coord_max = 50;
    const int y_coord_max = 50;
//    const int sizeInCM = 10;

    // assign default values to the grid
    for(int x_coord = 0; x_coord <= x_coord_max; ++x_coord)
    {
        for(int y_coord = 0; y_coord <= y_coord_max; ++y_coord)
        {
            m_occupancyGrid.grid[x_coord][y_coord].state = false;
            // etc.
        }
    }

    // add the central vehicle / our car to the grid as an occupied area
    m_occupancyGrid.grid[25][25].state = true; //centre

    return true;
}

bool CSitMain::process()
{
    bool result = false;

    // populate distances data struct
    for(const auto& it : m_currentSensorData.data)
    {
        if("sonar_front_left" == it.sensor_name)
        {
            m_currentDistanceData.distanceToFront = it.range_sensor_distance;
            result = true;
            break;
        }
    }

    // populate occupancy grid
    // ???

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

bool CSitMain::getData(SOccupancyGrid& data)
{
    data = m_occupancyGrid;
    return true;
}
