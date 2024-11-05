#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertionSort(Node** head) {
    if (*head == NULL) return;

    Node* sorted = NULL;
    Node* current = *head;

    while (current != NULL) {
        Node* next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }

    *head = sorted;
}

int main() {
    Node* list = NULL;

    insertAtBeginning(&list, -4);
    insertAtBeginning(&list, 8);
    insertAtBeginning(&list, 5);
    insertAtBeginning(&list, -1);
    insertAtBeginning(&list, 3);
    insertAtBeginning(&list, -10);

    printf("Lista original: ");
    printList(list);

    insertionSort(&list);
    printf("Lista ordenada com Insertion Sort: ");
    printList(list);

    return 0;
}
