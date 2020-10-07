#include <bits/stdc++.h>

using namespace std;

/**
 * 11827 - Maximum GCD
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;

    int n;
    cin >> n;
    getline(cin, line);


    for (int t = 0; t < n; t++) {
        int size = 0;
        int arr[100];
        
        getline(cin, line);
        istringstream iss(line);
        for (int x; iss >> x; size++)
            arr[size] = x;

        int g = 1;
        for (int i = 0; i < size; i++)
            for (int j = i + 1; j < size; j++)
                g = max(g, gcd(arr[i], arr[j]));

        cout << g << "\n";
    }
}
