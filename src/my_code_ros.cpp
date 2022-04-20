#include <ros_coverage_example/my_code_ros.hpp>

namespace ros_coverage_example {

void SomethingWrapperROS::doSomething(std::string arg) const {
  something.doThing(arg);
}

void OtherThingWrapperROS::doOtherThing(int arg) const {
  otherThing.doOtherThing(arg);
}

} // namespace ros_coverage_example