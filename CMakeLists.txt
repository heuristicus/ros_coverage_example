cmake_minimum_required(VERSION 3.0.2)
project(ros_coverage_example)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_python_setup()

catkin_package()

set(SRC_FILES
  src/my_code.cpp
  src/my_code_ros.cpp
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
link_directories(${catkin_LIBRARY_DIRS})

add_library(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})

if(CATKIN_ENABLE_TESTING AND ENABLE_COVERAGE_TESTING)
  find_package(code_coverage REQUIRED)
  # Add compiler flags for coverage instrumentation before defining any targets
  APPEND_COVERAGE_COMPILER_FLAGS()
endif()

if (CATKIN_ENABLE_TESTING)
  # Add your tests here
  find_package(rostest REQUIRED)
  foreach(T
    test/launch/test_my_code.launch
    test/launch/test_my_code_ros.launch
  )
  add_rostest(${T})
  endforeach()

  foreach(T
    test/test_my_code.cpp
  )
  get_filename_component(TEST_NAME ${T} NAME_WLE)
  catkin_add_gtest(${TEST_NAME} ${T})
  target_link_libraries(${TEST_NAME} ${PROJECT_NAME} ${catkin_LIBRARIES} ${GTEST_LIBRARIES})
  endforeach()

  foreach(T
    test/test_my_code_ros.cpp
  )
  get_filename_component(TEST_NAME ${T} NAME_WLE)
  add_executable(${TEST_NAME} ${T})
  add_dependencies(tests ${TEST_NAME})
  target_link_libraries(${TEST_NAME} ${PROJECT_NAME} ${catkin_LIBRARIES} ${GTEST_LIBRARIES})
  endforeach()

  add_rostest(test/launch/test_my_code_cpp_ros.launch)
  add_rostest(test/launch/test_my_code_cpp.launch)

  # Create a target ${PROJECT_NAME}_coverage_report
  if(ENABLE_COVERAGE_TESTING)
    set(COVERAGE_EXCLUDES "*/${PROJECT_NAME}/test*")
    add_code_coverage(
      NAME ${PROJECT_NAME}_coverage_report
      DEPENDENCIES tests
    )
  endif()
endif()