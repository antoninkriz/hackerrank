#pragma optimization_level 3
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 5000 + 1;

typedef long long ll;

struct XY {
    int x, y;

    inline constexpr XY(int x = 0, int y = 0) noexcept : x(x), y(y) {}

    inline constexpr XY operator-(const XY &xy) const noexcept {
        return {x - xy.x, y - xy.y};
    }

    inline constexpr ll operator*(const XY &xy) const noexcept {
        return ((ll) x * (ll) xy.x) + ((ll) y * (ll) xy.y);
    }
} __attribute__((aligned(8)));

short n;
short result[N_MAX];
XY points[N_MAX];

/**
 * Nezzar and Nice Beatmap
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    // Read inputs
    for (short i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
        result[i] = i;
    }

    // Bubble sort-ish magic
    // For each point after the first two
    for (short i = 3; i <= n; i++) {
        // Swap (bubble down) with each preceding point (except 1 and 2) if the dot product is negative
        // https://math.libretexts.org/Bookshelves/Calculus/Book%3A_Vector_Calculus_(Corral)/01%3A_Vectors_in_Euclidean_Space/1.03%3A_Dot_Product
        for (short j = i; j >= 3; j--) {
            if (0 < (points[j] - points[j - 1]) * (points[j - 2] - points[j - 1]))
                break;
            swap(points[j], points[j - 1]);
            swap(result[j], result[j - 1]);
        }
    }

    for (short i = 1; i <= n; i++)
        cout << result[i] << ' ';
}
