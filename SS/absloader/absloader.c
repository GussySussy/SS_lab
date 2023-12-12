#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *input, *output;
char type[20], name[20], textrec[100];
int start, length, address, data, ptaddr;

int main()
{
    input = fopen("input.txt", "r");
    output = fopen("output2.txt", "w");

    if (input == NULL || output == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    fscanf(input, "%s %s %x %x", type, name, &address, &length);
    if (!strcmp(type, "H"))
    {
        start = address;
        ptaddr = address;
    }

    while (fscanf(input, "%s %x %x", type, &address, &length) != EOF)
    {
        if (!strcmp(type, "T"))
        {
            while (ptaddr < address)
            {
                printf("%06X\t\t%c%c\n", ptaddr, 'x', 'x');
                fprintf(output, "%06X\t\t%c%c\n", ptaddr, 'x', 'x');
                ptaddr++;
            }
            fgets(textrec, 100, input); // Read the rest of the line
            textrec[strlen(textrec) - 1] = '\0';
            char *token = strtok(textrec, " ");
            while (token != NULL)
            {
                for (int i = 0; i < strlen(token); i += 2)
                {
                    fprintf(output, "%06x\t\t%c%c\n", address, token[i], token[i + 1]);
                    printf("%06X\t\t%c%c\n", address, token[i], token[i + 1]);
                    address++;
                }
                token = strtok(NULL, " "); // Get next token
            }
            ptaddr = address;
        }
        else if (!strcmp(type, "E"))
        {
            break; // Exit the loop when "E" record is encountered
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}
