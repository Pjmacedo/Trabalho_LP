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

Node* merge(Node* left, Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    if (left->data <= right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* mid = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        mid = mid->next;
        fast = fast->next->next;
    }

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main() {
    Node* list = NULL;

    insertAtBeginning(&list, 9);
    insertAtBeginning(&list, -2);
    insertAtBeginning(&list, 4);
    insertAtBeginning(&list, 6);
    insertAtBeginning(&list, -5);
    insertAtBeginning(&list, 1);
    insertAtBeginning(&list, -3);

    printf("Lista original: ");
    printList(list);

    list = mergeSort(list);
    printf("Lista ordenada com Merge Sort: ");
    printList(list);

    return 0;
}
