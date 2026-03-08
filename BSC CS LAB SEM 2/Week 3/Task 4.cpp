#include <stdio.h>

int main() {
    int n, index;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter index (0 to %d): ", n - 1);
    scanf("%d", &index);

    int *ptr = arr;

    if (index >= 0 && index < n) {
        printf("Element at index %d is: %d\n", index, *(ptr + index));
    } else {
        printf("Invalid index! Please enter between 0 and %d.\n", n - 1);
    }

    return 0;
}
