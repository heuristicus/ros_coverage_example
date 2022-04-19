cmake_minimum_required(VERSION 3.0.2)
project(ros_coverage_example)
find_package(catkin REQUIRED)

catkin_python_setup()

catkin_package()

include_directories()

if (CATKIN_ENABLE_TESTING)
  # Add your tests here
  find_package(rostest REQUIRED)
  foreach(T
    test/launch/test_my_code.launch
    test/launch/test_my_code_ros.launch
  )
  add_rostest(${T})
  endforeach()
endif()