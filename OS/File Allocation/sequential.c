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

void allocate(int st, int size)
{
    int count = 0;
    for (int i = st; i < st + size; i++)
    {
        if (blocks[i] != 1)
        {
            count++;
        }
    }
    if (count == size)
    {
        int block_cnt = 0;
        files[fcnt].size = size;
        for (int i = st; i < st + size; i++)
        {
            blocks[i] = 1;
            files[fcnt].allocated[block_cnt] = i;
            block_cnt++;
        }
        printf("\nFile has been allocated");
        fcnt++;
    }
    else
    {
        printf("\nFile could not be allocated sequentially");
    }
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
        printf("\nEnter the name of the file : ");
        scanf("%s", &file_name);
        strcpy(files[fcnt].fname, file_name);

        printf("\nEnter the starting block : ");
        scanf("%d", &st);
        printf("\nEnter the size of the file (in blocks) : ");
        scanf("%d", &size);

        allocate(st, size);

        printf("\n\nDo you want to enter more files :\n1) YES\n2) NO\n3)Display\n");
        scanf("%d", &ch);
        if (ch == 3)
        {
            display();
        }
    } while (ch != 2);
}