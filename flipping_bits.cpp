#pragma GCC optimize ("O3")

#include <fstream>
#include <iostream>

using std::cin;
using std::ofstream;

int main()
{
    unsigned int q, q_itr, n;
    ofstream fout(getenv("OUTPUT_PATH"));

    cin >> q;
    for (q_itr = 0; q_itr < q; ++q_itr) {
        cin >> n;
        fout << ~n << "\n";
    }
}
