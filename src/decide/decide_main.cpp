/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "decide_main.h"

#include "sit_data.h"

#include "Logger.h"

#include <vector>

enum EEventCompare {
    EEC_NONE =0,
    EEC_LESS_THAN,
    EEC_EQUAL_TO,
    EEC_MORE_THAN
};

struct SRuleTableStruct {
    //float actual_data;
    EEventCompare compare;
    float expected_data;
    std::string (*func)(void);
};

std::string accelerate()
{
    CLOG(LOGLEV_RUN, "Accelerating" );
    return "Accelerate";
}

std::string cruise()
{
    CLOG(LOGLEV_RUN, "Cruising" );
    return "Cruise";
}

std::string brake()
{
    CLOG(LOGLEV_RUN, "Braking" );
    return "Brake";
}

std::vector<SRuleTableStruct> l_rule_table
{
    // IF                       |   COMPARE           | EXPECTED      | RESULT
    //================================================================================
    {/*current distance*/           EEC_LESS_THAN,      20.0f,           &brake},
    {/*current distance*/           EEC_MORE_THAN,      20.0f,           &accelerate}

};

bool CDecideMain::init()
{

    return true;
}

bool CDecideMain::start()
{

    return true;
}

bool CDecideMain::process()
{
    bool result = false;

    for(const auto& it: l_rule_table)
    {
        switch(it.compare)
        {
        case EEC_LESS_THAN:
        {
            if(m_distance < it.expected_data)
                m_current_decision = it.func();
            break;
        }
        case EEC_MORE_THAN:
        {
            if(m_distance > it.expected_data)
                m_current_decision = it.func();
            break;
        }
        default:
            return false;
        }

    }
    return result;
}

bool CDecideMain::stop()
{

    return true;
}

bool CDecideMain::setTheData(void* ptr)
{
    float* p = static_cast<float*>(ptr);
    m_distance = *p;
    return true;
}


bool CDecideMain::getTheData(void*)
{
//    ptr = &m_current_decision.at(0);
    return true;
}

bool CDecideMain::setData(const SSITDistancesData& data)
{
    m_distance = data.distanceToFront;
    return true;
}

bool CDecideMain::getData(std::string& data)
{
    data = m_current_decision;
    return true;
}
