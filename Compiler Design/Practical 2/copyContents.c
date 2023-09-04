#include <stdio.h>
#include <stdlib.h>

// Function to read character by character from source and write to destination
void copyCharacterByCharacter(FILE *source, FILE *destination) {
    char ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
}

// Function to read line by line from source and write to destination
void copyLineByLine(FILE *source, FILE *destination) {
    char line[1000];  // Assuming lines are not longer than 1000 characters
    while (fgets(line, sizeof(line), source) != NULL) {
        fputs(line, destination);
    }
}

int main() {
    FILE *sourceFile, *destFile1, *destFile2;
    char sourceFileName[] = "source.txt";
    char destFileName1[] = "output_character_by_character.txt";
    char destFileName2[] = "output_line_by_line.txt";

    // Task 1: Read the contents of one text file and write to another text file
    sourceFile = fopen(sourceFileName, "r");
    destFile1 = fopen(destFileName1, "w");
    if (sourceFile == NULL || destFile1 == NULL) {
        perror("Error opening files");
        return 1;
    }
    copyCharacterByCharacter(sourceFile, destFile1);
    fclose(sourceFile);
    fclose(destFile1);

    // Task 2: Read data character by character and write to another text file
    sourceFile = fopen(sourceFileName, "r");
    destFile2 = fopen(destFileName2, "w");
    if (sourceFile == NULL || destFile2 == NULL) {
        perror("Error opening files");
        return 1;
    }
    copyLineByLine(sourceFile, destFile2);
    fclose(sourceFile);
    fclose(destFile2);

    // Task 3: Display the contents of both text files
    printf("Contents of %s:\n", sourceFileName);
    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        return 1;
    }
    char ch;
    while ((ch = fgetc(sourceFile)) != EOF) {
        putchar(ch);
    }
    fclose(sourceFile);

    printf("\n\nContents of %s:\n", destFileName1);
    destFile1 = fopen(destFileName1, "r");
    if (destFile1 == NULL) {
        perror("Error opening destination file 1");
        return 1;
    }
    while ((ch = fgetc(destFile1)) != EOF) {
        putchar(ch);
    }
    fclose(destFile1);

    printf("\n\nContents of %s:\n", destFileName2);
    destFile2 = fopen(destFileName2, "r");
    if (destFile2 == NULL) {
        perror("Error opening destination file 2");
        return 1;
    }
    while ((ch = fgetc(destFile2)) != EOF) {
        putchar(ch);
    }
    fclose(destFile2);

    printf("\n");

    return 0;
}
