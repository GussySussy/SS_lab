#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convHex(char mask[10], char *bitmask)
{
    char value[5];
    strcpy(bitmask, "");
    for (int i = 0; i < strlen(mask); i++)
    {
        switch (mask[i])
        {
        case '0':
            strcpy(value, "0000");
            break;
        case '1':
            strcpy(value, "0001");
            break;
        case '2':
            strcpy(value, "0010");
            break;
        case '3':
            strcpy(value, "0011");
            break;
        case '4':
            strcpy(value, "0100");
            break;
        case '5':
            strcpy(value, "0101");
            break;
        case '6':
            strcpy(value, "0110");
            break;
        case '7':
            strcpy(value, "0111");
            break;
        case '8':
            strcpy(value, "1000");
            break;
        case '9':
            strcpy(value, "1001");
            break;
        case 'A':
            strcpy(value, "1010");
            break;
        case 'B':
            strcpy(value, "1011");
            break;
        case 'C':
            strcpy(value, "1100");
            break;
        case 'D':
            strcpy(value, "1101");
            break;
        case 'E':
            strcpy(value, "1110");
            break;
        case 'F':
            strcpy(value, "1111");
            break;
        default:
            strcpy(value, "");
            break;
        }
        strcat(bitmask, value);
    }
}

int length, start;
char type[5], name[10], mask[10], bitmask[20], textrec[100], address[10], l[100];
char *endptr;
long int addr;

int main()
{
    FILE *input, *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    if (input == NULL || output == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    printf("Enter the starting address of the program : ");
    scanf("%X", &start);

    fgets(textrec, sizeof(textrec), input);
    textrec[strlen(textrec) - 1] = '\0';
    char *token = strtok(textrec, "^");
    if (!strcmp(token, "H"))
    {
        strcpy(type, token);
        strcpy(name, strtok(NULL, "^"));
        addr = strtol(strtok(NULL, "^"), &endptr, 16);
        strcpy(l, strtok(NULL, "^"));
        fprintf(output, "%s^%s^%06X^%s\n", type, name, start, l);
    }

    fgets(textrec, sizeof(textrec), input);
    printf("%s", textrec);
    token = strtok(textrec, "^");
    while (strcmp(token, "E"))
    {
        if (!strcmp(token, "T"))
        {
            strcpy(type, token);
            addr = strtol(strtok(NULL, "^"), &endptr, 16);
            strcpy(l, strtok(NULL, "^"));
            strcpy(mask, strtok(NULL, "^"));
            fprintf(output, "%s^%06X^%s^%s^", type, (addr + start), l, mask);
            convHex(mask, bitmask);
            token = strtok(NULL, "^");
            printf("%s\n", token);
            for (int i = 0; i < strlen(bitmask); i++)
            {
                if (token != NULL)
                {
                    long int curr = strtol(token, &endptr, 16);
                    if (bitmask[i] == '1')
                    {
                        fprintf(output, "%X^", (curr + start));
                    }
                    else
                    {
                        fprintf(output, "%X^", curr);
                    }
                }
                else
                {
                    fprintf(output, "\n");
                    break;
                }
                token = strtok(NULL, "^");
            }
        }
        fgets(textrec, sizeof(textrec), input);
        token = strtok(textrec, "^");
    }
    if (!strcmp(token, "E"))
    {
        fprintf(output, "%s^%06x", token, start);
    }

    fclose(input);
    fclose(output);
    return 0;
}
