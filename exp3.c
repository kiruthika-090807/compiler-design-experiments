#include <stdio.h>
#include <ctype.h>

#define MAX 50

// Function to check operators
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '%');
}

int main() {
    char input[1000], token[MAX];
    int i = 0, j;

    printf("Enter source code:\n");
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {

        // ?? Ignore whitespace
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // ?? Ignore single-line comment
        if (input[i] == '/' && input[i + 1] == '/') {
            while (input[i] != '\n' && input[i] != '\0')
                i++;
            continue;
        }

        // ?? Ignore multi-line comment
        if (input[i] == '/' && input[i + 1] == '*') {
            i += 2;
            while (!(input[i] == '*' && input[i + 1] == '/') && input[i] != '\0')
                i++;
            i += 2;
            continue;
        }

        // ?? ????? Identifier
        if (isalpha(input[i]) || input[i] == '_') {
            j = 0;
            while (isalnum(input[i]) || input[i] == '_') {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Identifier: %s\n", token);
            continue;
        }

        // ?? ????? Constant
        if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';
            printf("Constant: %s\n", token);
            continue;
        }

        // ?? ????? Operator
        if (isOperator(input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
            continue;
        }

        // Ignore everything else
        i++;
    }

    return 0;
}
