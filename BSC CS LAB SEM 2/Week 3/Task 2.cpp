#include <stdio.h>

int main() {
    int size1, size2;

    printf("Enter size of first sorted array: ");
    scanf("%d", &size1);
    printf("Enter size of second sorted array: ");
    scanf("%d", &size2);

    int arr1[size1], arr2[size2], merged[size1 + size2];

    printf("Enter %d elements of first sorted array:\n", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter %d elements of second sorted array:\n", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    int k = 0;

    for (int i = 0; i < size1; i++) {
        merged[k++] = arr1[i];
    }

    for (int j = 0; j < size2; j++) {
        merged[k++] = arr2[j];
    }

    printf("Merged Array (first array first): ");
    for (int m = 0; m < size1 + size2; m++) {
        printf("%d ", merged[m]);
    }

    return 0;
}
