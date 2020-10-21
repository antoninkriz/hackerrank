#include <bits/stdc++.h>

using namespace std;

#define BOARD_SIZE ((10000) + 1)
#define b(x, y) board[x][y]

char board[BOARD_SIZE][BOARD_SIZE];
int nonZero = 0;

void setPlace(int x, int y) {
    b(x, y) += 1;

    if (b(x, y) == 1)
        nonZero++;
    else if (b(x, y) == 5) {
        nonZero--;

        b(x, y) = 0;

        setPlace(x - 1, y);
        setPlace(x + 1, y);
        setPlace(x, y - 1);
        setPlace(x, y + 1);
    }
}

/**
 * Yandex - Counter Complexity
 */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(board, 0, sizeof(char) * BOARD_SIZE * BOARD_SIZE);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x += 100;
        y += 100;

        setPlace(x, y);

        cout << nonZero << "\n";
    }

    return 0;
}
