/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include <memory>
#include <vector>

#include "icomponent.h"

enum EComponentStatus : unsigned int
{
    E_NONE = 0,
    E_INIT,
    E_STARTED,
    E_STOP
};

struct SModuleEntry
{
    std::string module_name;
    EComponentStatus status{E_NONE};
    std::shared_ptr<IComponent> module;
};

class CFactory
{
public:
    CFactory()=default;                               // Constructor
    CFactory(const CFactory&) = delete;               // Copy constructor
    CFactory(CFactory&&) = delete;                    // Move constructor
    CFactory& operator=(const CFactory&) = delete;    // Copy assignment operator
    CFactory& operator=(CFactory&&) = delete;         // Move assignment operator
    ~CFactory()=default;                              // Destructor

    bool init();
    bool start();
    bool stop();
    void addModule(const std::string module_name, const std::shared_ptr<IComponent> p_module);
    void removeModule(const std::string module_name);
    std::shared_ptr<IComponent> getModule(const std::string module_name);

private:
    std::vector<SModuleEntry> m_module_list;

};
