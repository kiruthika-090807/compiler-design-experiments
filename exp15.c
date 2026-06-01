#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    char ch;
    int characters = 0, words = 0, lines = 1;

    fp = fopen("input.txt", "r");

    if(fp == NULL)
    {
        printf("File not found");
        return 1;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        characters++;

        if(ch == ' ' || ch == '\t' || ch == '\n')
            words++;

        if(ch == '\n')
            lines++;
    }

    fclose(fp);

    printf("Characters = %d\n", characters);
    printf("Words = %d\n", words + 1);
    printf("Lines = %d\n", lines);

    return 0;
}
