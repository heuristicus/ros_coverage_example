#include <gtest/gtest.h>
#include <ros_coverage_example/my_code.hpp>

namespace ros_coverage_example {
TEST(TestSomething, testSomethingInit) {
  SomethingDoer a;
  EXPECT_TRUE(a.isInitialised());
}

TEST(TestSomething, testSomethingFalse) {
  SomethingDoer a;
  EXPECT_TRUE(a.doThing("test"));
}

TEST(TestSomething, testSomethingTrue) {
  SomethingDoer a;
  EXPECT_FALSE(a.doThing("not test"));
}

TEST(TestOtherThing, testOtherThingInit) {
  OtherThingDoer a;
  EXPECT_TRUE(a.isInitialised());
}

TEST(TestOtherThing, testOtherThingFalse) {
  OtherThingDoer a;
  EXPECT_FALSE(a.doOtherThing(11));
}

TEST(TestOtherThing, testOtherThingTrue) {
  OtherThingDoer a;
  EXPECT_TRUE(a.doOtherThing(1));
}

TEST(TestOtherThing, testOtherThingRaise) {
  OtherThingDoer a;
  try {
    a.doOtherThing(-1);
  } catch (std::invalid_argument) {
    SUCCEED();
    return;
  }
  ADD_FAILURE();
}

} // namespace ros_coverage_example

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}