/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "StateMachineBase.h"
#include "factory.h"

#include <atomic>

class CStateMachine : CStateMachineBase
{
public:
    CStateMachine()=default;                                    // Constructor
    CStateMachine(const CStateMachine&) = delete;               // Copy constructor
    CStateMachine(CStateMachine&&) = delete;                    // Move constructor
    CStateMachine& operator=(const CStateMachine&) = delete;    // Copy assignment operator
    CStateMachine& operator=(CStateMachine&&) = delete;         // Move assignment operator
    ~CStateMachine()=default;                                   // Destructor

    bool init(std::shared_ptr<CFactory> p_factory);
    bool start();
    bool process();
    bool stop();

private:
    void RunCallout(unsigned int return_code) override;

    std::atomic<bool> m_shutdown_request{false};
    std::shared_ptr<CFactory> m_factory;

};
