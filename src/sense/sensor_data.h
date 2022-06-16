/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include <vector>
#include <string>

struct SSensorProxyData
{
    int sensor_ID;
    std::string sensor_name;
    // type?
    float range_sensor_distance; // type of data?
};

struct SAllSensorData
{
    std::vector<SSensorProxyData> data;
};
