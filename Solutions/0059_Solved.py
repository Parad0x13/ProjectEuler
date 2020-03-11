# Project Euler problem 59 solved 1519KST 27Oct13

from Euler.Solution import Solution
import Euler.Math as EM
from itertools import product

red = open("resources/0059_p059_cipher.txt", "r").read()
red = red.split(",")

def decrypt(data, key):
    black = ""
    for index in range(len(red)):
        redItem = int(red[index])
        keyItem = ord(key[index % len(key)])
        value = redItem ^ keyItem
        black += chr(value)
    return black

def findKey():
    return "exp"    # Determined after trial and error running the code below

    saved = open("resources/test.txt", "w")

    valids = [chr(x) for x in range(32, 127)]
    keys = list(product("abcdefghijklmnopqrstuvwxyz", repeat = 3))
    blacks = []
    for key in keys:
        black = decrypt(red, key)
        if len(set(black) - set(valids)) > 0: continue
        blacks.append(black)
        saved.write("{} {}\n".format(key, black))

    print("Check resource file for valid strings")
    return None

def logic():
    key = findKey()
    black = decrypt(red, key)

    total = sum([ord(val) for val in black])
    return total

solution = Solution(value = 129448, placement = 20122)
solution.logic = logic
solution.run()
