#/*****************************************************************
# * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
# *
# * This file is part of the project: Communication platform
# *
# * This project can not be copied and/or distributed
# * without the express permission of the copyright holder
# *****************************************************************/
project( auto_main )

#INCLUDES
#external
include_directories(${CMAKE_SOURCE_DIR}/../DevFramework/StateMachine)
include_directories(${CMAKE_SOURCE_DIR}/../DevFramework/Factory)
include_directories(${CMAKE_SOURCE_DIR}/../DevFramework/Logger)

#internal
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/common)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/state_machine)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/control)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/decide)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/sense)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/situation)


#SOURCE FILES
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/../DevFramework/StateMachine/*.cpp
    ${CMAKE_SOURCE_DIR}/../DevFramework/Factory/*.cpp
    )

file(GLOB_RECURSE HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/../DevFramework/StateMachine/*.h
    ${CMAKE_SOURCE_DIR}/../DevFramework/Factory/*.h
    ${CMAKE_SOURCE_DIR}/../DevFramework/Logger/Logger.h
    )

#GENERATE
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} )
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
