#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void main()
{

    FILE *optab, *symtab, *inter, *input;
    char label[10], opcode[10], operand[10], code[10], mnemonic[10];
    int start, locctr;

    optab = fopen("optab.txt", "r");
    input = fopen("input.txt", "r");
    inter = fopen("intermediate.txt", "w");
    symtab = fopen("symtab.txt", "w");
    fscanf(input, "%s\t%s\t%s", label, opcode, operand);

    if (!strcmp(opcode, "START"))
    {
        start = atoi(operand);
        locctr = start;
        fprintf(inter, "%s\t%s\n", opcode, operand);
        fscanf(input, "%s\t%s\t%s", label, opcode, operand);
    }
    else
    {
        locctr = 0;
    }

    while (strcmp(opcode, "END"))
    {
        fprintf(inter, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        if (strcmp(label, "**"))
        {
            fprintf(symtab, "%s\t%d\n", label, locctr);
        }

        fscanf(optab, "%s\t%s", code, mnemonic);
        while (strcmp(code, "END"))
        {
            if (!strcmp(opcode, code))
            {
                locctr += 3;
                break;
            }
            fscanf(optab, "%s\t%s", code, mnemonic);
        }

        if (!strcmp(opcode, "WORD"))
        {
            locctr += 3;
        }
        else if (!strcmp(opcode, "RESW"))
        {
            locctr = locctr + (atoi(operand) * 3);
        }
        else if (!strcmp(opcode, "BYTE"))
        {
            locctr++;
        }
        else if (!strcmp(opcode, "RESB"))
        {
            locctr = locctr + atoi(operand);
        }

        fscanf(input, "%s\t%s\t%s", label, opcode, operand);
    }

    fclose(input);
    fclose(symtab);
    fclose(optab);

    int length = locctr - start;
    fprintf(inter, "LENGTH\t%d", length);
    fclose(inter);
}