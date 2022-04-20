#ifndef MY_CODE_H
#define MY_CODE_H

#include <string>

namespace ros_coverage_example {

class SomethingDoer {
public:
  SomethingDoer() : initialised(true) {}

  bool doThing(std::string arg) const;
  bool untestedSomething(std::string arg) const;
  bool isInitialised() const { return initialised; }

private:
  bool initialised;
};

class OtherThingDoer {
public:
  OtherThingDoer() : initialised(true) {}

  bool doOtherThing(int arg) const;
  bool untestedOtherThing(int arg) const;
  bool isInitialised() const { return initialised; }

private:
  bool initialised;
};

} // namespace ros_coverage_example

#endif
