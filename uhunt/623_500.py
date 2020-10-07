# 623 - 500!
import sys
import math

for line in sys.stdin:
    num = int(line)
    print(f"{num}!\n{math.factorial(num)}")
