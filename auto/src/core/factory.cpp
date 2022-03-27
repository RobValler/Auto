/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "factory.h"

#include "sense_main.h"
#include "sit_main.h"
#include "decide_main.h"
#include "control_main.h"

bool CFactory::init()
{
    addModule("sensor", std::make_shared<CSenseMain>());
    addModule("sit", std::make_shared<CSitMain>());
    addModule("decide", std::make_shared<CDecideMain>());
    addModule("control", std::make_shared<CControlMain>());

    bool result = true;
    for(auto& it: m_module_list) {
        if(!it.module->init())
            result = false;
        else
            it.status = E_INIT;
    }
    return result;
}

bool CFactory::start()
{
    bool result = true;
    for(auto& it: m_module_list) {
        if(!it.module->start())
            result = false;
        else
            it.status = E_STARTED;
    }
    return result;
}

bool CFactory::stop()
{
    bool result = true;
    for(auto& it: m_module_list) {
        if(!it.module->stop())
            result = false;
        else
            it.status = E_STOP;
    }
    return result;
}

void CFactory::addModule(const std::string module_name, const std::shared_ptr<IComponent> p_module)
{
    SModuleEntry container{module_name, E_NONE, p_module};
    m_module_list.emplace_back(std::move(container));
}

void CFactory::removeModule(const std::string module_name)
{
    for( auto it = m_module_list.begin(); it != m_module_list.end(); /*no inc*/ )
    {
        if( module_name == it->module_name ) {
            it = m_module_list.erase(it);
            break;
        } else {
            ++it;
        }
    }
}

std::shared_ptr<IComponent> CFactory::getModule(const std::string module_name)
{
    for(const auto& it: m_module_list) {
        if ((module_name == it.module_name) &&
            (E_STARTED == it.status))
        {
            return it.module;
        }
    }
    return nullptr;
}
