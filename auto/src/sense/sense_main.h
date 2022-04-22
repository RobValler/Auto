/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "icomponent.h"
#include <memory>
#include <vector>

class CSensorProxyHandler;
struct SAllSensorData;

class CSenseMain : public IComponent
{
public:
    CSenseMain()=default;                                 // Constructor
    CSenseMain(const CSenseMain&) = delete;               // Copy constructor
    CSenseMain(CSenseMain&&) = delete;                    // Move constructor
    CSenseMain& operator=(const CSenseMain&) = delete;    // Copy assignment operator
    CSenseMain& operator=(CSenseMain&&) = delete;         // Move assignment operator
    ~CSenseMain()=default;                                // Destructor

    bool init() override;
    bool start() override;
    bool process() override;
    bool stop() override;

    bool getData(SAllSensorData& data);

private:
    std::shared_ptr<CSensorProxyHandler> m_sensor_proxy_handler;
    int data_distance{1000};

};
