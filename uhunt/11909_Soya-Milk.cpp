#include <bits/stdc++.h>

using namespace std;

#define toRad(x) ((x) * (M_PI / 180.0))

/**
 * 11909 - Soya Milk
 */
int main() {
    int l, w, h, d;
    double sin_l, sin_h, h_tri, res;

    while (scanf("%d %d %d %d", &l, &w, &h, &d) != EOF) {
      sin_l = sin(toRad(90 - d));
      sin_h = sin(toRad(d));
      h_tri = (l * sin_h) / sin_l;

      if (h < h_tri)
          res = ((h * ((h * sin_l) / sin_h)) / 2) * w;
      else
          res = l * w * h - (l * h_tri / 2) * w;

      cout << fixed << setprecision(3) << res << " mL\n";
    }

    return 0;
}
