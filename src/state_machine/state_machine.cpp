/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "state_machine.h"
#include "IStateClassBase.h"

// state classes
#include "state_start.h"
#include "state_main.h"
#include "state_stop.h"

enum EStateTable : unsigned int
{
    EST_NONE,
    EST_START,
    EST_MAIN,
    EST_STOP
};

bool CStateMachine::init(std::shared_ptr<CFactory> p_factory)
{
    m_factory = p_factory;
    return true;
}

bool CStateMachine::start()
{
    AddNewState(EST_START,  "Start",    std::make_shared<CStateStart>(m_factory));
    AddNewState(EST_MAIN,   "Main",     std::make_shared<CStateMain>(m_factory));
    AddNewState(EST_STOP,   "Stop",     std::make_shared<CStateStop>(m_factory));

    SetInitState(EST_START);
    return true;
}

bool CStateMachine::process()
{
    Process();

    if(!m_shutdown_request)
        return true;
    else
        return false;
}

bool CStateMachine::stop()
{
    SetNextState(EST_STOP);
    return true;
}

void CStateMachine::RunCallout(unsigned int return_code)
{
    switch(GetCurrentState())
    {
        case EST_START:
            SetNextState(EST_MAIN);
            break;
        case EST_MAIN:
        {
            if(IStateClassBase::StateCodeRunOK != return_code)
            {
                SetNextState(EST_STOP);
            }
            break;
        }
        case EST_STOP:
            m_shutdown_request = true;
            break;
    }
}
