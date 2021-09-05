/*Introduction to Dynamic Memory Allocation (DMA). DMA functions malloc(), calloc(), free() etc. Write a C program for allocating memory for following using malloc(), calloc() and make it free using free()

(a) int data type (b) float data type (c) int array (d) structure variable*/

#include<stdio.h>
#include<stdlib.h>

struct student
{
  int roll;
  char name[20];
};

int main()
{
  int *id;
  float* fd;
  int* arrptr; int i,n;
  struct student* strctptr;

  printf("Program written by enrollment number 200420107012\n");


  printf("Using malloc for int datatype");
  id = (int*)malloc(sizeof(int));
  printf("\nEnter a number: ");
  scanf("%d",&*id);
  printf("The value of integer datatype : %d",*id);

  printf("\n Using calloc for int datatype ");
  id = (int*)calloc(1,sizeof(int));
  printf("\nEnter a number: ");
  scanf("%d",&*id);
  printf("The value of integer datatype : %d",*id);


  printf("\nUsing malloc for float datatype ");
  fd = (float*)malloc(sizeof(float));
  printf("\nEnter a number: ");
  scanf("%f",&*fd);
  printf("The value of float datatype : %f",*fd);

  printf("\nUsing calloc for float datatype ");
  fd = (float *)calloc(1,sizeof(float));
  printf("\nEnter a number: ");
  scanf("%f",&*fd);
  printf("The value of float datatype : %f",*fd);

  printf("\nEnter the size of the array:");
  scanf("%d",&n);
  printf("\n\nUsing malloc for array ");
  arrptr = (int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
  {
    printf("Enter element-%d: ",i+1);
    scanf("%d",arrptr+i);
  }
  printf("\nArray elements");
  for(i=0;i<n;i++)
  {
    printf("%d ",*(arrptr+i));
  }
  free(arrptr);

  printf("\n\nUsing calloc for array ");
  arrptr = (int*)calloc(n,sizeof(int));
  for(i=0;i<n;i++)
  {
    printf("Enter element-%d: ",i+1);
    scanf("%d",arrptr+i);
  }
  printf("\nArray elements");
  for(i=0;i<n;i++)
  {
    printf("%d ",*(arrptr+i));
  }
  free(arrptr);


  printf("\n\nUsing malloc for structure ");
  printf("\nEnter no of student: ");
  scanf("%d",&n);
  strctptr=(struct student *)malloc(n*sizeof(struct student));
  for(i=0;i<n;i++)
  {
    printf("\nEnter student roll_no:");
    scanf("%d",&strctptr->roll);
    printf("Enter studen-%d name:",i+1);
    scanf("%s",(strctptr+i)->name);
  }
  for(i=0;i<n;i++)
  {
    printf("\nStudent-%d",i+1);
    printf("\nroll no: %d, name : %s",(strctptr+i)->roll,(strctptr+i)->name);
  }
  printf("\n\nUsing calloc for structure ");
  printf("\nEnter no of student: ");
  scanf("%d",&n);
  strctptr=(struct student *)calloc(n,sizeof(struct student));
  for(i=0;i<n;i++)
  {
    printf("\nEnter student roll_no:");
    scanf("%d",&strctptr->roll);
    printf("Enter student-%d name:",i+1);
    scanf("%s",(strctptr+i)->name);
  }
  for(i=0;i<n;i++)
  {
    printf("\nStudent-%d",i+1);
    printf("\nroll no: %d, name : %s",(strctptr+i)->roll,(strctptr+i)->name);
  }
  free(strctptr);

  return 0;
}