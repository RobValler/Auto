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

struct SSITDistancesData
{
    float distanceToFront;
    float distanceToLeftSide;
    float distanceToRightSide;
    float distanceToRear;
};


struct SOccupancySquare
{
    // this is 10x10 cm
    float x;
    float y;
    float z{0.0f}; // not used yet

    bool state{false}; // occupancy state: true is occupied, false is not
};

struct SOccupancyGrid
{
    SOccupancySquare grid[50][50];
};
