#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], result[200];
    char choice;
    int i, len;

    
    printf("Enter the first string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0'; 

    printf("Enter the second string: ");
    fgets(str2, sizeof(str2), stdin);
    str2[strcspn(str2, "\n")] = '\0'; 

  
    printf("\nChoose operation:\n");
    printf("a) Addition (Concatenate strings)\n");
    printf("b) Copy first string into result\n");
    printf("c) Reverse first string\n");
    printf("d) Length of first string\n");
    printf("Enter choice (a/b/c/d): ");
    scanf(" %c", &choice);

    switch(choice) {
        case 'a': 
            strcpy(result, str1);  
            strcat(result, str2);   
            printf("Result after addition: %s\n", result);
            break;

        case 'b':
            strcpy(result, str1);
            printf("Result after copying: %s\n", result);
            break;

        case 'c': 
            len = strlen(str1);
            for(i = 0; i < len; i++) {
                result[i] = str1[len - 1 - i];
            }
            result[len] = '\0';
            printf("Reversed string: %s\n", result);
            break;

        case 'd':
            len = strlen(str1);
            printf("Length of first string: %d\n", len);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

