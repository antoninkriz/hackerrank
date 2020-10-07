# 11879 - Multiple of 17
import sys

for line in sys.stdin:
  n = int(line)
  if n == 0:
    break

  print(1 if n % 17 == 0 else 0)
