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
#include "decide_main.h"
#include "control_main.h"
#include "sensor_proxy_handler.h"

#include <vector>



IStateClassBase::StateReturnCode CStateMain::StateRun()
{
    ///\ todo separate state classes

    SAllSensorData data;
    bool remain_in_state = false;

    // #### SENSOR ###
    // get data
    //std::static_pointer_cast<CSenseMain>(m_factory->getModule("sensor"))->getData(data);
    m_factory->getModule("sensor")->getTheData(&data);

    // ### INTERPRETATION ###
    /// note The SIT is not used yet.
    //m_factory->getModule("sit")->process();

    // ### DECIDE ###
    // run through all the sensor data
    for(const auto& it: data.data)
    {
        CLOG(LOGLEV_RUN, "Sensor (", it.sensor_name, ") distance is ", it.range_sensor_distance );

        //std::static_pointer_cast<CDecideMain>(m_factory->getModule("decide"))->setData(it.range_sensor_distance);
        m_factory->getModule("decide")->setTheData(it.range_sensor_distance);
        m_factory->getModule("decide")->process();

        //check for zero distance
        if(it.range_sensor_distance > 0)
            remain_in_state = true;
    }

    std::string decide{"null"};
    std::static_pointer_cast<CDecideMain>(m_factory->getModule("decide"))->getData(decide);
    CLOG(LOGLEV_RUN, "Decide = ", decide );


    if(!remain_in_state)
        return StateCodeRunExitOK;

    // ### CONTROL ###
    std::static_pointer_cast<CControlMain>(m_factory->getModule("control"))->setCommand(decide);
//    m_factory->getModule("control")->process();

    return StateCodeRunOK;
}
