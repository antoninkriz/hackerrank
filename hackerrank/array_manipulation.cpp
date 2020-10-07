#include <bits/stdc++.h>

using namespace std;

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n, m;
    cin >> n >> m;

    auto counter = map<int, long>();

    for (size_t i = 0; i < m; i++) {
        int a, b, k;
        cin >> a >> b >> k;

        counter[a] += k;
        counter[b + 1] -= k;
    }

    auto maxSum = 0l, tempSum = 0l;
    for (const auto &[k, v] : counter) {
        tempSum += v;
        maxSum = max(tempSum, maxSum);
    }

    fout << maxSum << "\n";
    fout.close();

    return 0;
}
