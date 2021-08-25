#include <stdio.h>
#include <stdlib.h>
 
struct STUDENT {
   char name[50];
   int rollNo,m1,m2,m3;
   float percentage;
};

void sort(struct STUDENT arr[], int size)
{
    int i, j;
    struct STUDENT temp;
    
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < (size - 1-i); j++)
        {
            if (arr[j].rollNo > arr[j + 1].rollNo)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            } 
        }
    }
}
void printArray(struct STUDENT arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("Name: %sRoll No: %d\nPercentage: %.2f\n", arr[i].name,arr[i].rollNo,arr[i].percentage);
    printf("\n");
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
  
  sort(student,n);
  printArray(student,n);
  
   return 0;
}
