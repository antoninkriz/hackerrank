#include <bits/stdc++.h>

using namespace std;

/**
 * 11152 - Colourful Flowers
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, z;
    while (cin >> x >> y >> z) {
      double angleX = acos((pow(y, 2) + pow(z, 2) - pow(x, 2)) / (2 * y * z));
      double rB = x / (2 * sin(angleX));    

      double s = (x + y + z) / 2.0;
      double rS = sqrt(s * (s - x) * (s - y) * (s - z)) / s;

      double sB = M_PI * (rB * rB);
      double sT = sqrt(s * (s - x) * (s - y) * (s - z));
      double sS = M_PI * (rS * rS);

      cout << fixed << setprecision(4) << sB - sT << " " << sT - sS << " " << sS << "\n";
    }
    
    return 0;
}
