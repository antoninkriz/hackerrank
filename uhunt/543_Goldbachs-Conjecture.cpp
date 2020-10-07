#include <bits/stdc++.h>

using namespace std;

set<int> sieve() {
    static constexpr const int n = 1000000;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    auto res = set<int>();
    for (int p = 2; p <= n; p++)
        if (prime[p])
            res.insert(p);

    return res;
}

/**
 * 543 - Goldbach's Conjecture
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto primes = sieve();

    while (true) {
        int n;
        cin >> n;

        if (!n)
            break;

        for (const auto &p : primes) {
            if (primes.count(n - p)) {
                cout << n << " = " << p << " + " << n - p << "\n";
                break;
            }
        }
    }

    return 0;
}
