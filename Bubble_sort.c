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

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(Node* head) {
    if (head == NULL) return;

    int swapped;
    Node* ptr1;
    Node* ptr2 = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}

int main() {
    Node* list = NULL;

    insertAtBeginning(&list, -3);
    insertAtBeginning(&list, 7);
    insertAtBeginning(&list, 2);
    insertAtBeginning(&list, -5);
    insertAtBeginning(&list, 10);
    insertAtBeginning(&list, 1);
    insertAtBeginning(&list, -8);

    printf("Lista original: ");
    printList(list);

    bubbleSort(list);
    printf("Lista ordenada com Bubble Sort: ");
    printList(list);

    return 0;
}
