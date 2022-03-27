/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "core.h"

#include <signal.h>
#include <atomic>

#include "Logger.h"

namespace  {
    static std::atomic<bool> l_shutdowndown;
}

void my_handler(int)
{
    CLOG(LOGLEV_RUN, "Shutdown request received");
    l_shutdowndown = true;
}

int main(int argc, char *argv[])
{
    CAutoCore core;

    l_shutdowndown = false;
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
    sigaction(SIGTERM, &sigIntHandler, NULL);

    core.start();

    while(!l_shutdowndown)
    {
        if(!core.process())
            break;
    }

    core.stop();

    return 1;
}
