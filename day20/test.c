#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next

}Node;

Node* newNode(  int value ){
    Node *n = (Node*)malloc(sizeof(Node));
    n->data = value;
    n->next = NULL;

    return n;
}

Node* insertFront(Node* head, int value){
    Node* n = newNode(value);
    n->next = head;
    return n;
}

Node* insertEnd(Node* head, int value){
    Node* n = newNode(value);
    if(!head){
        return n;
    }
    Node* current = head;
    while(current->next){
        current = current->next;
        current->next = n;
    }
    return head;
}

// Delete the first node with value val — O(n)
Node* deleteNode(Node *head, int val) {
    if (!head) return NULL;

    if (head->data == val) {
        Node *tmp = head->next;

        free(head);
        return tmp;
    }


    Node *cur = head;
    while (cur->next && cur->next->data != val)
    cur = cur->next;
    if (cur->next) {
        Node *del = cur->next;
        cur->next = del->next;
        free(del);
    }
    return head;
}
// Print all nodes
void printList(Node *head) {
 while (head) {
 printf("%d -> ", head->data);
 head = head->next;
 }
 printf("NULL\n");
}
int main() {
 Node *head = NULL;
 head = insertEnd(head, 1);
 

 head = insertEnd(head, 7);
 head = insertEnd(head, 3);
 head = insertFront(head, 9);
 printList(head); // 9 -> 1 -> 7 -> 3 -> NULL
 head = deleteNode(head, 7);
 printList(head); // 9 -> 1 -> 3 -> NULL
 return 0;
}