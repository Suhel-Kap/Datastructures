//5. Write a calculator program(add, subtract, multiply, divide). Prepare user defined function for each functionality.

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

float add(float a, float b);
float subtract(float a, float b);
float multiply(float a, float b);
float division(float a, float b);

int main(){

    float a,b,ans;
    int o;

    printf("Enter value of two numbers on which operation is to be done.\n");
    scanf("%f %f",&a,&b);
    printf("Enter \"1\" for addition, \"2\" for subtraction, \"3\" for multiplication and \"4\" for division\n");
    scanf("%d",&o);

    if(o==1){
        ans = add(a,b);
    } else if(o==2){
        ans = subtract(a,b);
    } else if(o==3){
        ans = multiply(a,b);
    } else if(o==4){
        ans = division(a,b);
    } else{
        printf("Invalid number!\n");
    }

    printf("answer = %f \n",ans);
    
    getch();
    return 0;
}

float add(float a, float b){
    return a+b;
}

float subtract(float a, float b){
    return a-b;
}

float multiply(float a, float b){
    return a*b;
}

float division(float a, float b){
    if(b == 0){
        printf("Value of b shouldn't be zero.");
        exit(0);
    }
    return a/b;
}