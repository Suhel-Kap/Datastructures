#include <stdio.h>
#include <string.h>

void push(char s[],unsigned int n,int *TOP,char x){
	if(*TOP == n-1)
	{
		printf("Stack Overflow!!\n");
		return;
	}
	else
	{
		s[++*TOP]=x;
	}
}

char pop(char s[],int *TOP)
{
	if(*TOP != -1) 
		return s[--*TOP+1];	

}

void checkPalindrome(char string[]){
	unsigned int n = strlen(string);
	if(n % 2 == 0)
	{
		printf("String is not a palindrome!!\n");
	}
	else{
		if(string[n/2]!='x')
		{
			printf("Invalid middle character!!\n");
		}
		else
		{
			int i=0;
			while(i<n){
				if(i==n/2 && string[i++]=='x')
				{	
					continue;
				}
				
				if(string[i++] == 'x' && i!=n/2)
				{
				
					printf("More than one 'x' found in the string!!\n");
					return;
				}
			
			}
			char s[20];
			char temp[n];
			int TOP=-1;
			i=0;
			while(i<n)
			{
				push(s,n,&TOP,string[i++]);
			}
			i=0;
			
			while(TOP != -1 && i<n)
			{
				temp[i++] = pop(s,&TOP);
				
			}
			!strcmp(string,temp) ? 	printf("String is a palindrome!!!\n") : printf("String is not a palindrome!!!\n");
		}
	}
	
}

int main(){
	char string[20];
  printf("Program written by enrollment number 200420107012\n");
	printf("Enter a string to check for palindrome : ");
	scanf("%s",string);
	checkPalindrome(string);
	return 0;
}
