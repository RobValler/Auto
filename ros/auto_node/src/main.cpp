/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/


#include "rclcpp/rclcpp.hpp"

#include "core.h"
#include "Logger.h"

#include <chrono>
#include <signal.h>
#include <atomic>

namespace  {
    static std::atomic<bool> l_shutdowndown;
}

void my_handler(int)
{
    CLOG(LOGLEV_RUN, "POSIX Interrupt detected, stopping!");
    l_shutdowndown = true;
}

int main(int argc, char **argv)
{
    l_shutdowndown = false;
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
    sigaction(SIGTERM, &sigIntHandler, NULL);

    CAutoCore core;

    rclcpp::init(argc, argv);
    core.start();

    while(true)
    {
        if(!core.process() || true == l_shutdowndown)
            break;

        std::this_thread::sleep_for( std::chrono::milliseconds(50) );

    }

    rclcpp::shutdown();
    core.stop();
    return 0;
}
