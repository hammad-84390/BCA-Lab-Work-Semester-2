#include <stdio.h>

#define SIZE 25

void createArray(int arr[], int *n);
void displayArray(int arr[], int n);
void insertElement(int arr[], int *n, int pos, int element);
void deleteElement(int arr[], int *n, int pos);

int main() {
    int arr[SIZE];
    int n = 0;
    int choice, pos, element;

    createArray(arr, &n);

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Display Array\n");
        printf("2. Insert Element\n");
        printf("3. Delete Element\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayArray(arr, n);
                break;
            case 2:
                printf("Enter position (0 to %d): ", n);
                scanf("%d", &pos);
                printf("Enter element: ");
                scanf("%d", &element);
                insertElement(arr, &n, pos, element);
                break;
            case 3:
                printf("Enter position (0 to %d): ", n-1);
                scanf("%d", &pos);
                deleteElement(arr, &n, pos);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}

void createArray(int arr[], int *n) {
    printf("Enter number of elements (max %d): ", SIZE);
    scanf("%d", n);

    if (*n > SIZE) {
        printf("Size exceeds limit. Setting to %d.\n", SIZE);
        *n = SIZE;
    }

    printf("Enter %d elements:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n) {
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertElement(int arr[], int *n, int pos, int element) {
    if (*n >= SIZE) {
        printf("Array is full. Cannot insert.\n");
        return;
    }
    if (pos < 0 || pos > *n) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos] = element;
    (*n)++;
    printf("Element inserted.\n");
}

void deleteElement(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Array is empty. Cannot delete.\n");
        return;
    }
    if (pos < 0 || pos >= *n) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i+1];
    }
    (*n)--;
    printf("Element deleted.\n");
}
