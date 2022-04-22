/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "core.h"
#include "factory.h"
#include "Logger.h"

bool CAutoCore::start()
{
    m_factory = std::make_shared<CFactory>();
    m_state_machine = std::make_shared<CStateMachine>();

    m_factory->setUp(); // add the components
    m_factory->init();  // initialise the added components
    m_state_machine->init(m_factory);
    m_state_machine->start();

    CLOG(LOGLEV_RUN, "Core started");

    return true;
}

bool CAutoCore::process()
{
    return m_state_machine->process();
}

bool CAutoCore::stop()
{
    CLOG(LOGLEV_RUN, "Core stopped");

    return true;
}
