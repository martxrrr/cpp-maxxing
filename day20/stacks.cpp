/*
 ____ _____  _    ____ _  ______  
/ ___|_   _|/ \  / ___| |/ / ___| 
\___ \ | | / _ \| |   | ' /\___ \ 
 ___) || |/ ___ \ |___| . \ ___) |
|____/ |_/_/   \_\____|_|\_\____/
*/
// LIFO Data structure

#include <iostream>
class Node{
    public:
    int data;
    Node* nextLink; 

    Node(int data) : data(data), nextLink(nullptr) {}
};

class stackList{
    private:
    Node* top;
    public:
    stackList() : top(nullptr) {}
    void push(int data){
        Node* newNode = new Node(data);
        if(top == nullptr){
            top = newNode;
        }else{
            newNode->nextLink = top;
            top = newNode;
        }

        // std::cout << "Succesfully added " << data << std::endl;
    }
    void pop(){
        // std::cout << "Successfully popped " << top->data << std::endl;
        top = top->nextLink;    
     }

    void display(){
        Node* current = top;
        while(current != nullptr){
            std::cout << current->data << "  ";
            current = current->nextLink;
        }
        std::cout << "\n";
    }
};


int main(){

    stackList stack;
    stack.push(21);
    stack.push(32);
    stack.push(68);
    stack.push(54);
    stack.push(90);

    stack.display();

    return 0;
}