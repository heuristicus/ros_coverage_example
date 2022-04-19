#!/usr/bin/env python
"""
Pretend that this file wraps my_code stuff to expose it to ros
"""
import rospy
from std_msgs.msg import String, Int8
from ros_coverage_example.my_code import SomethingDoer, OtherThingDoer


class SomethingWrapperROS:
    def __init__(self):
        self.something = SomethingDoer()
        self.initialised = True
        self.publisher = rospy.Publisher("something", String, queue_size=1)

    def do_something(self, thing):
        self.something.do_thing(thing)


class OtherThingWrapperROS:
    def __init__(self):
        self.other_thing = OtherThingDoer()
        self.initialised = True
        self.publisher = rospy.Publisher("other_thing", Int8, queue_size=1)

    def do_other_thing(self, other_thing):
        self.other_thing.do_other_thing(other_thing)


class UntestedThing:
    def __init__(self):
        pass
