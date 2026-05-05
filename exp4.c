#include <stdio.h>

int main() {
    char ch;

    printf("Enter an operator: ");
    scanf("%c", &ch);

    switch(ch) {
        case '+':
            printf("Valid Arithmetic Operator: Addition (+)\n");
            break;

        case '-':
            printf("Valid Arithmetic Operator: Subtraction (-)\n");
            break;

        case '*':
            printf("Valid Arithmetic Operator: Multiplication (*)\n");
            break;

        case '/':
            printf("Valid Arithmetic Operator: Division (/)\n");
            break;

        default:
            printf("Invalid Operator\n");
    }

    return 0;
}
