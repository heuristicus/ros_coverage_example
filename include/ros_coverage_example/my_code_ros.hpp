#ifndef MY_CODE_ROS_H
#define MY_CODE_ROS_H

#include <ros/ros.h>
#include <ros_coverage_example/my_code.hpp>
#include <std_msgs/Int8.h>
#include <std_msgs/String.h>

namespace ros_coverage_example {
class SomethingWrapperROS {
public:
  SomethingWrapperROS(ros::NodeHandle &nh)
      : initialised(true),
        publisher(nh.advertise<std_msgs::Int8>("something", 1)){};
  void doSomething(std::string arg) const;
  bool isInitialised() const { return initialised; }
  std::string topic() const { return publisher.getTopic(); }

private:
  SomethingDoer something;
  bool initialised;
  ros::Publisher publisher;
};

class OtherThingWrapperROS {
public:
  OtherThingWrapperROS(ros::NodeHandle &nh)
      : initialised(true),
        publisher(nh.advertise<std_msgs::String>("other_thing", 1)){};
  void doOtherThing(int arg) const;
  bool isInitialised() const { return initialised; }
  std::string topic() const { return publisher.getTopic(); }

private:
  OtherThingDoer otherThing;
  bool initialised;
  ros::Publisher publisher;
};
} // namespace ros_coverage_example

class UntestedThing {
public:
  UntestedThing(){};
};

#endif