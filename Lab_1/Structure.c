//Structure.c
//Store and retrieve the name of the students and obtained marks in c programming in 1st semester using structure.

#include<stdio.h>

struct marks
{
    char name[30];
    int marks;
};

int main()
    {

        struct marks student_record[3];
        for (int i =0;i<3;i++)
        {
            printf("Enter the name of Student:");
            scanf("%s",student_record[i].name);
            printf("Enter marks in 'c programming:");
            scanf("%d",&student_record[i].marks);
        }

        for (int i =0;i<3;i++)
        {
            printf("The name of Student is :%s and his marks is %d/n",student_record[i].name,student_record[i].marks);
        }
    }
