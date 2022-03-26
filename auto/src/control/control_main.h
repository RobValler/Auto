/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "icomponent.h"

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

private:


};
