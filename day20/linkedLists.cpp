//Didn't have time for SFML today, I was doing this for class assignment 
//DSA linked Lists in c++

#include <iostream>

class Node{
public:
	double data;
	Node* next;

	Node(double data) : data(data), next(nullptr) {}
};

class linkedList{
private:
	Node* head;

public:
	linkedList() : head(nullptr) {}

	void insert(double data){
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;

		// std::cout << "successfuly added " << newNode->data << "\n";
	}

	void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "END" << std::endl;
    }
};

int main(){

	linkedList list1;
	list1.insert(3.14159); //pi
	list1.insert(299712458); //c
	list1.insert(2.71828); //e
	list1.insert(9.80665); //G
	list1.insert(67.67); // 67

	list1.display();

	return 0;
}