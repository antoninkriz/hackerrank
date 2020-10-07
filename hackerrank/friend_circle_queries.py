#!/bin/python3

import math
import os
import random
import re
import sys


"""
Disjoint Set Union / Union Find class
"""
class UniFind:
    def __init__(self):
        self.friends = dict() # Nodes connections
        self.sizes = dict() # Sizes of each nodes group
        self.maxSize = 0 # Maximum size of all groups

    """
    Find a connection with a path compression
    """
    def find(self, n):
        while self.friends[n] != n:
            self.friends[n] = self.friends[self.friends[n]]
            n = self.friends[n]
        return n

    """
    Union
    """
    def uni(self, a, b):
        # Init if not exist
        if self.friends.get(a) is None:
            self.friends[a] = a
            self.sizes[a] = 1

        if self.friends.get(b) is None:
            self.friends[b] = b
            self.sizes[b] = 1

        # Find itself
        x = self.find(a)
        y = self.find(b)
        
        # Already in the same group
        if x == y:
            return

        # Get sizes and weight them
        # So the smaller group can be connected to the bigger one
        sx = self.sizes[x]
        sy = self.sizes[y]

        if sx < sy:
            self.friends[x] = y
            self.sizes[y] = sx + sy
        else:
            self.friends[y] = x
            self.sizes[x] = sx + sy
        
        # Update max size
        self.maxSize = sx + sy if (sx + sy) > self.maxSize else self.maxSize


def maxCircle(queries):
    u = UniFind()
    res = []

    for q in queries:
        u.uni(q[0], q[1])
        res.append(u.maxSize)

    return res


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input())

    queries = []

    for _ in range(q):
        queries.append(list(map(int, input().rstrip().split())))

    ans = maxCircle(queries)

    fptr.write('\n'.join(map(str, ans)))
    fptr.write('\n')

    fptr.close()
