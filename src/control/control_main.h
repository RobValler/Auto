/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "IComponent.h"

#include <memory>

enum ESetCommand : unsigned int
{
    ESC_FORWARD = 0,
    ESC_BACKWARD
};

class CActuatorProxyHandler;

class CControlMain : public IComponent
{
public:
    CControlMain()=default;                                // Constructor
    CControlMain(const CControlMain&) = delete;               // Copy constructor
    CControlMain(CControlMain&&) = delete;                    // Move constructor
    CControlMain& operator=(const CControlMain&) = delete;    // Copy assignment operator
    CControlMain& operator=(CControlMain&&) = delete;         // Move assignment operator
    ~CControlMain()=default;                               // Destructor

    bool init() override;
    bool start() override;
    bool process() override;
    bool stop() override;
    bool setTheData(void*) override { return true; }
    bool getTheData(void*) override { return true; }

    bool setCommand(std::string command);

private:
    std::shared_ptr<CActuatorProxyHandler> m_actuator_proxy_handler;

};
