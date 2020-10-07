#include <bits/stdc++.h>

using namespace std;

int t, a, b, c;

/**
 * 11727 - Cost Cutting
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    
    for (int i = 1; i <= t; i++) {
      cin >> a >> b >> c;
      cout << "Case " << i << ": " << max(min(a,b), min(max(a,b),c)) << "\n";
    }

    cout << flush;
    
    return 0;
}
