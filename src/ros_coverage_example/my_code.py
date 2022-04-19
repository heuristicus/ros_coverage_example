#!/usr/bin/env python
"""
This file implements the functionality we want in a ros-independent way
"""


class SomethingDoer:
    def __init__(self):
        self.initialised = True

    def do_thing(self, arg: str):
        if arg.startswith("test"):
            return True
        elif arg.startswith("not"):
            return False
        else:
            # untested branch
            return True

    def untested_something(self, arg: str):
        if arg.startswith("asdf"):
            return False

        return True


class OtherThingDoer:
    def __init__(self):
        self.initialised = True

    def do_other_thing(self, arg: int):
        if arg < 0:
            raise ValueError
        elif 0 <= arg <= 10:
            return True

        if arg < 10:
            # This is an untested branch
            pass
        else:
            return False

    def untested_other_thing(self, arg: int):
        if arg > 10:
            raise ValueError

        return False
