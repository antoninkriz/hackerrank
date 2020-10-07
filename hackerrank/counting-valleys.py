#!/bin/python3

import math
import os
import random
import re
import sys


def countingValleys(n, s):
    isInValley = False
    height = 0
    valleys = 0

    for c in s:
        height += 1 if c == 'U' else -1
        if height < 0 and not isInValley:
            isInValley = True
            valleys += 1
        elif height >= 0:
            isInValley = False

    return valleys


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())
    s = input()
    result = countingValleys(n, s)

    fptr.write(str(result) + '\n')
    fptr.close()
