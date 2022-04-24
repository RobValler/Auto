/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include <thread>
#include <iostream>
#include <string>
#include <atomic>
#include <chrono>

#include "sim_main.h"

struct SSensorProxyData
{
    int sensor_ID;
    std::string sensor_name;
    // type?
    float range_sensor_distance; // type of data?
};

class CSensorProxy
{
public:
    CSensorProxy(std::string name)                            // Constructor
        : m_name(name)
    {
        t_main = std::thread(&CSensorProxy::process, this);
    }
    CSensorProxy(const CSensorProxy&) = delete;               // Copy constructor
    CSensorProxy(CSensorProxy&&) = delete;                    // Move constructor
    CSensorProxy& operator=(const CSensorProxy&) = delete;    // Copy assignment operator
    CSensorProxy& operator=(CSensorProxy&&) = delete;         // Move assignment operator
    ~CSensorProxy()                                           // Destructor
    {
        m_shutdown_request = true;
        t_main.join();
    }

    void read(SSensorProxyData& data)
    {
        data.sensor_ID = m_ID;
        data.sensor_name = m_name;
        data.range_sensor_distance = CSimCore::get_range_sensor_distance();
    }

    std::string getName() { return m_name; }
    void stop() { m_shutdown_request = true; }

private:
    void process() {
        while(!m_shutdown_request) {

            std::this_thread::sleep_for( std::chrono::microseconds(1000) );
        }
    }

    std::atomic<bool> m_shutdown_request{false};
    std::thread t_main;
    float m_distance{100.0f};
    std::string m_name;
    int m_ID;
};
