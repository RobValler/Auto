/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "FactoryBase.h"

class CFactory : public CFactoryBase
{
public:
    CFactory()=default;                               // Constructor
    CFactory(const CFactory&) = delete;               // Copy constructor
    CFactory(CFactory&&) = delete;                    // Move constructor
    CFactory& operator=(const CFactory&) = delete;    // Copy assignment operator
    CFactory& operator=(CFactory&&) = delete;         // Move assignment operator
    ~CFactory()=default;                              // Destructor

    void setUp();
};
