#include <stdio.h>
#include <string.h>

struct Symbol
{
    char name[20];
    char type[20];
};

struct Symbol table[100];
int count = 0;

void insert()
{
    printf("Enter Symbol Name: ");
    scanf("%s", table[count].name);

    printf("Enter Data Type: ");
    scanf("%s", table[count].type);

    count++;
    printf("Symbol Inserted Successfully!\n");
}

void display()
{
    int i;

    if(count == 0)
    {
        printf("Symbol Table is Empty\n");
        return;
    }

    printf("\nSymbol Table\n");
    printf("------------\n");
    printf("Name\tType\n");

    for(i = 0; i < count; i++)
        printf("%s\t%s\n", table[i].name, table[i].type);
}

void search()
{
    char key[20];
    int i, found = 0;

    printf("Enter Symbol to Search: ");
    scanf("%s", key);

    for(i = 0; i < count; i++)
    {
        if(strcmp(table[i].name, key) == 0)
        {
            printf("Symbol Found\n");
            printf("Name: %s\n", table[i].name);
            printf("Type: %s\n", table[i].type);
            found = 1;
            break;
        }
    }

    if(!found)
        printf("Symbol Not Found\n");
}

void deleteSymbol()
{
    char key[20];
    int i, j, found = 0;

    printf("Enter Symbol to Delete: ");
    scanf("%s", key);

    for(i = 0; i < count; i++)
    {
        if(strcmp(table[i].name, key) == 0)
        {
            for(j = i; j < count - 1; j++)
                table[j] = table[j + 1];

            count--;
            found = 1;
            printf("Symbol Deleted Successfully\n");
            break;
        }
    }

    if(!found)
        printf("Symbol Not Found\n");
}

int main()
{
    int choice;

    do
    {
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Search");
        printf("\n4. Delete");
        printf("\n5. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: insert(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: deleteSymbol(); break;
            case 5: break;
            default: printf("Invalid Choice\n");
        }
    } while(choice != 5);

    return 0;
}
