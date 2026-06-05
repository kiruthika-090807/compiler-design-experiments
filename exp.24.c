#include <stdio.h>

int main()
{
    FILE *fp1, *fp2;
    char ch, next;
    int comments = 0;

    fp1 = fopen("input.c", "r");
    fp2 = fopen("output.c", "w");

    if(fp1 == NULL)
    {
        printf("Input file not found\n");
        return 0;
    }

    while((ch = fgetc(fp1)) != EOF)
    {
        if(ch == '/')
        {
            next = fgetc(fp1);

            if(next == '/')
            {
                comments++;
                while((ch = fgetc(fp1)) != '\n' && ch != EOF);
                fputc('\n', fp2);
            }
            else if(next == '*')
            {
                comments++;
                while((ch = fgetc(fp1)) != EOF)
                {
                    if(ch == '*')
                    {
                        next = fgetc(fp1);
                        if(next == '/')
                            break;
                    }
                }
            }
            else
            {
                fputc(ch, fp2);
                fputc(next, fp2);
            }
        }
        else
        {
            fputc(ch, fp2);
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("Number of comments = %d\n", comments);
    printf("Comments removed and written to output.c\n");

    return 0;
}
