import timeit

class Solution:
    def __init__(self, value = None, placement = None):
        self.value = value
        self.placement = placement

    """Must return a value"""
    def logic(self):
        print("Please overrite the logic function...")
        return None

    def run(self):
        print("Executing Project Euler Solution...\n")

        beg = timeit.default_timer()
        value = self.logic()
        fin = timeit.default_timer()

        print("Finished executing in {} milliseconds\n".format(fin - beg))

        if self.value == None:
            if value == None: print("The correct value is not known, and no value was discovered")
            else: print("The correct value is not known, however the value {} was discovered".format(value))
        else:
            if value != self.value: print("The correct value is {}, however an incorrect value of {} was discovered".format(self.value, value))
            else: print("Congratulations, the correct value of {} was discovered!".format(value))

        if self.placement != None: print("I was person number {} to solve this equation".format(self.placement))
