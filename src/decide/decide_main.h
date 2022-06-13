/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

#include "IComponent.h"

#include <string>

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
    bool process() override;
    bool stop() override;
    bool setTheData(void* ptr) override {
        float* p = static_cast<float*>(ptr);
        m_distance = *p;
        return true;
    }
    bool getTheData(void* ptr) override;

//    void setData(float distance){ m_distance = distance; }
//    void getData(std::string& data){ data = m_current_decision; }

private:
    float m_distance;
    std::string m_current_decision;

};
