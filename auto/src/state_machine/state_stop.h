/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "IStateClassBase.h"
#include "factory.h"

class CFactory;

class CStateStop : public IStateClassBase
{
public:
    CStateStop(std::shared_ptr<void> p)                   // Constructor
    {
        m_factory = std::static_pointer_cast<CFactory>(p);
    }
    CStateStop(const CStateStop&) = delete;               // Copy constructor
    CStateStop(CStateStop&&) = delete;                    // Move constructor
    CStateStop& operator=(const CStateStop&) = delete;    // Copy assignment operator
    CStateStop& operator=(CStateStop&&) = delete;         // Move assignment operator
    ~CStateStop()=default;                                // Destructor

    StateReturnCode StateEntry() override {
        m_factory->stop();
        return StateCodeEntryOK;
    }
    StateReturnCode StateRun() override { return StateCodeRunExitOK; }
    StateReturnCode StateExit() override { return StateCodeExitOK; }

private:
    std::shared_ptr<CFactory> m_factory;

};
