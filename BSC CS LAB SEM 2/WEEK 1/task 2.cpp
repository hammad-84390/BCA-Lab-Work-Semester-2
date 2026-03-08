#include <stdio.h>
#include <string.h>

int main() {
    char str[200], word[50];
    char result[200] = "";
    char temp[200];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Enter the word to remove: ");
    scanf("%s", word);

    strcpy(temp, str);

    char *token = strtok(temp, " ");
    int first = 1;

    while (token != NULL) {
        if (strcmp(token, word) != 0) {
            if (!first) {
                strcat(result, " ");
            }
            strcat(result, token);
            first = 0;
        }
        token = strtok(NULL, " ");
    }

    printf("String after removal: \"%s\"\n", result);

    return 0;
}

