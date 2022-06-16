/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/


#include "control_main.h"

#include "actuator_proxy_handler.h"

bool CControlMain::init()
{
    m_actuator_proxy_handler = std::make_shared<CActuatorProxyHandler>();
    m_actuator_proxy_handler->addActuator(std::make_shared<CActuatorProxy>("main_drive"));
    //m_actuator_proxy_handler->addActuator(std::make_shared<CActuatorProxy>("steering"));

    return true;
}

bool CControlMain::start()
{

    return true;
}

bool CControlMain::process()
{

    return true;
}


bool CControlMain::stop()
{

    return true;
}

bool CControlMain::setCommand(std::string command)
{

    if("Accelerate" == command) {
        m_actuator_proxy_handler->writeToActuator("main_drive", command);
    }
    else if("Brake" == command) {
        m_actuator_proxy_handler->writeToActuator("main_drive", command);
    }
    else if("Left" == command) {
        m_actuator_proxy_handler->writeToActuator("steering", command);
    }
    else if("Right" == command) {
        m_actuator_proxy_handler->writeToActuator("steering", command);
    }
    else
    {
        // default
    }

    return true;
}
