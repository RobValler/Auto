/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
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

    for(const auto& it: m_module_list) {
        it.module->init();
    }

    return true;
}

bool CFactory::start()
{
    for(const auto& it: m_module_list) {
        it.module->start();
    }
    return true;
}

bool CFactory::stop()
{
    ///\ todo automate
    for(const auto& it: m_module_list) {
        it.module->stop();
    }

    return true;
}

void CFactory::addModule(const std::string module_name, const std::shared_ptr<IComponent> p_module)
{
    SModuleEntry container{module_name, p_module};
    m_module_list.emplace_back(std::move(container));
}

std::shared_ptr<IComponent> CFactory::getModule(const std::string module_name)
{
    for(const auto& it: m_module_list) {
        if(module_name == it.module_name) {
            return it.module;
        }
    }
    return nullptr;
}
