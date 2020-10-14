#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

inline constexpr ull intPow(ull base, ull exp) noexcept {
    ull res = 1;

    while (true) {
        if (exp & 1u)
            res *= base;
        exp >>= 1u;
        if (!exp)
            break;
        base *= base;
    }

    return res;
}

inline constexpr void swap(ull *a, ull *b) {
    ull tmp = *a;
    *a = *b;
    *b = tmp;
}

template<int width>
struct ConstArr {
    static constexpr const ull size = intPow(2, width + 1);

    ull arr[size];
    ull arrLeft[size] = {0}, arrRight[size] = {0};

    size_t memSize = sizeof(arr) / sizeof(arr[0]);
    size_t pos = 0;

    constexpr void merge(int l, int m, int r) noexcept {
        int nl = m - l + 1;
        int nr = r - m;

        for (int i = 0; i < nl; i++)
            arrLeft[i] = arr[l + i];

        for (int j = 0; j < nr; j++)
            arrRight[j] = arr[m + 1 + j];

        int i = 0, j = 0, k = l;

        while (i < nl && j < nr) {
            if (arrLeft[i] <= arrRight[j]) {
                arr[k] = arrLeft[i];
                i++;
            } else {
                arr[k] = arrRight[j];
                j++;
            }
            k++;
        }

        while (i < nl) {
            arr[k] = arrLeft[i];
            i++;
            k++;
        }

        while (j < nr) {
            arr[k] = arrRight[j];
            j++;
            k++;
        }
    }

    constexpr void mergeSort(int l, int r) noexcept {
        if (l < r) {
            int m = l + (r - l) / 2;
            mergeSort(l, m);
            mergeSort(m + 1, r);
            merge(l, m, r);
        }
    }

    constexpr void newNum(ull prev, ull depth) noexcept {
        if (depth == width)
            return;

        if (pos == size - 1)
            return;

        ull nextA = 3 * intPow(10, depth) + prev;
        ull nextB = 8 * intPow(10, depth) + prev;

        arr[pos++] = nextA;
        arr[pos++] = nextB;

        newNum(nextA, depth + 1);
        newNum(nextB, depth + 1);
    }


    constexpr ConstArr() : arr() {
        newNum(0, 0);
        mergeSort(0, size - 1);
    }
};

static constexpr const ConstArr<9> car = ConstArr<9>();
ull a, b, res;

/**
 * Special Salads
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> a >> b;

    auto x = upper_bound(car.arr, car.arr + car.memSize, a - 1);
    auto y = upper_bound(car.arr, car.arr + car.memSize, b);

    res = *x * ((*x - a) + 1);

    while (true) {
        auto curr = *x;
        auto next = *(++x);

        if (next >= *y) {
            x--;
            break;
        }

        res += (next - curr) * next;
    }

    res += *y * (b - *x);

    cout << res << "\n";
    return 0;
}
