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
#include <string>
#include <atomic>

#include "std_msgs/msg/string.hpp"


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
    CSensorProxy(std::string name);                           // Constructor
    CSensorProxy(const CSensorProxy&) = delete;               // Copy constructor
    CSensorProxy(CSensorProxy&&) = delete;                    // Move constructor
    CSensorProxy& operator=(const CSensorProxy&) = delete;    // Copy assignment operator
    CSensorProxy& operator=(CSensorProxy&&) = delete;         // Move assignment operator
    ~CSensorProxy();                                          // Destructor

    void read(SSensorProxyData& data);
    std::string getName() { return m_name; }
    void stop() { m_shutdown_request = true; }

private:
    void process();

    std::atomic<bool> m_shutdown_request{false};
    std::thread t_main;
    float m_distance{100.0f};
    std::string m_name;
    int m_ID;
};
