#!/bin/bash
set -e
. /opt/ros/humble/setup.bash

gazebo --verbose topic_demo.world &
ros2 run rviz2 rviz2 demo.rviz &
#ros2 topic pub /demo/cmd_demo geometry_msgs/Twist '{linear: {x: 1.0}}' -1
