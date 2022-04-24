/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#include "decide_main.h"

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
    void (*func)(void);
};

void accelerate()
{
    CLOG(LOGLEV_RUN, "Accelerating" );
}

void cruise()
{
    CLOG(LOGLEV_RUN, "Cruising" );
}

void brake()
{
    CLOG(LOGLEV_RUN, "Braking" );
}

std::vector<SRuleTableStruct> l_rule_table
{
    // IF                       |   COMPARE           | EXPECTED      | RESULT
    //================================================================================
    {/*current distance*/           EEC_LESS_THAN,      0.5f,           &brake},
    {/*current distance*/           EEC_MORE_THAN,      0.5f,           &accelerate}

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
            if(m_distance < it.compare)
                it.func();
            break;
        }
        case EEC_MORE_THAN:
        {
            if(m_distance > it.compare)
                it.func();
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
