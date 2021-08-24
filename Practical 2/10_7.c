#include <stdio.h>

struct STUDENT {
    char name[50];
    int rollNo,m1,m2,m3;
}s[10];

void result_rollno(int rollNo){
    int i=0;
    while(s[i].rollNo != rollNo){
      if (i==10){
        printf("Roll number not found!\n");
        return;
      }
      i++;
    }
    printf
    ("Name of student: %sRoll Number: %d\nMarks in:\n\tm1: %d\n\tm2: %d\n\tm3: %d\n",
     s[i].name, s[i].rollNo, s[i].m1, s[i].m2, s[i].m3);

}


int main(){
    printf("Program written by enrollment number 200420107012\n");
    
    int n,i,rollNo;
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
    }
    
    printf("Enter roll number to find: ");
    scanf("%d", &rollNo);

    result_rollno(rollNo);
    
    return 0;
}
