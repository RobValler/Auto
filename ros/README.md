# ROS2 Example
This uses the "Humble Hawksbill" version of ROS2.   

## Install ROS2 Humble Hawksbill

Install base packages:   
```
I pretty much forgot already :(
```

Install colcon:   
```
pip install -U colcon-common-extensions
```

## How to create and build a ROS package
### Command line
Run through the following sequence:   
```
source /opt/ros/humble/setup.bash
ros2 pkg create <package_name> --build-type ament_cmake --dependencies rclcpp
```
Add the source code and ensure the CMakeLists.txt is updated.   
Build all:   
```
colcon build --symlink-install
source install/setup.bash
ros2 run <package_name> cpp_code
```

Use the following to build a specific package:   
```
colcon build --packages-select <package_name>
```

### Using QtCreator
Run the following commands and then load the CMakeLists.txt file for the   
relevant ros package.   
```
source /opt/ros/humble/setup.bash
qtcreator auto_node/CMakeLists.txt sensor_node/CMakeLists.txt actuator_node/CMakeLists.txt
```

### Using Gazebo
Install the support packages:   
```
sudo apt install ros-humble-gazebo-ros-pkgs
sudo apt install ros-humble-ros-core ros-foxy-geometry2
gedit /opt/ros/humble/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
```
In terminal 1:   
```
gazebo --verbose /opt/ros/humble/share/gazebo_plugins/worlds/gazebo_ros_diff_drive_demo.world
gazebo --verbose /home/rob/WORK/Development/Auto/simulation/gazebo/my_world.sdf
```
In terminal 2:   
```
ros2 topic pub /demo/cmd_demo geometry_msgs/Twist '{linear: {x: 1.0}}' -1
```


