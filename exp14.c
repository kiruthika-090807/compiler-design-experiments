#include<stdio.h>
#include<string.h>

int main()
{
    char exp[20];
    int i = 0;
    char temp = 'A';

    printf("Enter Expression: ");
    scanf("%s", exp);

    printf("\nThree Address Code:\n");

    while(exp[i] != '\0')
    {
        if(exp[i] == '+' || exp[i] == '-' ||
           exp[i] == '*' || exp[i] == '/')
        {
            printf("%c = %c %c %c\n",
                   temp,
                   exp[i-1],
                   exp[i],
                   exp[i+1]);

            exp[i+1] = temp;
            temp++;
        }
        i++;
    }

    return 0;
}
