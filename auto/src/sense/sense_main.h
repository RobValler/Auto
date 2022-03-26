/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

class CSenseMain
{
public:
    CSenseMain()=default;                                // Constructor
    CSenseMain(const CSenseMain&) = delete;               // Copy constructor
    CSenseMain(CSenseMain&&) = delete;                    // Move constructor
    CSenseMain& operator=(const CSenseMain&) = delete;    // Copy assignment operator
    CSenseMain& operator=(CSenseMain&&) = delete;         // Move assignment operator
    ~CSenseMain()=default;                               // Destructor

    bool start();
    bool stop();

private:


};
