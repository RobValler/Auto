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
#include "sensor_proxy_handler.h"


IStateClassBase::StateReturnCode CStateMain::StateRun()
{
    ///\ todo separate state classes

    SAllSensorData data;
    bool remain_in_state = false;

    // #### SENSOR ###
    // get data
    std::static_pointer_cast<CSenseMain>(m_factory->getModule("sensor"))->getData(data);

    // ### INTERPRETATION ###
    m_factory->getModule("sit")->process();

    // ### DECIDE ###
    m_factory->getModule("decide")->process();
    for(const auto& it: data.data)
    {
        CLOG(LOGLEV_RUN, "Sensor (", it.sensor_name, ") distance is ", it.range_sensor_distance );

        //check for zero distance
        if(it.range_sensor_distance > 0)
            remain_in_state = true;
    }

    if(!remain_in_state)
        return StateCodeRunExitOK;

    // ### CONTROL ###
    m_factory->getModule("control")->process();

    return StateCodeRunOK;
}
