/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "IComponent.h"

#include "sit_data.h"

#include <string>

class CDecideMain : public IComponent
{
public:
    CDecideMain()=default;                                // Constructor
    CDecideMain(const CDecideMain&) = delete;               // Copy constructor
    CDecideMain(CDecideMain&&) = delete;                    // Move constructor
    CDecideMain& operator=(const CDecideMain&) = delete;    // Copy assignment operator
    CDecideMain& operator=(CDecideMain&&) = delete;        // Move assignment operator
    ~CDecideMain()=default;                               // Destructor

    bool init() override;
    bool start() override;
    bool process() override;
    bool stop() override;
    bool setTheData(void*) override { return true; }
    bool getTheData(void*) override { return true; }

    bool setData(const SSITDistancesData& data);
    bool setData(const SOccupancyGrid& data);
    bool getData(std::string& data);

private:
    SSITDistancesData m_distanceData;               ///<
    SOccupancyGrid m_occupancyGrid;                 ///<
    std::string m_current_decision;                 ///<
};
