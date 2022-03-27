/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "state_main.h"
#include "factory.h"

#include "sense_main.h"

IStateClassBase::StateReturnCode CStateMain::StateRun()
{
    m_factory->getModule("sensor")->process();

    SSenseData data;
    std::static_pointer_cast<CSenseMain>(m_factory->getModule("sensor"))->getData(data);



    m_factory->getModule("sit")->process();
    m_factory->getModule("decide")->process();
    m_factory->getModule("control")->process();

    if(++m_counter < 100)
        return StateCodeRunOK;
    else
        return StateCodeRunExitOK;
}
