#!/bin/python3

import math
import os
import random
import re
import sys


def getHourglassSum(arr):
    return sum(arr[0]) + sum(arr[2]) + arr[1][1]


def hourglassSum(arr):
    return max([getHourglassSum([x[c: c+3] for x in arr[r: r+3]]) for c in range(4) for r in range(4)])


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr = []
    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    result = hourglassSum(arr)

    fptr.write(str(result) + '\n')
    fptr.close()
