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

#include "Logger.h"

#include "sense_main.h"

IStateClassBase::StateReturnCode CStateMain::StateRun()
{
    SSenseData data;
    bool remain_in_state = false;

    ///\todo update
    m_factory->getModule("sensor")->process();    
    std::static_pointer_cast<CSenseMain>(m_factory->getModule("sensor"))->getData(data);
    CLOG(LOGLEV_RUN, "Sensor (", data.data.at(0).sensor_name, ") distance is ", data.data.at(0).distance );

    //check for zero distance
    for(const auto& it : data.data) {
        if(it.distance > 0)
            remain_in_state = true;
    }

    if(!remain_in_state)
        return StateCodeRunExitOK;

    m_factory->getModule("sit")->process();
    m_factory->getModule("decide")->process();
    m_factory->getModule("control")->process();

    return StateCodeRunOK;
}
