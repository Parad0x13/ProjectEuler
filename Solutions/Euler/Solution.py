import sys
import timeit

import cProfile

class Solution:
    def __init__(self, value = None, placement = None, profile = False):
        self.value = value
        self.placement = placement
        self.profile = profile

    def log(self, text):
        print("[EULER] {}".format(text), flush = True)

    """Must return a value"""
    def logic(self):
        self.log("Please overwrite the logic function...")
        return None

    def run(self):
        self.log("Executing Project Euler Solution '{}'".format(sys.argv[0].replace(".py", "")))

        # [TODO] Get this to actually time things and run value check
        if self.profile:
            cProfile.run("logic()")
            return

        beg = timeit.default_timer()
        value = self.logic()
        fin = timeit.default_timer()

        self.log("Finished executing in {:.4f} seconds".format(fin - beg))

        if self.value == None:
            if value == None: self.log("The correct value is not known, and no value was discovered")
            else: self.log("The correct value is not known, however the value {} was discovered".format(value))
        else:
            if value != self.value: self.log("The correct value is {}, however an incorrect value of {} was discovered".format(self.value, value))
            else: self.log("Congratulations, the correct value of {} was discovered!".format(value))

        if self.placement != None: self.log("I was person number {} to solve this equation".format(self.placement))
