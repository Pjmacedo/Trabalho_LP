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

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = NULL;
    Node* curr = head;
    Node* tail = pivot;

    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if (*newHead == NULL) *newHead = curr;
            prev = curr;
            curr = curr->next;
        } else {
            if (prev) prev->next = curr->next;
            Node* temp = curr->next;
            curr->next = NULL;
            tail->next = curr;
            tail = curr;
            curr = temp;
        }
    }

    if (*newHead == NULL) *newHead = pivot;
    *newEnd = tail;

    return pivot;
}

Node* quickSortRec(Node* head, Node* end) {
    if (head == NULL || head == end) return head;

    Node* newHead = NULL;
    Node* newEnd = NULL;

    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = NULL;
        newHead = quickSortRec(newHead, temp);
        temp = newHead;
        while (temp->next != NULL) temp = temp->next;
        temp->next = pivot;
    }

    pivot->next = quickSortRec(pivot->next, newEnd);
    return newHead;
}

int main() {
    Node* list = NULL;

    insertAtBeginning(&list, -7);
    insertAtBeginning(&list, 5);
    insertAtBeginning(&list, 3);
    insertAtBeginning(&list, -2);
    insertAtBeginning(&list, 6);
    insertAtBeginning(&list, -4);
    insertAtBeginning(&list, 8);

    printf("Lista original: ");
    printList(list);

    list = quickSortRec(list, NULL);
    printf("Lista ordenada com Quick: ");
    printList(list);

    return 0;
}
