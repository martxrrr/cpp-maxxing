#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// 1. Insert a node at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted %d at the beginning.\n", value);
}

// 2. Insert a node at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    
    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at the end (as head).\n", value);
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.\n", value);
}

// 3. Delete the first node
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;
    printf("Deleted first node containing %d.\n", temp->data);
    free(temp); // Free the memory of the old head
}

// 4. Delete the last node
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    // If there is only one node
    if (temp->next == NULL) {
        printf("Deleted last node containing %d.\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }
    
    // Traverse to the second-to-last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    printf("Deleted last node containing %d.\n", temp->next->data);
    free(temp->next); // Free the last node
    temp->next = NULL; // Break the link
}

// 5. Search for a value (returns true if found, false otherwise)
bool search(struct Node* head, int target) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// 6. Traverse and print the linked list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to test the implementation
int main() {
    struct Node* head = NULL; // Initialize an empty list

    // Testing Insertions
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    
    // Display list
    traverse(head);

    // Testing Search
    int target = 30;
    if (search(head, target)) {
        printf("Value %d found in the list.\n", target);
    } else {
        printf("Value %d NOT found in the list.\n", target);
    }

    // Testing Deletions
    deleteFirst(&head);
    traverse(head);

    deleteLast(&head);
    traverse(head);

    // Free remaining memory before exiting (good practice)
    while (head != NULL) {
        deleteFirst(&head);
    }

    return 0;
}