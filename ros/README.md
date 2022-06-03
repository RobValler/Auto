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
```
colcon build --symlink-install
source install/setup.bash
ros2 run <package_name> cpp_code
```

### Using QtCreator
Run the following commands and then load the CMakeLists.txt file for the   
relevant ros package.   
```
source /opt/ros/humble/setup.bash
qtcreator auto_node/CMakeLists.txt sensor_node/CMakeLists.txt
```
