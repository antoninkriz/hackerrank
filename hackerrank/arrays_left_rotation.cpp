#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the rotLeft function below.
vector<int> rotLeft(vector<int> a, int d) {
    auto v = vector<int>(a.begin() + d, a.end());
    v.insert(v.end(), a.begin(), a.begin() + d);
    return v;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> result = rotLeft(a, d);
    for (int i = 0; i < result.size(); i++)
        fout << result[i] << ((i != result.size() - 1) ? ' ' : '\n');

    fout.close();

    return 0;
}
