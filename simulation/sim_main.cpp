/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "sim_main.h"

namespace  {
    float l_distance = 200.0f;
}


bool CSimCore::start(){

    return true;
}

bool CSimCore::process(){

    l_distance -= 0.1f;

    return true;
}

bool CSimCore::stop(){
    return true;
}

float CSimCore::get_range_sensor_distance()
{
    return l_distance;
}

