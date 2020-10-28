#include <bits/stdc++.h>
 
using namespace std;
 
#define MFL 200000
 
int n, m, ta, tb, k;
int a[MFL], b[MFL];
 
/**
 * Born This Way
 */
int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    cin >> n >> m >> ta >> tb >> k;
 
    // I can remove more flights than available
    if (k >= n || k >= m) {
        cout << "-1";
        return 0;
    }
 
    // Read flights from A to B
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i] += ta;
 
    // Read flights from B to C
    for (int i = 0; i < m; i++) {
        cin >> b[i];
 
        // Skip flights that depart before the first flight from A can arrive
        if (b[i] < a[0])
            i--, m--;
 
        // If there's k or less flights there'll be no possible path
        if (k >= m) {
            cout << "-1";
            return 0;
        }
    }
 
    int x, res = 0;
 
    // For each cut...
    for (int i = 0; i <= k; i++) {
        // Find first flight from B to C that's after arrival of A[i] flight
        x = (k - i) + (int) (lower_bound(b, b + m, a[i]) - b);
 
        // Out of bounds, skip the rest
        if (x > m - 1) {
            cout << "-1";
            return 0;
        }
 
        // Update flight if a worse one is found
        res = max(b[x] + tb, res);
    }
 
    // Print result
    cout << res;
    return 0;
}
