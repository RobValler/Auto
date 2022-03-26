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

class CDecideMain : public IComponent
{
public:
    CDecideMain()=default;                                // Constructor
    CDecideMain(const CDecideMain&) = delete;               // Copy constructor
    CDecideMain(CDecideMain&&) = delete;                    // Move constructor
    CDecideMain& operator=(const CDecideMain&) = delete;    // Copy assignment operator
    CDecideMain& operator=(CDecideMain&&) = delete;         // Move assignment operator
    ~CDecideMain()=default;                               // Destructor

    bool init() override;
    bool start() override;
    bool stop() override;

private:


};
