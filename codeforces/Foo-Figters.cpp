#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll

#define MN 300000

int n;
int valPos[MN];
int valNeg[MN];
ull mask[MN];

int *val;
ll sum = 0;
ull ans = 0;

/*
 * Foo Fighters
 */
int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    // Read input
    for (int i = 0; i < n; i++) {
        cin >> valPos[i] >> mask[i];
        valNeg[i] = -valPos[i];
        sum += valPos[i];
    }

    // Select an array with a positive sum
    val = sum < 0 ? valNeg : valPos;

    // Iterate through each bit position
    // Since we're checking bit masks we have to only try numbers (masks) like b0001, b0011, b0111, b1111, ...
    for (ull k = 1; k < (1llu << 63u); k <<= 1u) {
        sum = 0;

        // Try it for all numbers (masks)
        for (int i = 0; i < n; i++) {
            // Check if the mask is in a range of [ 2^k , 2^(k+1) ), if the number of 1s in the "ans & mask" is even add -val or val otherwise
            if (k <= mask[i] && mask[i] < (k << 1u))
                sum += ((unsigned) __builtin_popcountll(ans & mask[i]) & 1llu) ? val[i] : -val[i];
        }

        // Set k-bit in the answer (0001 | k=š -> 0101, ...)
        if (sum < 0)
            ans |= k;
    }

    cout << ans;
    return 0;
}
