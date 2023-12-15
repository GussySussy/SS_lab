#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

typedef struct
{
    char dname[10], files[10][50];
    int fcnt;
} directory;

directory dir[10];
int dcnt = 0;

void createDir()
{
    printf("\nEnter the name of the directory : ");
    scanf("%s", dir[dcnt].dname);

    for (int i = 0; i < dcnt; i++)
    {
        if (!strcmp(dir[dcnt].dname, dir[i].dname))
        {
            printf("\nError : Directories cannot have same name..");
            return;
        }
    }
    printf("\nDirectory has been created...");
    dcnt++;
}

void createFile()
{

    char dir_name[50];

    printf("\nEnter the name of the directory : ");
    scanf("%s", dir_name);

    for (int i = 0; i < dcnt; i++)
    {
        if (!strcmp(dir_name, dir[i].dname))
        {
            printf("directory found");
            printf("\nEnter the name of the file : ");
            scanf("%s", dir[i].files[dir[i].fcnt]);

            for (int j = 0; i < dir[i].fcnt; j++)
            {
                if (!strcmp(dir[i].files[dir[i].fcnt], dir[i].files[j]))
                {
                    printf("\nError : Directory cannot have files with the same name..");
                    return;
                }
            }
            printf("\nFile has been created...");
            dir[i].fcnt++;
            return;
        }
    }
    printf("\nDirectory not found...");
}

void searchFile()
{
    char fname[50];

    printf("\nEnter the name of the file : ");
    scanf("%s", fname);

    for (int i = 0; i < dcnt; i++)
    {
        for (int j = 0; j < dir[i].fcnt; j++)
        {
            if (!strcmp(fname, dir[i].files[j]))
            {
                printf("\nFile found");
                return;
            }
        }
    }

    printf("\nFile not found...");
}

void deleteFile()
{
    char dirName[50], fileName[50];

    printf("\nEnter the name of the directory : ");
    scanf("%s", dirName);

    for (int i = 0; i < dcnt; i++)
    {
        if (!strcmp(dirName, dir[i].dname))
        {
            printf("\nDirectory found");
            printf("\nEnter the name of the file : ");
            scanf("%s", fileName);

            for (int j = 0; j < dir[i].fcnt; j++)
            {
                if (!strcmp(fileName, dir[i].files[j]))
                {
                    strcpy(dir[i].files[j], dir[i].files[dir[i].fcnt]);
                    dir[i].fcnt--;
                    printf("\nFile has been deleted...");
                    return;
                }
            }

            printf("\nFile not found in the directory...");
            return;
        }
    }
    printf("\nDirectory not found...");
}

void display()
{
    for (int i = 0; i < dcnt; i++)
    {
        printf("\nFiles in %s : \n", dir[i].dname);
        for (int j = 0; j < dir[i].fcnt; j++)
        {
            printf("%s\t", dir[i].files[j]);
        }
    }
}

void menu()
{
    int ch;

    while (1)
    {
        printf("\n\nWhat do you want to do :\n1)Create a directory\n2)Create a File\n3)Search for a file\n4)Delete a file\n5)Display files\n6)Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createDir();
            break;
        case 2:
            createFile();
            break;
        case 3:
            searchFile();
            break;
        case 4:
            deleteFile();
            break;
        case 5:
            display();
            break;
        default:
            exit(0);
        }
    }
}

void main()
{
    menu();
}

