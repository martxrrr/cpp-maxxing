#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    char data;
    struct treeNode *left;
    struct treeNode *right;

}treeNode;

//function to create a node, allocate memory and assign values defined in the struct
//the function returns a pointer to the newly created node
treeNode* newNode(char value){
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));
    if(node != NULL){
        node->data = value;
        node->left = node->right = NULL;
    }
    return node; 
}

//manually building a tree
treeNode* buildTree(){
    treeNode *root = newNode('A'); //root node
    root->left = newNode('B'); //left child
    root->right = newNode('C'); //right child
    root->left->left = newNode('D'); // left of the right child
    root->left->right = newNode('E'); //right of the left child
    root->left->left->left = newNode('G');
    root->left->left->right = newNode('H');
    root->left->left->right->right = newNode('L');

    root->right->right = newNode('F');
    root->right->right->left = newNode('I');
    root->right->right->right = newNode('J');
    root->right->right->right->left = newNode('K');
    return root;

}

void preorderTraverse(treeNode *node){ //LNR
    if(!node){
        return;
    }
    printf("%c ", node->data); //visit
    preorderTraverse(node->left); //go left
    preorderTraverse(node->right); //go right

}

void inorderTraverse(treeNode *node){ //LNR
    if(!node){
        return;
    }
    inorderTraverse(node->left); //left
    printf("%c ", node->data); //node
    inorderTraverse(node->right); //right

}

void postOrderTraverse(treeNode *node){ //LRN
    if(!node){
        return;
    }
    postOrderTraverse(node->left); //left
    postOrderTraverse(node->right); //right
    printf("%c ", node->data); //node
}

int main(){

    treeNode *tree = buildTree();
    
    printf("Pre-order:");
    preorderTraverse(tree);

    printf("\n");
    printf("Post-order: ");
    postOrderTraverse(tree);

    printf("\n");
    printf("In-order: ");
    inorderTraverse(tree);

    printf("\n");


    return 0;
}
