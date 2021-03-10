#include <bits/stdc++.h>

using namespace std;

int n, i;
int input[100500];
int colorCount[100500];

/*
 * Decorate Apple Tree
 */
int main() noexcept {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (i = 0; i < n - 1; i++)
        cin >> input[i + 2];

    for (i = n; i >= 1; i--) {
        if (colorCount[i] == 0)
            colorCount[i] = 1;
        colorCount[input[i]] += colorCount[i];
    }

    sort(colorCount + 1, colorCount + n + 1);

    for (i = 1; i < n + 1; i++)
        cout << colorCount[i] << ' ';

    return 0;
}
