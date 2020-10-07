# 10523 - Very Easy !!!
import sys

for line in sys.stdin:
  s = 0
  n, a = [int(x) for x in line.split()]
  
  for i in range(1, n + 1):
    s += i * (a ** i)
  print(s)
