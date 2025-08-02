//find_c.c
//program to find the position of the character 'C' in the sentence using pointer and string.
#include<stdio.h>
#include<string.h>

int main()
{
    int i;
    char input_str[50];
    printf("Enter a string:");
    scanf("%s",input_str);


    for (i=0;i<strlen(input_str);i++)
        {
            if (*(input_str + i)=='c')
            {
                fprintf(stdout,"Character 'c' is found at index %d.",i);
            }
        }

    }