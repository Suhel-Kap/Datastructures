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
    char keywordStack[30];

    int i = 0;
    while (input[i] != '\0')
    {
        char currentChar = input[i];

        if (isLexemeBreaker(currentChar))
        {
                   	// printf("currentChar %c", currentChar);
            if (isCharDelimeter(currentChar))
            {
                printf("%c : delimiter\n", currentChar);
            }
            else if (isCharOperator(currentChar))
            {
                printf("%c : operator\n", currentChar);
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

                    //    printf("TokenBuffer %s\n", tokenBuffer);

            if (isKeyword(tokenBuffer))
            {
                printf("%s : keyword\n", tokenBuffer);
                int k;
                for(k = 0; k < strlen(tokenBuffer); k++){
                    printf("%c", tokenBuffer[k]);
                    keywordStack[k] = tokenBuffer[k];
                }
                printf("\n");
                keywordStack[k+1] = ' ';
                keywordStack[k+2] = '\0';
                printf("Keyword stack %s\n", keywordStack);
            }
            else if (isOperator(tokenBuffer))
            {
                printf("%s : operator\n", tokenBuffer);
            }
            else
            {
                printf("%s : identifier\n", tokenBuffer);
                fputs(keywordStack, symbolTableFile);
                tokenBuffer[j] = '\n';
                tokenBuffer[j+1] = '\0';
                fputs(tokenBuffer, symbolTableFile);
            }
        }
    }
}

void main()
{
    FILE *ptr,*symbolTableFile;
    char ch[100];

    ptr = fopen("test.c", "a+");
    symbolTableFile = fopen("symbol_table.txt", "w");

    if (NULL == ptr)
    {
        printf("File can't be opened\n");
    }
    printf("content of this file are \n");

    if (symbolTableFile == NULL)
    {
        perror("Error opening files");
        return;
    }

    while (fgets(ch, 50, ptr) != NULL)
    {
        printf("%s\n", ch);
        analyze(ch, symbolTableFile);
    }

    fclose(ptr);
    fclose(symbolTableFile);
    //    analyze("for (j = 0; j < lexemeLength; j++)");
}