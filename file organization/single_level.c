#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

typedef struct
{
    char dname[10], files[10][50];
    int fcnt;
} directory;

directory dir;

void createFile()
{

    printf("\nEnter the name of the file : ");
    scanf("%s", dir.files[dir.fcnt]);

    for (int i = 0; i < dir.fcnt; i++)
    {
        if (!strcmp(dir.files[dir.fcnt], dir.files[i]))
        {
            printf("\nError : Directory cannot have files with the same name..");
            return;
        }
    }
    printf("\nFile has been created...");
    dir.fcnt++;
}

void searchFile()
{
    char fname[50];

    printf("\nEnter the name of the file : ");
    scanf("%s", fname);

    for (int i = 0; i < dir.fcnt; i++)
    {
        if (!strcmp(fname, dir.files[i]))
        {
            printf("\nFile found");
            return;
        }
    }
}

void deleteFile()
{
    char fname[50];

    printf("\nEnter the name of the file : ");
    scanf("%s", fname);

    for (int i = 0; i < dir.fcnt; i++)
    {
        if (!strcmp(fname, dir.files[i]))
        {
            printf("%s\t%s",dir.files[i],dir.files[dir.fcnt]);
            strcpy(dir.files[i], dir.files[dir.fcnt-1]);
            dir.fcnt--;
            printf("\nFile has been deleted...");
            return;
        }
    }
    printf("\nError : File to be found was not found...");
}

void display()
{
    printf("\nFiles in %s are : \n", dir.dname);
    for (int i = 0; i < dir.fcnt; i++)
    {
        printf("%s\n", dir.files[i]);
    }
}

void menu()
{
    int ch;

    while (1)
    {
        printf("\n\nWhat do you want to do :\n1)Create a File\n2)Search for a file\n3)Delete a file\n4)Display files\n5)Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createFile();
            break;
        case 2:
            searchFile();
            break;
        case 3:
            deleteFile();
            break;
        case 4:
            display();
            break;
        default:
            exit(0);
        }
    }
}

void main()
{
    printf("\nEnter name of the directory : ");
    scanf("%s", dir.dname);

    menu();
}