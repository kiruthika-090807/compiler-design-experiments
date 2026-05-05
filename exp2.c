#include <stdio.h>
#include <string.h>

int main() {
    char line[200];
    int inMultiline = 0; // Track multi-line comment state

    printf("Enter lines of code (type 'exit' to stop):\n");

    while (1) {
        fgets(line, sizeof(line), stdin);

        // Stop condition
        if (strncmp(line, "exit", 4) == 0)
            break;

        // Check if already inside multi-line comment
        if (inMultiline) {
            printf("This line is part of a multi-line comment\n");

            // Check for end of comment
            if (strstr(line, "*/") != NULL) {
                inMultiline = 0;
            }
            continue;
        }

        // Check single-line comment
        if (strncmp(line, "//", 2) == 0) {
            printf("This is a single-line comment\n");
        }
        // Check start of multi-line comment
        else if (strstr(line, "/*") != NULL) {
            printf("Start of a multi-line comment\n");

            // If end is also in same line
            if (strstr(line, "*/") != NULL) {
                printf("Multi-line comment ends in same line\n");
            } else {
                inMultiline = 1;
            }
        }
        else {
            printf("This is NOT a comment\n");
        }
    }

    return 0;
}
