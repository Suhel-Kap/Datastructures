#include <stdio.h>
#include <stdlib.h>
 
struct STUDENT {
   char name[50];
   int rollNo,m1,m2,m3;
   float percentage;
};
 
struct STUDENT* search3(struct STUDENT arr[],int size,int rollNo){
   int i=0;
   struct STUDENT* ptr;
   ptr = (struct STUDENT*)malloc(sizeof(struct STUDENT));
   while(arr[i].rollNo != rollNo){
       i++;
       if (i >= size){
           return ptr;
       }
   }
   return &arr[i];
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
  
  struct STUDENT* foundStudent;
  foundStudent = search3(student,n,rollNo);

  if (foundStudent->rollNo != 0)
     printf("Name: %s\nRoll Number: %d\nMarks in:\n\tm1: %d\n\tm2: %d\n\tm3: %d\nPercentage: %.2f\n",foundStudent->name,foundStudent->rollNo,foundStudent->m1,foundStudent->m2,foundStudent->m3,foundStudent->percentage);
   else
     printf("Student not found!\n");
  
   return 0;
}
