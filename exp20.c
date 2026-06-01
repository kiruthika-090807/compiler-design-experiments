#include<stdio.h>
#include<ctype.h>

int main()
{
    FILE *fp;
    char ch;
    int flag = 0;

    fp = fopen("sample.c","r");

    if(fp == NULL)
    {
        printf("File not found");
        return 0;
    }

    printf("Constants are:\n");

    while((ch = fgetc(fp)) != EOF)
    {
        if(isdigit(ch))
        {
            printf("%c", ch);
            flag = 1;

            while((ch = fgetc(fp)) != EOF &&
                  (isdigit(ch) || ch == '.'))
            {
                printf("%c", ch);
            }

            printf("\n");
        }
    }

    fclose(fp);
    return 0;
}
