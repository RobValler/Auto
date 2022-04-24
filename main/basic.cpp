#include <gtest/gtest.h>

#include "core.h"
#include "sim_main.h"

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

TEST(Tester, Test_Func)
{
    CAutoCore core;

    l_shutdowndown = false;
    struct sigaction sigIntHandler;
    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;
    sigaction(SIGINT, &sigIntHandler, NULL);
    sigaction(SIGTERM, &sigIntHandler, NULL);

    CSimCore::GetInstance();
    CSimCore::start();
    core.start();

    while(!l_shutdowndown)
    {
        CSimCore::process();

        if(!core.process())
            break;
    }

    core.stop();
    CSimCore::stop();
}
