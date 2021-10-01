//6. Write a program to find the maximum value from given array.

#include <stdio.h>

int main(){
    int a[20],ans,i,n;

    printf("Enter length of array \n[Note : length should be less than 20]\n");
    scanf("%d",&n);
    printf("Enter values of each  element of array consisting %d elements one by one \n",n);

    for(i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }

    ans = a[0];

    for(i = 0; i < n-1; i++){
        if(a[i+1]>a[i]){
            ans = a[i+1];
        }
    }

    printf("The maximum value from given array is %d \n",ans);
}