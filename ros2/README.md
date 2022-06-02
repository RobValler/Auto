#ROS2 Example

##Dependencies
###Install colcon
'''
pip install -U colcon-common-extensions
'''

##How to create and build a package
###Command line
Run through the following sequence:   
'''
source /opt/ros/humble/setup.bash
ros2 pkg create <package_name> --build-type ament_cmake --dependencies rclcpp
'''
Add the source code and ensure the CMakeLists.txt is updated.   
'''
colcon build --symlink-install
source install/setup.bash
ros2 run <package_name> cpp_code
'''

###Using QtCreator
Run the following commands and then load the CMakeLists.txt file for the   
relevant ros package.   
'''
source /opt/ros/humble/setup.bash
qtcreator <package_name>/CMakeLists.txt
'''
