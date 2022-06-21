#!/bin/bash
set -e
. /opt/ros/humble/setup.bash
. install/setup.bash

qtcreator	sensor_node/CMakeLists.txt \
		actuator_node/CMakeLists.txt \
		msg_def/CMakeLists.txt \
		auto_node/CMakeLists.txt
		

#i=0
#declare -a arrFolder
#for folder in *; do
#    if [ -d "$folder" ]; then
##        echo "$folder"
        
#        arrFolder[ $i ]="$folder"
#        (( i++ ))
        
#        echo "${arrFolder[$i]}"
#    fi
#done

#echo "Array = ${arrFolder}"


