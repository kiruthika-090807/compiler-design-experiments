#include <stdio.h>

int main()
{
    FILE *fp;
    char ch;
    int insideTag = 0;

    fp = fopen("sample.html", "r");

    if (fp == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF)
    {
        if (ch == '<')
        {
            insideTag = 1;
        }

        if (insideTag)
        {
            printf("%c", ch);
        }

        if (ch == '>')
        {
            insideTag = 0;
            printf("\n");
        }
    }

    fclose(fp);
    return 0;
}
