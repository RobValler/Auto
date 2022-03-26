/*****************************************************************
 * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
 *
 * This file is part of the project: Comms
 *
 * This project can not be copied and/or distributed
 * without the express permission of the copyright holder
 *****************************************************************/

#pragma once

class IComponent{
public:
    virtual ~IComponent(){};
    virtual bool init()=0;
    virtual bool start()=0;
    virtual bool process()=0;
    virtual bool stop()=0;
};
