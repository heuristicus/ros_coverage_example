#!/usr/bin/env python
"""
Test the code that is present in the my_code.py file using rostest.unitrun
"""

import unittest
from ros_coverage_example.my_code import SomethingDoer, OtherThingDoer

PKG = "ros_coverage_example"


class TestSomething(unittest.TestCase):
    def test_something_init(self):
        a = SomethingDoer()

        self.assertTrue(a.initialised)

    def test_something_true(self):
        a = SomethingDoer()
        self.assertTrue(a.do_thing("test"))

    def test_something_false(self):
        a = SomethingDoer()
        self.assertFalse(a.do_thing("not test"))


class TestOtherThing(unittest.TestCase):
    def test_other_thing_init(self):
        a = OtherThingDoer()

        self.assertTrue(a.initialised)

    def test_something_false(self):
        a = OtherThingDoer()
        self.assertFalse(a.do_other_thing(11))

    def test_something_true(self):
        a = OtherThingDoer()
        self.assertTrue(a.do_other_thing(1))

    def test_something_raise(self):
        a = OtherThingDoer()
        with self.assertRaises(ValueError):
            a.do_other_thing(-1)


class TestMyCodeSuite(unittest.TestSuite):
    def __init__(self):
        super().__init__()
        # Must use loadTestsFromTestCase to get all functions with prefix test_ in the given test case. Otherwise
        # only the runTest function is added to the suite.
        loader = unittest.TestLoader()
        self.addTest(loader.loadTestsFromTestCase(TestSomething))
        self.addTest(loader.loadTestsFromTestCase(TestOtherThing))


if __name__ == "__main__":
    import rostest

    rostest.unitrun(PKG, "my_code_ros", "test_my_code.TestMyCodeSuite")
