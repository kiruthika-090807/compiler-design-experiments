#include <stdio.h>

int main()
{
    char trailingE[][5] = {")", "id"};
    char trailingT[][5] = {")", "id"};
    char trailingF[][5] = {")", "id"};

    int i;

    printf("TRAILING(E) = { ");
    for(i = 0; i < 2; i++)
        printf("%s ", trailingE[i]);
    printf("}\n");

    printf("TRAILING(T) = { ");
    for(i = 0; i < 2; i++)
        printf("%s ", trailingT[i]);
    printf("}\n");

    printf("TRAILING(F) = { ");
    for(i = 0; i < 2; i++)
        printf("%s ", trailingF[i]);
    printf("}\n");

    return 0;
}
