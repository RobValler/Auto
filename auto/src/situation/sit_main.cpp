/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "sit_main.h"

#include <iostream>

bool CSitMain::init()
{

    return true;
}

bool CSitMain::start()
{

    return true;
}

bool CSitMain::process()
{
    std::cout << "SIT process" << std::endl;
    return true;
}

bool CSitMain::stop()
{

    return true;
}
