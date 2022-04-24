/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "factory.h"

#include "IComponent.h"

#include "sense_main.h"
#include "sit_main.h"
#include "decide_main.h"
#include "control_main.h"

void CFactory::setUp()
{
    addModule("sensor", std::make_shared<CSenseMain>());
    addModule("sit", std::make_shared<CSitMain>());
    addModule("decide", std::make_shared<CDecideMain>());
    addModule("control", std::make_shared<CControlMain>());
}

