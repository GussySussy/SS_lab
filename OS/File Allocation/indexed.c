#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BLOCKS 100

int blocks[MAX_BLOCKS];

typedef struct
{
    char fname[100];
    int allocated[MAX_BLOCKS];
    int size;
} file;

file files[20];
int fcnt = 0;

int checkIndex()
{
    int index;
    printf("\nEnter the index block : ");
    scanf("%d", &index);
    if (blocks[index] != 1)
    {
        return index;
    }
    else
    {
        printf("\nCannot be allocated...Try again");
        return 0;
    }
}

void allocate(int size)
{
    int indices[size], count = 0;
    while (count < size)
    {
        int index = checkIndex();
        if (index)
        {
            indices[count] = index;
        }
        else
        {
            return;
        }
        count++;
    }
    for (int i = 0; i < size; i++)
    {
        blocks[indices[i]] = 1;
        files[fcnt].allocated[i] = indices[i];
    }
    printf("File has been Allocated");
    files[fcnt].size = size;
    fcnt++;
}

void display()
{
    printf("%s", files[0].fname);
    printf("%d", files[0].allocated[0]);
    printf("\nFile\tAllocated_to");
    for (int i = 0; i < fcnt; i++)
    {
        printf("\n%s\t", files[i].fname);
        for (int j = 0; j < files[i].size; j++)
        {
            printf("%d, ", files[i].allocated[j]);
        }
    }
}

void main()
{
    int st, size, ch;
    char file_name[100];

    do
    {
        if (ch == 1)
        {
            printf("\nEnter the name of the file : ");
            scanf("%s", &file_name);
            strcpy(files[fcnt].fname, file_name);

            printf("\nEnter the size of the file (in blocks) : ");
            scanf("%d", &size);

            allocate(size);
        }
        if (ch == 3)
        {
            display();
        }
        printf("\n\nDo you want to enter more files :\n1) YES\n2) NO\n3)Display\n");
        scanf("%d", &ch);
    } while (ch != 2);
}