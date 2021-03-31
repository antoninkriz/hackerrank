#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MAX = 4e6;
const ll SHIFT = 1u << 22u;

// Inputs
ll inp[MAX + 1];

// dp[i] will have a legal counterpart dp[(SHIFT - 1) ^ i]
ll dp[SHIFT];

/*
 * Compatible Numbers
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    // Init DP array
    fill(dp, dp + SHIFT, -1);

    // Init inputs
    for (ll i = 1; i <= n; i++) {
        cin >> inp[i];
        dp[inp[i]] = inp[i];
    }

    // Foreach dp[i]
    for (ll i = 0; i < SHIFT; i++) {
        if (dp[i] != -1)
            continue;

        // By removing any bit set to 1 in a number the already legal/compatible numbers wont change
        for (ll j = 0; j <= 22; j++) {
            ll bitShift = 1u << j;

            // Check j-th bit && check if "i xored-th j" element is filled
            if (i & bitShift && dp[i ^ bitShift] != -1)
                dp[i] = dp[i ^ (1 << j)];
        }
    }

    // Only one solution is required, print it
    for(ll i = 1; i <= n; i++)
        cout << dp[(SHIFT - 1) ^ inp[i]] << " ";

    return 0;
}
