#include <stdio.h>
#include <string.h>

int main()
{
    char lhs[10], alpha[20], beta[20];

    printf("Left Recursive Production:\n");
    printf("L -> L,S | S\n\n");

    strcpy(lhs, "L");
    strcpy(alpha, ",S");
    strcpy(beta, "S");

    printf("Grammar after eliminating left recursion:\n");
    printf("%s -> %s%s'\n", lhs, beta, lhs);
    printf("%s' -> %s%s' | e\n", lhs, alpha, lhs);

    return 0;
}
