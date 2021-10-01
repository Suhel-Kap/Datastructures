//3. Write a program that computes x raised to the power y.
#include<stdio.h>
#include<conio.h>

int main(){

    int x,y,ans = 1,i;
    printf("\nEnter value of x and y respectively\n");
    scanf("%d %d",&x,&y);

    if(y<0){
        printf("Value of y shouldn't be less than 0.");
        return 0;
    }

    for(i = 0; i < y;i++){
        ans=ans*x;
    }

    printf("\nx raised to the power y is %d",ans);
    getch();
    return 0;
}