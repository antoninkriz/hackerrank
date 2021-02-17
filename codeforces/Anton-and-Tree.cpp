#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define uf int

#define SIZE 200001

struct State {
    uf node;
    uf parent;
    uf dist;
} __attribute__((aligned(32)));

bitset<SIZE> colors;
auto g = vector<vector<uf>>(SIZE, vector<uf>(0));

uf N;
uf a, b, i;

uf distNode = 0;
uf distMax = 0;

uf sp = 0;
State s[SIZE];
State state;
State dfs(const vector<vector<uf>> &graph, uf u) {
    s[sp++] = {u, u, 0};

    while (sp != 0) {
        state = s[--sp];
        
        if (distMax < state.dist) {
            distNode = state.node;
            distMax = state.dist;
        }

        for (const auto &x : graph[state.node]) {
            if (x != state.parent)
                s[sp++] = {x, state.node, state.dist + (colors[x] != colors[state.node])};
        }
    }
    
    return {distNode, u, distMax};
}

/**
 * Anton and Tree
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    for (i = 1; i <= N; i++)
        cin >> a, colors[i] = a;

    for (i = 0; i < N - 1; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto first = dfs(g, 1);
    auto second = dfs(g, first.node);
    cout << (second.dist + 1) / 2;

    return 0;
}
