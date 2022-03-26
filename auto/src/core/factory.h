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

#include <memory>

class CSenseMain;
class CSitMain;
class CDecideMain;
class CControlMain;

class CFactory : public IComponent
{
public:
    CFactory()=default;                               // Constructor
    CFactory(const CFactory&) = delete;               // Copy constructor
    CFactory(CFactory&&) = delete;                    // Move constructor
    CFactory& operator=(const CFactory&) = delete;    // Copy assignment operator
    CFactory& operator=(CFactory&&) = delete;         // Move assignment operator
    ~CFactory()=default;                              // Destructor

    bool init() override;
    bool start() override;
    bool process() override;
    bool stop() override;

private:
    std::shared_ptr<CSenseMain> m_sense;
    std::shared_ptr<CSitMain> m_sit;
    std::shared_ptr<CDecideMain> m_decide;
    std::shared_ptr<CControlMain> m_control;

};
