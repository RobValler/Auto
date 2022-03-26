/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "sense_main.h"

#include <iostream>

bool CSenseMain::start()
{
    std::cout << "Sense component started" << std::endl;

    return true;
}

bool CSenseMain::stop()
{

    return true;
}
