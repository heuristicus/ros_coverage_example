#include <ros_coverage_example/my_code.hpp>
#include <stdexcept>

namespace ros_coverage_example {

bool SomethingDoer::doThing(std::string arg) const {
  if (arg.rfind("test", 0) == 0) {
    return true;
  } else if (arg.rfind("not", 0) == 0) {
    return false;
  } else {
    // untested branch
    return true;
  }
}

bool SomethingDoer::untestedSomething(std::string arg) const {
  if (arg.rfind("asdf", 0) == 0) {
    return false;
  }
  return true;
}

bool OtherThingDoer::doOtherThing(int arg) const {
  if (arg < 0) {
    throw std::invalid_argument("Argument is less than zero");
  } else if (arg >= 0 && arg <= 10) {
    return true;
  } else if (arg >= 30 && arg <= 50) {
    return true;
  } else {
    return false;
  }
}

bool OtherThingDoer::untestedOtherThing(int arg) const {
  if (arg > 10) {
    throw std::invalid_argument("Argument is greater than 10");
  }

  return false;
}

} // namespace ros_coverage_example