#include <bits/stdc++.h>

using namespace std;

class Query {
public:
    long from;
    long to;
    long amount;

    friend istream &operator>>(istream &is, Query &l) {
        return is >> l.from >> l.to >> l.amount;
    }

    friend bool operator<(const Query &a, const Query &b) {
        return a.from != b.from
               ? a.from < b.from
               : a.to != b.to
                 ? a.to < b.to
                 : false;
    }
};


long manipulate(vector<Query> &queries, unordered_map<long, size_t> &levels) {
    auto max = 0l;

    auto volumes = vector<long>(levels.size());

    for (const auto &q : queries) {
        auto idxStart = levels[q.from];
        auto idxEnd = levels[q.to];

        for (auto i = idxStart; i <= idxEnd; i++) {
            volumes[i] += q.amount;

            if (volumes[i] > max)
                max = volumes[i];
        }
    }

    return max;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, m;
    cin >> n >> m;

    vector<Query> queries(m);
    set<long> levelsSet;
    for (auto &q : queries) {
        cin >> q;
        levelsSet.insert(q.from);
        levelsSet.insert(q.to);
    }

    size_t i = 0;
    unordered_map<long, size_t> levels;
    for (const auto &l : levelsSet)
        levels[l] = i++;

    long result = manipulate(queries, levels);

    fout << result << "\n";
    fout.close();

    return 0;
}
