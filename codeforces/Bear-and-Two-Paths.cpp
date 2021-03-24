#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
 * Bear and Two Paths
 */
int main() {
    ll n, k, a, b, c, d;

    cin >> n >> k;
    cin >> a >> b >> c >> d;

    if (k < n + 1 || n == 4) {
        printf("-1");
        return 0;
    }

    vector<ll> v(n - 4);
    for (ll i = 1; i <= n; i++) {
        if (i == a || i == b || i == c || i == d)
            continue;
        v[i - (i >= a) - (i >= b) - (i >= c) - (i >= d) - 1] = i;
    }

    cout << a << ' ' << c << ' ';
    for (const auto &x : v)
        cout << x << ' ';
    cout << d << ' ' << b << '\n';

    cout << c << ' ' << a << ' ';
    for (const auto &x : v)
        cout << x << ' ';
    cout << b << ' ' << d << ' ';

    return 0;
}
