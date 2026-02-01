#include <stdio.h>
#include <stdlib.h>

// Definition of a node 
struct Node {
    int data;
    struct Node *next;
};

// Insert a node at a given position (starting from 1) 
void insertAtPosition(struct Node **head, int value, int pos) {
    struct Node *newNode, *temp;
    int i;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // Insert a node at the beginning 
    if (pos == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    temp = *head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node from a given position (starting from 1) 
void deleteAtPosition(struct Node **head, int pos) {
    struct Node *temp, *prev;
    int i;

    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    // Delete the first node 
    if (pos == 1) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    temp = *head;
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display the linked list 
void display(struct Node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Main function 
int main() {
    struct Node *head = NULL;

    insertAtPosition(&head, 10, 1);
    insertAtPosition(&head, 20, 2);
    insertAtPosition(&head, 30, 3);
    display(head);

    insertAtPosition(&head, 25, 3);
    display(head);

    deleteAtPosition(&head, 2);
    display(head);

    return 0;
}
