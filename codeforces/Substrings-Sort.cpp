#include <bits/stdc++.h>

using namespace std;

struct cmpStrLenContent {
    bool operator()(const string &a, const string &b) {
        if (a.length() == b.length())
            return a < b;
        return a.length() < b.length();
    }
};

/**
 * Substrings Sort
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    if (n == 1) {
        string s;
        cin >> s;
        cout << "YES\n" << s;
        return 0;
    }
 
    auto db = map<string, int, cmpStrLenContent>();
 
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        db[s] += 1;
    }
 
    for (auto it = ++db.begin(); it != db.end(); it++) {
        if (it->first.find((prev(it))->first) == string::npos) {
            cout << "NO\n";
            return 0;
        }
    }
 
    cout << "YES\n";
    for (const auto &p : db) {
        for (int i = 0; i < p.second; i++)
            cout << p.first << '\n';
    }
}
