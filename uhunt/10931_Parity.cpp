#include <bits/stdc++.h>

using namespace std;

#define leftbit (0b01000000000000000000000000000000)

/**
 * 10931 - Parity
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    while (cin >> n && n) {
      x = 0;

      cout << "The parity of ";

      for (int i = 0, started = false; i < 31; i++, n <<= 1)
        if ((x += !!(n & leftbit)) > 0)
          cout << ((n & leftbit) ? '1' : '0');

      cout << " is " << x << " (mod 2).\n";
    }
  
    return 0;
}
