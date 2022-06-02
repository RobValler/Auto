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
#include "sim_main.h"
#include "Logger.h"

int main(int argc, char *argv[])
{
        CAutoCore core;

  rclcpp::init(argc, argv);

   CSimCore::GetInstance();
    CSimCore::start();
    core.start();

    while(true)
    {
        CSimCore::process();

        if(!core.process())
            break;
    }

    core.stop();
    CSimCore::stop();

  rclcpp::shutdown();
  return 0;
}
