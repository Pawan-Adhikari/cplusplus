#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "Ram";
    char str2[] = "Shyam";
    int result = strcmp(str1, str2);

    if (result < 0) {
        printf("'%s' comes before '%s' (strcmp returned: %d)\n", str1, str2, result);
    } else if (result > 0) {
        printf("'%s' comes after '%s' (strcmp returned: %d)\n", str1, str2, result);
    } else {
        printf("'%s' is equal to '%s' (strcmp returned: %d)\n", str1, str2, result);
    }

    char str3[] = "Shyam";
    char str4[] = "Ram";
    result = strcmp(str3, str4);

    if (result < 0) {
        printf("'%s' comes before '%s' (strcmp returned: %d)\n", str3, str4, result);
    } else if (result > 0) {
        printf("'%s' comes after '%s' (strcmp returned: %d)\n", str3, str4, result);
    } else {
        printf("'%s' is equal to '%s' (strcmp returned: %d)\n", str3, str4, result);
    }
    
    char str5[] = "Apple";
    char str6[] = "Apple";
    result = strcmp(str5, str6);

    if (result < 0) {
        printf("'%s' comes before '%s' (strcmp returned: %d)\n", str5, str6, result);
    } else if (result > 0) {
        printf("'%s' comes after '%s' (strcmp returned: %d)\n", str5, str6, result);
    } else {
        printf("'%s' is equal to '%s' (strcmp returned: %d)\n", str5, str6, result);
    }

    return 0;
}
    for (i=0; i < n; i++)
    {
        for (j=1;j<i; j++)
        {
            // For ascending sort (A-Z), swap if current is greater than next
            if (strcmp(records[j].name, records[i].name) > 0)
            {

                temp_struct = records[i];
                records[i] = records[j];
                records[j] = temp_struct;
            }
        }
    }
}