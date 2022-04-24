/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "factory.h"
#include "state_machine.h"

#include <memory>

class CAutoCore
{
public:
    CAutoCore()=default;                                // Constructor
    CAutoCore(const CAutoCore&) = delete;               // Copy constructor
    CAutoCore(CAutoCore&&) = delete;                    // Move constructor
    CAutoCore& operator=(const CAutoCore&) = delete;    // Copy assignment operator
    CAutoCore& operator=(CAutoCore&&) = delete;         // Move assignment operator
    ~CAutoCore()=default;                               // Destructor

    bool start();
    bool process();
    bool stop();

private:
    std::shared_ptr<CFactory> m_factory;
    std::shared_ptr<CStateMachine> m_state_machine;

};
