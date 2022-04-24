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

class CStateStart : public IStateClassBase
{
public:
    CStateStart(std::shared_ptr<void> p)                    // Constructor
    {
        m_factory = std::static_pointer_cast<CFactory>(p);
    }
    CStateStart(const CStateStart&) = delete;               // Copy constructor
    CStateStart(CStateStart&&) = delete;                    // Move constructor
    CStateStart& operator=(const CStateStart&) = delete;    // Copy assignment operator
    CStateStart& operator=(CStateStart&&) = delete;         // Move assignment operator
    ~CStateStart()=default;                                 // Destructor

    StateReturnCode StateEntry() override {
        m_factory->start();
        return StateCodeEntryOK;
    }
    StateReturnCode StateRun() override { return StateCodeRunExitOK; }
    StateReturnCode StateExit() override { return StateCodeExitOK; }

private:
    std::shared_ptr<CFactory> m_factory;

};
