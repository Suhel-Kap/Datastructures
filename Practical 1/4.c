//4. Perform program no. 2 and 3 using function.

//2. Write a program to take two input variable from user and swap that values.
//3. Write a program that computes x raised to the power y.

#include<stdio.h>
#include<conio.h>

void swap_numbers(int *a,int *b);
int power(int x,int y);

int main(){

    int x,y,ans;
    int *p=&x,*q=&y;
    printf("\nEnter value of x and y respectively\n");
    scanf("%d %d",&x,&y);
    swap_numbers(&x,&y);
    printf("\nAfter Swaping x=%d and y=%d",x,y);
    printf("\nEnter value of x and y respectively\n");
    scanf("%d %d",&x,&y);
    ans = power(x,y);
    printf("\nx raised to the power y is %d",ans);
    getch();
    return 0;
}
void swap_numbers(int *a,int *b){

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int power(int x,int y){
    int ans=1;
    for(int i = 0; i < y;i++){
        ans=ans*x;
    }
    return ans;
}