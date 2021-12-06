// To print string reverse
#include <stdio.h>
#include <string.h>
void reverse(char *input, int start, int end)
{
    if (start >= end)
        return;
    char temp;
    temp = input[start];
    input[start] = input[end];
    input[end] = temp;
    reverse(input, ++start, --end);
}
int main()
{
    printf("Program written by enrollment number 200420107012\n");
    char input[100];
    printf("Enter string: ");
    scanf("%[^\n]s", input);
    reverse(input, 0, strlen(input) - 1);
    printf("Reversed string: %s\n", input);
    return 0;
}