#pragma optimization_level 3
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 10e5 + 42;

ll n, m, r;
ll u[MAX];
ll v[MAX];
ll c[MAX];
ll dag[MAX];
ll top[MAX];
vector<vector<ll>> g(MAX);

bool topSort() {
    queue<ll> q;
    ll cnt = 0;

    for (ll i = 1; i <= n; i++)
        if (!dag[i])
            q.push(i);

    while (!q.empty()) {
        auto x = q.front();
        q.pop();

        cnt++;
        top[x] = cnt;

        for (const auto &to : g[x]) {
            dag[to]--;
            if (dag[to] == 0)
                q.push(to);
        }
    }

    return cnt == n;
}

bool check(ll mid) {
    for (ll i = 1; i <= n; i++) {
        g[i].clear();
        dag[i] = 0;
    }

    for (ll i = 1; i <= m; i++) {
        if (c[i] > mid) {
            g[u[i]].push_back(v[i]);
            dag[v[i]]++;
        }
    }

    return topSort();
}

/*
 * Andrew and Taxi
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (ll i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> c[i];
        r = max(r, c[i]);
    }

    ll l = 0;

    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    check(l);

    ll cnt = 0;
    for (ll i = 1; i <= m; i++)
        if (c[i] <= l && top[v[i]] < top[u[i]])
            cnt++;

    cout << l << ' ' << cnt << '\n';

    for (ll i = 1; i <= m; i++)
        if (c[i] <= l && top[v[i]] < top[u[i]])
            cout << i << ' ';

    return 0;
}
