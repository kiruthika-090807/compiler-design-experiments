#include<stdio.h>
#include<string.h>

char str[20];
int i=0;

void S()
{
    if(str[i]=='a')
    {
        i++;
        if(str[i]=='a')
        {
            i++;
            if(str[i]=='b')
                i++;
            else
                i=-1;
        }
        else
            i=-1;
    }
}

int main()
{
    printf("Enter the string: ");
    scanf("%s",str);

    S();

    if(i==strlen(str))
        printf("String Accepted");
    else
        printf("String Rejected");

    return 0;
}
