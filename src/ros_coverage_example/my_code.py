#!/usr/bin/env python
"""
This file implements the functionality we want in a ros-independent way
"""


class SomethingDoer:
    def __init__(self):
        self.initialised = True

    def do_thing(self, arg: str):
        return arg.startswith("test")


class OtherThingDoer:
    def __init__(self):
        self.initialised = True

    def do_other_thing(self, arg: int):
        if arg < 0:
            raise ValueError
        elif 0 <= arg <= 10:
            return True
        else:
            return False
