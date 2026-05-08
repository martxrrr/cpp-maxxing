//=================
// BLOODY QUEUES //
//=================
// FIFO Data structure
#include <iostream>
class Node{
    public:
    int data;
    Node* nextLink;
    Node(int data) : data(data), nextLink(nullptr) {} 
};
class Queue{
    private:
    Node* head;
    Node* tail;
    int Qsize = 0;
    int MAX = 10;
    int MIN = 1;
    public:
    Queue() : tail(nullptr), head(nullptr) {}
    void enqueue(int data){ //add an element to the end of the queue
        if(Qsize < MAX){
            Node* newNode = new Node(data);
            if(tail == nullptr){ 
                head = newNode;
                tail = newNode;
            }
            else{
                tail->nextLink = newNode;
                tail = newNode;
                // std::cout << "Successfully added " << tail->data <<"\n";
            }
            Qsize += 1;
        }
        else{
            std::cout << "Queue max size reached!" << std::endl;
        }
    }
    int dequeue(){ //remove the first element from the queue and return that number
        if(Qsize >= MIN){
            int value = head->data;
            head = head->nextLink;
            Qsize -= 1;
            return value;
        }
        else{
            std::cout << "QUEUE is already empty! \n"; 
            return 0;
        }
    }
    void display(){
        Node* current = head;
        while(current != nullptr){
            std::cout << current->data << " ";
            current = current->nextLink;
        }
        std::cout << "END!" << std::endl;
    }
};
int main(){
    Queue queue;
    queue.enqueue(12);
    queue.enqueue(29);
    queue.enqueue(35);
    queue.enqueue(48);
    queue.enqueue(67);
    queue.enqueue(71);
    queue.enqueue(87);
    queue.enqueue(88);
    queue.enqueue(90);
    queue.enqueue(10);
    queue.enqueue(2);
    queue.enqueue(7);
    
    
    queue.display();

    int val = queue.dequeue();
    std::cout << "Dequeued: " << val << "\n";
    queue.display();


    return 0;
}

int x = 10;
int sum = x + 5;
// sum = 15