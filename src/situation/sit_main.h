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

#include "sensor_data.h"
#include "sit_data.h"

class CSitMain : public IComponent
{
public:
    CSitMain()=default;                               // Constructor
    CSitMain(const CSitMain&) = delete;               // Copy constructor
    CSitMain(CSitMain&&) = delete;                    // Move constructor
    CSitMain& operator=(const CSitMain&) = delete;    // Copy assignment operator
    CSitMain& operator=(CSitMain&&) = delete;         // Move assignment operator
    ~CSitMain()=default;                              // Destructor

    bool init() override;
    bool start() override;
    bool process() override;
    bool stop() override;
    bool setTheData(void*) override { return true; }
    bool getTheData(void*) override { return true; }

    bool setData(const SAllSensorData& data);
    bool getData(SSITDistancesData& data);

private:
    SSITDistancesData m_currentDistanceData;
    SAllSensorData m_currentSensorData{};

};
