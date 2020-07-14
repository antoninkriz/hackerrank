#!/bin/python3

import math
import os
import random
import re
import sys


def repeatedString(s, n):
    x = 0
    for c in s:
        x += 1 if c == 'a' else 0

    total = (n // len(s)) * x

    i = 0
    m = n - ((n // len(s)) * len(s))
    for c in s:
        if i >= m:
            break

        total += 1 if c == 'a' else 0
        i += 1

    return total


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()
    n = int(input())
    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')
    fptr.close()
