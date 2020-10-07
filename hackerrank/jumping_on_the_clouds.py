#!/bin/python3

import math
import os
import random
import re
import sys


def jumpingOnClouds(c):
    j = 0
    i = 0

    while i < len(c):
        if i == len(c) - 1:
            break

        j +=1

        if i + 2 < len(c):
            if c[i + 2] != 1:
                i +=2
            else:
                i +=1
        else:
            i +=1

    return j


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())
    c = list(map(int, input().rstrip().split()))
    result = jumpingOnClouds(c)

    fptr.write(str(result) + '\n')
    fptr.close()
