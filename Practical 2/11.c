#include <stdio.h>
#include <string.h>

struct STUDENT {
    char name[50];
    int rollNo,m1,m2,m3;
    float percentage;
};

void result_name(struct STUDENT arr[],int size,char name[50]){
    int i=0;
    int result=-1;
    while(result!=0){
        result = strcmp(arr[i].name,name);
        i++;
        if (i > size){
            printf("Name not found\n");
            return;
        }
    }
    printf("Percentage of %s\b is %.2f\n",name,arr[i-1].percentage);
    
}


int main(){
    printf("Program written by enrollment number 200420107012\n");
    
    int n,i;
    char name[50];
    printf("Enter Number of students: ");
    scanf("%d",&n);
    
    
    struct STUDENT student[n];
    for(i=0;i<n;i++){
        printf("Enter name of student: ");
        getchar();
        fgets(student[i].name,50,stdin);
        printf("Enter student rollNo: ");
        scanf("%d",&student[i].rollNo);
        printf("Enter marks m1 m2 m3 of student(out of 70): ");
        scanf("%d %d %d",&student[i].m1,&student[i].m2,&student[i].m3);
        student[i].percentage = ((student[i].m1+student[i].m2+student[i].m3)*100)/210;
    }
    
    printf("Enter name of student: ");
    getchar();
    fgets(name,50,stdin);
    // printf("%s",name);
    
    result_name(student,n,name);
    
    return 0;
}
