#include <stdio.h>
#include <stdlib.h>

struct element {
    int data;
    struct element* next;
    struct element* prev;
};

struct element* head = NULL;

struct element* createElement(int data) {
    struct element* newElement = (struct element*)malloc(sizeof(struct element));
    if (newElement == NULL) {
        printf("Memory full!\n");
        exit(0);
    }
    newElement->data = data;
    newElement->next = NULL;
    newElement->prev = NULL;
    return newElement;
}

void createList(int n) {
    struct element* temp;
    head = NULL; 
    int data;
    for (int i = 1; i <= n; i++) {
        printf("Enter data for element %d: ", i);
        scanf("%d", &data);
        struct element* newElement = createElement(data);
        if (head == NULL) {
            head = newElement;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newElement;
            newElement->prev = temp;
        }
    }
}


void insertAtBeginning(int data) {
    struct element* newElement = createElement(data);
    if (head == NULL) {
        head = newElement;
        return;
    }
    newElement->next = head;
    head->prev = newElement;
    head = newElement;
}

void insertAtEnd(int data) {
    struct element* newElement = createElement(data);
    if (head == NULL) {
        head = newElement;
        return;
    }
    struct element* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newElement;
    newElement->prev = temp;
}

void insertAtPosition(int data, int pos) {
    if (pos == 1) {
        insertAtBeginning(data);
        return;
    }
    struct element* newElement = createElement(data);
    struct element* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    newElement->next = temp->next;
    newElement->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newElement;
    temp->next = newElement;
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct element* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct element* temp = head;
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if (pos == 1) {
        deleteAtBeginning();
        return;
    }
    struct element* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
}

void traverse() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct element* temp = head;
    printf("List (forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, pos, n;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many elements to create? ");
                scanf("%d", &n);
                createList(n);
                break;

            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Where to insert? 1-Beginning 2-Middle 3-End: ");
                scanf("%d", &pos);
                if (pos == 1)
                    insertAtBeginning(data);
                else if (pos == 2) {
                    int position;
                    printf("Enter position to insert: ");
                    scanf("%d", &position);
                    insertAtPosition(data, position);
                } else if (pos == 3)
                    insertAtEnd(data);
                else
                    printf("Invalid choice!\n");
                break;

            case 3:
                printf("Where to delete? 1-Beginning 2-Middle 3-End: ");
                scanf("%d", &pos);
                if (pos == 1)
                    deleteAtBeginning();
                else if (pos == 2) {
                    int position;
                    printf("Enter position to delete: ");
                    scanf("%d", &position);
                    deleteAtPosition(position);
                } else if (pos == 3)
                    deleteAtEnd();
                else
                    printf("Invalid choice!\n");
                break;

            case 4:
                traverse();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
