#include <stdio.h>

int main() {
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *ptr = arr;

    printf("Array elements using pointer traversal:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(ptr + i));
    }

    return 0;
}
