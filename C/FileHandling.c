//Filehandling.c
//to read name, rollno, address, and phone number of each student in your class using structure. 
//Store the information in file so that you can recover the information later. 
//While recovering the information from the file sort the information alphabetically according to the name.

#include<string.h>
#include<stdio.h>
FILE *file_ptr;
struct data
{
    char name[20];
    unsigned int roll;
    char add[30];
    unsigned int num;
}temp_struct;

int main()
{   
    int n,i,j;
    char temp_str[20];
    printf("Enter the number of students you want to keep record of: ");
    scanf("%d",&n);
    struct data records[n];
    for (i=0;i<n;i++)
    {
        printf("Enter the name:");
        scanf("%s",records[i].name);
        printf("Enter the address:");
        scanf("%s",records[i].add);
        printf("Enter the roll number:");
        scanf("%u",&records[i].roll);
        printf("Enter the number:");
        scanf("%u",&records[i].num);
    }

    file_ptr = fopen("New_file.txt","w");

    fwrite(records,sizeof(struct data),n,file_ptr);

    fclose(file_ptr);

    file_ptr = fopen("New_file.txt","r");
    if (file_ptr == NULL) { // Added error check for fopen
        printf("Error opening file for reading!\n");
        return 1; // Indicate an error
    }

    fread(records, sizeof(struct data),n,file_ptr);
    fclose(file_ptr); // Close the file after reading

    // Bubble sort for ascending order (A-Z)
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
        if (strcmp(records[j].name, records[j + 1].name) > 0) {
            temp_struct = records[j];
            records[j] = records[j + 1];
            records[j + 1] = temp_struct;
        }
    }
}


    printf("\nSorted Student Records:\n"); 
    for (i=0;i<n;i++)
    {
        printf("Name: %s, Address: %s, Roll: %u, Phone: %u.\n",records[i].name, records[i].add, records[i].roll, records[i].num);
    }
    return 0; 
}
