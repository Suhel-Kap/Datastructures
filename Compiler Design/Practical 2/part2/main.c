#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int keywordsLength = 34;
char keywords[34][12] = {
    "auto",
    "break",
    "case",
    "char",
    "const",
    "continue",
    "default",
    "do",
    "double",
    "else",
    "else if",
    "enum",
    "extern",
    "float",
    "for",
    "goto",
    "if",
    "int",
    "long",
    "main",
    "register",
    "return",
    "short",
    "signed",
    "sizeof",
    "static	",
    "struct",
    "switch",
    "typedef",
    "union",
    "unsigned",
    "void",
    "volatile",
    "while",
};
char lexemeBreakers[16] = {',', ';', ' ', '\n', '{', '}', '[', ']', '(', ')', '+', '-', '*', '%', '/', '='};
int lexemeLength = 16;

char delimiters[10] = {',', ';', ' ', '\n', '{', '}', '[', ']', '(', ')'};
int delimiterLength = 10;

char operators[7] = {'+', '-', '*', '%', '/', '<', '>'};
int operatorLength = 7;

typedef struct
{
    char name[50];
    char datatype[20];
    int numArgs;
} SymbolTableEntry;

SymbolTableEntry symbolTable[100];

int symbolTableIndex = 0;

void addToSymbolTable(const char *name, const char *datatype, int numArgs)
{
    int i;
    for (i = 0; i < symbolTableIndex; i++)
    {
        if (strcmp(symbolTable[i].name, name) == 0)
            return;
    }
    if (symbolTableIndex < 100)
    {
        strcpy(symbolTable[symbolTableIndex].name, name);
        strcpy(symbolTable[symbolTableIndex].datatype, datatype);
        symbolTable[symbolTableIndex].numArgs = numArgs;
        symbolTableIndex++;
    }
}

void printSymbolTable(FILE *symbolTableFile)
{
    for (int i = 0; i < symbolTableIndex; i++)
    {
        fprintf(symbolTableFile, "%s %s", symbolTable[i].name, symbolTable[i].datatype);
        if (symbolTable[i].numArgs > 0)
        {
            fprintf(symbolTableFile, " %d", symbolTable[i].numArgs);
        }
        fprintf(symbolTableFile, "\n");
    }
}
bool isDelimeter(char *input)
{
    if (strlen(input) > 1)
        return false;
    int j;
    for (j = 0; j < delimiterLength; j++)
    {
        if (input[0] == delimiters[j])
            return true;
    }
    return false;
}

bool isCharDelimeter(char input)
{
    int j;
    for (j = 0; j < delimiterLength; j++)
    {
        if (input == delimiters[j])
            return true;
    }
    return false;
}

bool isKeyword(char *input)
{
    int j;
    for (j = 0; j < keywordsLength; j++)
    {
        if (strcmp(input, keywords[j]) == 0)
            return true;
    }
    return false;
}

bool isOperator(char *input)
{
    if (strlen(input) > 1)
        return false;
    int j;
    for (j = 0; j < operatorLength; j++)
    {
        if (input[0] == operators[j])
            return true;
    }
    return false;
}

bool isCharOperator(char input)
{
    int j;
    for (j = 0; j < operatorLength; j++)
    {
        if (input == operators[j])
            return true;
    }
    return false;
}

bool isLexemeBreaker(char input)
{
    int j;
    for (j = 0; j < lexemeLength; j++)
    {
        if (input == lexemeBreakers[j])
            return true;
    }
    return false;
}

void analyze(char input[], FILE *symbolTableFile)
{
    int i = 0;
    char keywordStack[30];
    bool insideFunction = false;
    int numArgs = 0;

    while (input[i] != '\0')
    {
        char currentChar = input[i];

        if (isLexemeBreaker(currentChar))
        {
            if (isCharDelimeter(currentChar))
            {
                // printf("%c : delimiter\n", currentChar);
            }
            else if (isCharOperator(currentChar))
            {
                // printf("%c : operator\n", currentChar);
            }
            i++;
        }
        else if (currentChar == ' ' || currentChar == '\t')
        {
            i++; // Skip whitespace characters
        }
        else
        {
            // Collect the entire token until a delimiter is encountered
            char tokenBuffer[50];
            int j = 0;

            while (input[i] != '\0' && !isLexemeBreaker(input[i]))
            {
                tokenBuffer[j] = input[i];
                i++;
                j++;
            }

            tokenBuffer[j] = '\0';

            if (isKeyword(tokenBuffer))
            {
                // printf("%s : keyword\n", tokenBuffer);
                strcpy(keywordStack, tokenBuffer);
            }
            else if (isOperator(tokenBuffer))
            {
                // printf("%s : operator\n", tokenBuffer);
            }
            else
            {
                // printf("%s : identifier\n", tokenBuffer);

                if (insideFunction)
                {
                    numArgs++; // Increment the argument count
                }
                printf("%d numArgs, %d insideFunc\n", numArgs, insideFunction);

                // Add the identifier to the symbol table
                addToSymbolTable(tokenBuffer, keywordStack, numArgs);

                // Check for function declaration
                if (strcmp(tokenBuffer, "(") == 0)
                {
                    printf("Function \n");
                    // Check if the previous keywordStack token is a keyword (function name)
                    if (isKeyword(keywordStack))
                    {
                        insideFunction = true;
                        numArgs = 0; // Reset argument count for the new function
                    }
                }
                else if (strcmp(tokenBuffer, ")") == 0)
                {
                    insideFunction = false; // End of function declaration
                }
            }
        }
    }
}

int main()
{
    FILE *ptr, *symbolTableFile;
    char ch[100];

    ptr = fopen("test.c", "r");
    symbolTableFile = fopen("symbol_table.txt", "w");

    if (ptr == NULL || symbolTableFile == NULL)
    {
        perror("Error opening files");
        return 1;
    }

    while (fgets(ch, sizeof(ch), ptr) != NULL)
    {
        analyze(ch, symbolTableFile);
    }

    // Print the symbol table to the symbol table file
    printSymbolTable(symbolTableFile);

    fclose(ptr);
    fclose(symbolTableFile);

    return 0;
}