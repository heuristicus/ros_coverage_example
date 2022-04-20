#include <gtest/gtest.h>
#include <ros/ros.h>
#include <ros_coverage_example/my_code_ros.hpp>

namespace ros_coverage_example {

class TestWrappers: public testing::Test
{
public:
    ros::NodeHandle* node;

    void SetUp() override
    {
        testing::Test::SetUp();
        this->node = new ros::NodeHandle();
    };

    void TearDown() override
    {
        delete this->node;
        testing::Test::TearDown();
    }
};


TEST_F(TestWrappers, testSomethingInit) {
  SomethingWrapperROS a(*(this->node));
  EXPECT_TRUE(a.isInitialised());
}

TEST_F(TestWrappers, testSomethingPub) {
  SomethingWrapperROS a(*(this->node));
  EXPECT_EQ(a.topic(), "/something");
}

TEST_F(TestWrappers, testOtherThingInit) {
  OtherThingWrapperROS a(*(this->node));
  EXPECT_TRUE(a.isInitialised());
}

TEST_F(TestWrappers, testOtherThingPub) {
  OtherThingWrapperROS a(*(this->node));
  EXPECT_EQ(a.topic(), "/other_thing");
}

} // namespace ros_coverage_example

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "test_my_code_ros_cpp");
  return RUN_ALL_TESTS();
}