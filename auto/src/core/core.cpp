/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "core.h"
#include "factory.h"

bool CAutoCore::start()
{
    m_factory = std::make_shared<CFactory>();

    m_factory->init();
    m_factory->start();

    return true;
}

bool CAutoCore::process()
{
    m_factory->getModule("sensor")->process();
    m_factory->getModule("sit")->process();
    m_factory->getModule("decide")->process();
    m_factory->getModule("control")->process();

    return true;
}

bool CAutoCore::stop()
{
    m_factory->stop();

    return true;
}
