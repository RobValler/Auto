/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "core.h"

int main(int argc, char *argv[])
{
    CAutoCore core;

    core.start();

    while(true)
    {
        core.process();
    }

    core.stop();

    return 1;
}
