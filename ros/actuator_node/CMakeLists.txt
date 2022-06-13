#*****************************************************************
# * Copyright (C) 2017-2022 Robert Valler - All rights reserved.
# *
# * This file is part of the project: Auto
# *
# * This project can not be copied and/or distributed
# * without the express permission of the copyright holder
# *****************************************************************
cmake_minimum_required(VERSION 3.8)
project(actuator_node)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()

add_executable(cpp_code src/actuator.cpp)
ament_target_dependencies(cpp_code
                            rclcpp
                            std_msgs)

install(TARGETS
    cpp_code
    DESTINATION lib/${PROJECT_NAME})
