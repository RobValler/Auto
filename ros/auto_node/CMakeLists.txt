#*****************************************************************
# * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
# *
# * This file is part of the project: Auto
# *
# * This project can not be copied and/or distributed
# * without the express permission of the copyright holder
# *****************************************************************
cmake_minimum_required(VERSION 3.8)
project(auto_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_definitions(-DROS2_IS_ENABLED)
add_definitions(-DGAZEBO_IS_ENABLED)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
#find_package(msg_def REQUIRED)
find_package(gazebo REQUIRED)

find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)


#paths
#external
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../DevFramework/StateMachine)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../DevFramework/Factory)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../DevFramework/Logger/include)

#internal
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../src/core)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../src/state_machine)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../src/control)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../src/decide)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../src/sense)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../src/situation)

#simulation
#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../simulation)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()


#SOURCE FILES
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/*.cpp
#    ${CMAKE_CURRENT_SOURCE_DIR}/../../simulation/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../DevFramework/StateMachine/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../DevFramework/Factory/*.cpp
    )

file(GLOB_RECURSE HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/../../src/*.h
#    ${CMAKE_CURRENT_SOURCE_DIR}/../../simulation/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../DevFramework/StateMachine/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../DevFramework/Factory/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/../../../DevFramework/Logger/Logger.h
    )

#GENERATE
add_executable(cpp_code ${SOURCES} ${HEADERS} )

ament_target_dependencies(cpp_code
                            rclcpp
                            std_msgs
#                            msg_def
                            gazebo
                            geometry_msgs
                            sensor_msgs)
                        
install(TARGETS
    cpp_code
    DESTINATION lib/${PROJECT_NAME})                        
