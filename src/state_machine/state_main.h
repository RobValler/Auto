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
class CFactory;

class CStateMain : public IStateClassBase
{
public:
    CStateMain(std::shared_ptr<void> p)                   // Constructor
    {
        m_factory = std::static_pointer_cast<CFactory>(p);
    }
    CStateMain(const CStateMain&) = delete;               // Copy constructor
    CStateMain(CStateMain&&) = delete;                    // Move constructor
    CStateMain& operator=(const CStateMain&) = delete;    // Copy assignment operator
    CStateMain& operator=(CStateMain&&) = delete;         // Move assignment operator
    ~CStateMain()=default;                                // Destructor

    StateReturnCode StateEntry() override { return StateCodeEntryOK; }
    StateReturnCode StateRun() override;
    StateReturnCode StateExit() override;

private:
    std::shared_ptr<CFactory> m_factory;
    int m_counter{0};

};
