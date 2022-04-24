/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Auto
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once



class CSimCore
{
public:

    static CSimCore& GetInstance(){
        static CSimCore instance;
        return instance;
    }

    static bool start();
    static bool process();
    static bool stop();

    static float get_range_sensor_distance();


private:
    CSimCore(){}
    CSimCore(CSimCore const&) = delete;
    void operator=(CSimCore const&) = delete;

};
