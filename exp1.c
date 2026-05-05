#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '%');
}

int main() {
    char input[1000], token[MAX];
    int i = 0, j = 0;

    printf("Enter source code:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {

        // Ignore whitespace
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Handle single-line comments (//)
        if (input[i] == '/' && input[i + 1] == '/') {
            while (input[i] != '\n' && input[i] != '\0')
                i++;
            continue;
        }

        // Handle multi-line comments (/* */)
        if (input[i] == '/' && input[i + 1] == '*') {
            i += 2;
            while (!(input[i] == '*' && input[i + 1] == '/') && input[i] != '\0')
                i++;
            i += 2;
            continue;
        }

        // ????? Identifiers
        if (isalpha(input[i]) || input[i] == '_') {
            j = 0;
            while (isalnum(input[i]) || input[i] == '_') {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Identifier: %s\n", token);
            continue;
        }

        // ????? Constants (numbers)
        if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Constant: %s\n", token);
            continue;
        }

        // ????? Operators
        if (isOperator(input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
            continue;
        }

        // Ignore other characters
        i++;
    }

    return 0;
}
