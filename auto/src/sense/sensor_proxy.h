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

    int read() { return m_distance; }
    std::string getName() { return m_name; }
    void stop() { m_shutdown_request = true; }

private:
    void process() {
        while(!m_shutdown_request) {
            if(m_distance > 0)
                m_distance = m_distance - 0.1f;

            std::this_thread::sleep_for( std::chrono::seconds(1) );
        }
    }

    std::atomic<bool> m_shutdown_request{false};
    std::thread t_main;
    float m_distance{1000.0f};
    std::string m_name;

};
