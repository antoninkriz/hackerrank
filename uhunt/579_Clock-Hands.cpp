#include <bits/stdc++.h>

using namespace std;

/**
 * 579 - Clock Hands
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    double h, m, diff;
    while (cin >> h >> c >> m && !(h == 0 && m == 0)) {
        m = m * 6;
        h = h * 30 + m / 12;

        if (m > 360)
            m -= 360;
        if (h > 360)
            h -= 360;

        diff = max(h, m) - min(h, m);
        cout << fixed << setprecision(3) << (diff > 180 ? 360 - diff : diff) << "\n";
    }
}
