#include <stdio.h>
#include <string.h>

int main()
{
    char prefix[20], alpha[20];

    printf("Enter common prefix: ");
    scanf("%s", prefix);

    printf("Enter remaining part after prefix: ");
    scanf("%s", alpha);

    printf("\nGrammar after Left Factoring:\n");
    printf("S -> %sS' | a\n", prefix);
    printf("S' -> %s | e\n", alpha);

    return 0;
}
