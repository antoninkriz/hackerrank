#include <bits/stdc++.h>

using namespace std;

/**
 * 11727 - Cost Cutting
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      printf("Case %d: %d\n", i + 1, max(min(a,b), min(max(a,b),c)));
    }
    
    return 0;
}
