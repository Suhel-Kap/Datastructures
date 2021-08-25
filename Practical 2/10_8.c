#include <stdio.h>
#include <string.h>

struct STUDENT {
    char name[50];
    int rollNo,m1,m2,m3;
    float percentage;
}s[10];

void result_name(char name[50]){
    int i=0;
    int result=-1;
    while(result!=0){
        result = strcmp(s[i].name,name);
        i++;
        if (i > 10){
            printf("Name not found\n");
            return;
        }
    }
    printf("Percentage of %s\b is %.2f\n",name,s[i-1].percentage);
    
}


int main(){
    printf("Program written by enrollment number 200420107012\n");
    
    int n,i;
    char name[50];
    printf("Enter Number of students: ");
    scanf("%d",&n);
 
    for(i=0;i<n;i++){
        printf("Enter name of student: ");
        getchar();
        fgets(s[i].name,50,stdin);
        printf("Enter student rollNo: ");
        scanf("%d",&s[i].rollNo);
        printf("Enter marks m1 m2 m3 of student(out of 70): ");
        scanf("%d %d %d",&s[i].m1,&s[i].m2,&s[i].m3);
        s[i].percentage = ((s[i].m1+s[i].m2+s[i].m3)*100)/210;
    }
    
    printf("Enter name of student: ");
    getchar();
    fgets(name,50,stdin);
    // printf("%s",name);
    
    result_name(name);
    
    return 0;
}
