//Average_expenditure.c
//program to find the average expenditure of a company for each month of each year, each year and average over the range of years specified. 
//Use arrays to construct a table, display the table of expenditure and find the sum and average.


#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned int i,j,m,n;
    float sum=0;

    printf("Enter the first year: ");
    scanf("%u",&m);
    printf("Enter the last year: ");
    scanf("%u",&n);

    int **matrix=(int **)malloc(sizeof(int)*(n-m+1)*12);
    float *yearly_avg=(float *)malloc(sizeof(float)*12);

    int year_1 = m;
    int year_2 = n;

    for (i=0; i<(n-m+1); i++)
    {
        for (j=0; j<12; j++)
        {
            printf("Enter the average expenditure of %d th year and %d th month: ",i+1,j+1);
            scanf("%d",&matrix[i][j]);
            sum += matrix[i][j];
        }
        yearly_avg [i] = sum/12;
        sum = 0;
    }

    i = 0;
    printf("Year  Baisakh  Jestha  Asar  Shrawan  bhadau  asoj  kartik  mangsir  paush  magh  falgun  chaitra  \n");
    for (m=year_1; m<=n; m++)
    {
        printf("%d th year = ",m);
        for (j=0; j<12; j++)
        {
            printf("%d  ",matrix[i][j]);
        }
        printf("%f\n",yearly_avg[i]);
        i+=1;
    }

}
//write a program to 
