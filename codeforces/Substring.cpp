#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll A = 'a';

/*
 * Substring
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    string s;

    cin >> n >> m >> s;

    vector<vector<ll>> dp(n, vector<ll>(26));

    vector<vector<ll>> graph(n);
    vector<ll> deg(n);
    deque<ll> q;

    for (ll i = 0; i < m; i++) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
        deg[y]++;
    }

    for (ll i = 0; i < n; i++) {
        if (deg[i] == 0) {
            q.push_back(i);
            dp[i][s[i] - A] = 1;
        }
    }

    ll cnt = 0;
    while (!q.empty()) {
        ll node = q.front();
        q.pop_front();
        cnt++;

        for (const auto &i : graph[node]) {
            for (ll l = 0; l < 26; l++) {
                ll num = (s[i] - A) == l ? 1 : 0;
                dp[i][l] = max(dp[i][l], dp[node][l] + num);
            }

            deg[i] -= 1;
            if (deg[i] == 0)
                q.push_back(i);
        }
    }

    if (cnt != n) {
        cout << -1;
    } else {
        ll ans = 0;
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < 26; j++)
                ans = max(ans, dp[i][j]);
        cout << ans;
    }

    return 0;
}
