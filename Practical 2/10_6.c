#include <stdio.h>

struct STUDENT {
    char name[50];
    int rollNo,m1,m2,m3;
}s[3];

void result(){
    int i;
    for(i=0;i<3;i++){
        if (s[i].m1 >= 23)
            printf("Student %d has passed in m1\n",i+1);
        else
            printf("Student %d has failed in m1\n",i+1);
        if (s[i].m2 >= 23)
            printf("Student %d has passed in m2\n",i+1);
        else
            printf("Student %d has failed in m2\n",i+1);
        if (s[i].m3 >= 23)
            printf("Student %d has passed in m3\n",i+1);
        else
            printf("Student %d has failed in m3\n",i+1);
        
    }
}


int main(){
    printf("Program written by enrollment number 200420107012\n");
    
    int n,i;
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
    
    result();
    
    return 0;
}
