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

bool CControlMain::setTheData(void*)
{

    return true;
}

bool CControlMain::getTheData(void*)
{

    return true;
}


bool CControlMain::setCommand(std::string command)
{

    if("Accelerate" == command) {
        m_actuator_proxy_handler->writeToActuator("main_drive", command);
    }
    if("Brake" == command) {
        m_actuator_proxy_handler->writeToActuator("main_drive", command);
    }


    return true;
}
