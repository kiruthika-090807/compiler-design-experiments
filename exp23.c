#include <stdio.h>

int main()
{
    char str[200];
    int lineNo = 1;

    printf("Enter the program lines (type END to stop):\n");

    while (1)
    {
        fgets(str, sizeof(str), stdin);

        if (strncmp(str, "END", 3) == 0)
            break;

        printf("%d\t%s", lineNo++, str);
    }

    return 0;
}
