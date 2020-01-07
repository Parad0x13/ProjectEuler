import timeit

class EulerSolution:
    answer = None
    placement = None

    def __init__(self):
        pass

    def logic(self):
        print("Please overrite the logic function...")

    def run(self):
        print("Running Project Euler Solution...\n")

        beg = timeit.default_timer()
        self.logic()
        fin = timeit.default_timer()

        print("\nFinished in {} milliseconds\n".format(fin - beg))

        if self.answer != None: print("The answer should be {}".format(self.answer))
        if self.placement != None: print("I was person number {} to solve this equation".format(self.placement))
