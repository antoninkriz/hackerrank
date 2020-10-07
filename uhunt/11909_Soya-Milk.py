# 11909 - Soya Milk
import sys
import math

for line in sys.stdin:
    l, w, h, d = [int(x) for x in line.split()]

    sin_l = math.sin(math.radians(90 - d))
    sin_h = math.sin(math.radians(d))
    h_tri = (l * sin_h) / sin_l

    if h < h_tri:
        res = ((h * ((h * sin_l) / sin_h)) / 2) * w
    else:
        res = l * w * h - (l * h_tri / 2) * w

    print("{0:.3f} mL".format(res))
