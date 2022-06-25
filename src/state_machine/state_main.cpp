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
#include "sit_main.h"
#include "decide_main.h"
#include "control_main.h"
#include "sensor_proxy_handler.h"

#include "sensor_data.h"
#include "sit_data.h"

#include <vector>

IStateClassBase::StateReturnCode CStateMain::StateRun()
{
    SAllSensorData allSensorData;
    SSITDistancesData distanceData;
    SOccupancyGrid occupancyGrid;
    std::string Decide;

    // #### SENSOR CLUSTER (HANDLER) ###
   // std::static_pointer_cast<CSenseMain>(m_factory->getModule("sensor"))->getData(allSensorData);
    GET_MODULE(CSenseMain, "sensor")->getData(allSensorData);

    // ### SITUATIONAL INTERPRETATION ###
    std::static_pointer_cast<CSitMain>(m_factory->getModule("sit"))->setData(allSensorData);
    m_factory->getModule("sit")->process();
    std::static_pointer_cast<CSitMain>(m_factory->getModule("sit"))->getData(distanceData);
    GET_MODULE(CSitMain, "sit")->getData(occupancyGrid);

    CLOG(LOGLEV_RUN, "Distance to front = ", distanceData.distanceToFront );
    // exit when the distance to the front object is less than minimum distance
    if(distanceData.distanceToFront <= 1.0f)
        return StateCodeRunExitOK;

    // ### DECIDE ###
    std::static_pointer_cast<CDecideMain>(m_factory->getModule("decide"))->setData(distanceData);
    GET_MODULE(CDecideMain, "decide")->setData(occupancyGrid);
    m_factory->getModule("decide")->process();
    std::static_pointer_cast<CDecideMain>(m_factory->getModule("decide"))->getData(Decide);
    CLOG(LOGLEV_RUN, "Decide = ", Decide );

    // ### CONTROL ###
    std::static_pointer_cast<CControlMain>(m_factory->getModule("control"))->setCommand(Decide);

    return StateCodeRunOK;
}
