#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

struct State {
    int node, parent, day;
} __attribute__((aligned(16)));

struct Pair {
    int a, b;
} __attribute__((aligned(8)));

vector<Pair> adj[200000 + 300];
vector<int> ans[200000 + 300];

int maxDays = 0;

void dfs() {
    auto s = stack<State>();
    s.push({1, 0, 0});

    while (!s.empty()) {
        int day = 0;
        auto state = s.top();
        s.pop();

        for (auto x : adj[state.node]) {
            if (x.a == state.parent)
                continue;

            day++;

            if (state.day == day)
                day++;

            ans[day].push_back(x.b);
            s.push({x.a, state.node, day});
        }

        maxDays = max(maxDays, day);
    }
}

/**
 * Road Improvement
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back({y, i + 1});
        adj[y].push_back({x, i + 1});
    }

    dfs();

    cout << maxDays << '\n';
    for (int i = 1; i < maxDays + 1; i++) {
        cout << ans[i].size() << ' ';
        for (const auto &x : ans[i])
            cout << x << ' ';
        cout << '\n';
    }
}
