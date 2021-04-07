#include <bits/stdc++.h>

using namespace std;

typedef unsigned short ush;

constexpr const ush MAX = 2000;
ush A[MAX] = {};
ush B[MAX] = {};
ush n;

inline bool sorted(const ush arr[MAX]) noexcept {
    for (ush i = 0; i < n; i++)
        if (arr[i] != i + 1)
            return false;
    return true;
}

inline void op1(ush arr[MAX]) noexcept {
    for (ush i = 0; i + 1 < n; i += 2)
        swap(arr[i], arr[i + 1]);
}

inline void op2(ush arr[MAX]) noexcept {
    for (ush i = 0; i < n / 2; i++)
        swap(arr[i], arr[i + n / 2]);
}

/*
 * King's Task
 */
int main() noexcept {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    n *= 2;

    for (ush i = 0; i < n; i++)
        cin >> A[i], B[i] = A[i];

    ush ans = -1;

    for (ush i = 0; i < n; i++) {
        if (sorted(A) || sorted(B)) {
            cout << min(i, ans);
            return 0;
        }

        if (i & 1u) {
            op1(A);
            op2(B);
        } else {
            op2(A);
            op1(B);
        }
    }

    cout << -1;

    return 0;
}
