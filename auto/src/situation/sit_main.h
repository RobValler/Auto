/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

class CSitMain
{
public:
    CSitMain()=default;                                // Constructor
    CSitMain(const CSitMain&) = delete;               // Copy constructor
    CSitMain(CSitMain&&) = delete;                    // Move constructor
    CSitMain& operator=(const CSitMain&) = delete;    // Copy assignment operator
    CSitMain& operator=(CSitMain&&) = delete;         // Move assignment operator
    ~CSitMain()=default;                               // Destructor

    bool start();
    bool stop();

private:


};
