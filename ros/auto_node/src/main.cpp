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


int main(int argc, char *argv[])
{
    CAutoCore core;

    rclcpp::init(argc, argv);
    core.start();

    while(true)
    {
        if(!core.process())
            break;

        std::this_thread::sleep_for( std::chrono::milliseconds(50) );
    }

    rclcpp::shutdown();
    core.stop();
    return 0;
}
