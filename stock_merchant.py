#!/bin/python3

import math
import os
import random
import re
import sys


def sockMerchant(n, ar):
    m = dict()
    for v in ar:
        if v not in m:
            m[v] = 0
        m[v] += 1

    t = 0
    for k, v in m.items():
        t += v // 2

    return t


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())
    ar = list(map(int, input().rstrip().split()))
    result = sockMerchant(n, ar)

    fptr.write(str(result) + '\n')
    fptr.close()
