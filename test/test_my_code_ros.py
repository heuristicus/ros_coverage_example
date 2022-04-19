#!/usr/bin/env python
"""
Test the code that is present in the my_code_ros.py file using rostest.rosrun, needed because we are pretending it
needs a roscore
"""

import rospy
import unittest

from ros_coverage_example.my_code_ros import SomethingWrapperROS, OtherThingWrapperROS

PKG = "ros_coverage_example"

class TestSomethingWrapper(unittest.TestCase):
    def test_something_init(self):
        a = SomethingWrapperROS()

        self.assertTrue(a.initialised)

    def test_other_thing_pub(self):
        a = SomethingWrapperROS()

        self.assertTrue(hasattr(a, "publisher"))


class TestOtherThingWrapper(unittest.TestCase):
    def test_other_thing_init(self):
        a = OtherThingWrapperROS()

        self.assertTrue(a.initialised)

    def test_other_thing_pub(self):
        a = OtherThingWrapperROS()

        self.assertTrue(hasattr(a, "publisher"))


class TestMyCodeROSSuite(unittest.TestSuite):
    def __init__(self):
        super().__init__()
        # Must use loadTestsFromTestCase to get all functions with prefix test_ in the given test case. Otherwise
        # only the runTest function is added to the suite.
        loader = unittest.TestLoader()
        self.addTest(loader.loadTestsFromTestCase(TestSomethingWrapper))
        self.addTest(loader.loadTestsFromTestCase(TestOtherThingWrapper))


if __name__ == "__main__":
    import rostest

    rospy.init_node("test_my_code_ros")
    rostest.rosrun(PKG, "my_code_ros", "test_my_code_ros.TestMyCodeROSSuite")
