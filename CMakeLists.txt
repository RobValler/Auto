#/*****************************************************************
# * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
# *
# * This file is part of the project: Communication platform
# *
# * This project can not be copied and/or distributed
# * without the express permission of the copyright holder
# *****************************************************************/
cmake_minimum_required(VERSION 3.15.0)
project( Automotive )

# set the defaults
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set (CMAKE_CXX_STANDARD 14)
set (Wall)
set (W1)
set (Wfloat-conversion)

# load projects
add_subdirectory(auto)
#add_subdirectory(test)

