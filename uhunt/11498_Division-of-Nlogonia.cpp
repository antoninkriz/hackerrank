#include <bits/stdc++.h>

using namespace std;

/**
 * 11498 - Division of Nlogonia
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
      int k;
      cin >> k;
      if (k == 0)
        break;

      int n, m;
      cin >> n >> m;

      for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        if (x == n || y == m) {
          cout << "divisa\n";
        } else {
          if (y > m)
            cout << "N";
          else
            cout << "S";

          if (x > n)
            cout << "E\n";
          else
            cout << "O\n";
        }
      }

    }
    
    return 0;
}
