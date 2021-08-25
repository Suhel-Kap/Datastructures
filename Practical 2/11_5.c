#include <stdio.h>

struct STUDENT {
    char name[50];
    int rollNo,m1,m2,m3;
    float percentage;
};

void search1(struct STUDENT arr[],int size,int rollNo){
    int i=0;
    while(arr[i].rollNo != rollNo){
        i++;
        if (i >= size){
            printf("Roll number not found\n");
            return;
        }
    }
    printf("Percentage of student %d is %.2f\n",i+1,arr[i].percentage);
    
}


int main(){
    printf("Program written by enrollment number 200420107012\n");
    
    int n,i,rollNo;
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
    
    printf("Enter roll number of student: ");
    scanf("%d",&rollNo);
    
    search1(student,n,rollNo);
    
    return 0;
}
