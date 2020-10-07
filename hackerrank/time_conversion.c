#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    int h;
    char s[10] = {0};

    scanf("%d%s", &h, s);

    if (s[6] == 'P') {
        if (h != 12)
            h = (h + 12) % 24;
    }
    else if (s[6] == 'A' && h == 12)
        h = 0;

    s[6] = 0;

    fprintf(fptr, "%.2d%s\n", h, s);

    fclose(fptr);

    return 0;
}
