#include <bits/stdc++.h>

using namespace std;

int minimumSwaps(vector<int> &arr) {
    int swaps = 0;

    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == (i + 1))
            continue;

        swap(arr[i], arr[arr[i] - 1]);
        i--;
        swaps++;
    }

    return swaps;
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = minimumSwaps(arr);

    fout << res << "\n";
    fout.close();

    return 0;
}
