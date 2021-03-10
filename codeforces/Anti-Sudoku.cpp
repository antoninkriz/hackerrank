#include <iostream>
 
using namespace std;
 
int n;

/*
 * Anti-Sudoku
 */
int main() noexcept {
    scanf("%d", &n);
    while ((n = fgetc(stdin)) != EOF)
        printf("%c", (char) (n == '1' ? '2' : n));
    return 0;
}
