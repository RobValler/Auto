/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "factory.h"

#include "sense_main.h"
#include "sit_main.h"
#include "decide_main.h"
#include "control_main.h"


bool CFactory::init()
{
    m_sense = std::make_shared<CSenseMain>();
    m_sit = std::make_shared<CSitMain>();
    m_decide = std::make_shared<CDecideMain>();
    m_control = std::make_shared<CControlMain>();

    m_sense->init();
    m_sit->init();
    m_decide->init();
    m_control->init();


    return true;
}

bool CFactory::start()
{
    ///\ todo automate
    m_sense->start();
    m_sit->start();
    m_decide->start();
    m_control->start();

    return true;
}

bool CFactory::process()
{
    m_sense->process();
    m_sit->process();
    m_decide->process();
    m_control->process();

    return true;
}

bool CFactory::stop()
{
    ///\ todo automate
    m_sense->stop();
    m_sit->stop();
    m_decide->stop();
    m_control->stop();

    return true;
}
