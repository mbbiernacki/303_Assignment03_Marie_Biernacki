#pragma once

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

//create template class using linked list to be the basis of the Queue
template <typename T>
struct Item_Type {

	//Item_Type constructor
	T data;
	Item_Type(T data) : data(data) {}


};

template <typename T>
struct Node {

	//each node will hold nodeData of Item_Type and a pointer to the next node

	Item_Type<T> nodeData;
	Node<T>* next;

	//node constructor
	Node(const Item_Type<T>& data, Node* next_ptr = nullptr) : nodeData(data), next(next_ptr) {}

};

template<typename T>
class Queue {
	protected:
	
		//initializing head pointer, tail pointer, and num_items
		Node<T>* head;
		Node<T>* tail;
		int num_items;

public:
	Queue() : head(nullptr), tail(nullptr), num_items(0) {} //default constructor
	
	//constructor with Item_Type
	Queue(Item_Type<T> d){
		Node<T>* tempPtr = new Node<T>(d);
		head = tail = tempPtr;
		num_items = 1;
	}

	//destructor
	~Queue() {
		while (head != nullptr) {
			Node<T>* current = head;
			head = head->next;
			delete current;
		}
	
		tail = nullptr;
		num_items = 0;
	
	} 
	
	//adds node to the end of the queue
	void push(const Item_Type<T>& item) {
		
		//declare newNode
		Node<T>* newNode = new Node<T>(item);

		//if the queue was empty, both head and tail are assigned to newNode
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			//otherwise, set the tail's next pointer to newNode, reassign the tail to the newNode
			tail->next = newNode;
			tail = newNode;
		}

		num_items++; //increase num_items
		

	}
	
	//removes the first node of the queue
	void pop() {
		
		//check if the queue is empty
		if (head == nullptr) {
			cout << "ERROR: pop() called on empty queue" << endl;
		}
		else {

			//set removed_node to head, then reassign head to the next node
			Node<T>* removed_node = head;
			head = head->next;

			//after updating head to head->next, if head is now null, update tail to null
			if (head == nullptr)
				tail = nullptr;

			delete removed_node; //delete removed_node and decrease num_items
			num_items--;
		}
	}

	//returns the item at the front of the queue
	Item_Type<T>& front() {
		//check if queue is empty
		if (head == nullptr) {
			cout << "ERROR: front() called on empty queue" << endl;
		}
		else {
			return head->nodeData;
		}
	
	}

	//returns the current size of the queue
	int size() {
		return num_items;
	}
	
	//returns true if queue is empty, false if queue is not empty
	bool empty() {
		if (head == nullptr)
			return true;
		return false;
	}
	
	//takes the element at the front of the queue, moves to the rear of the queue
	void move_to_rear() {
		if (head == nullptr) {
			cout << "ERROR: move_to_rear() called on empty queue" << endl;
		}
		
		else {
			//add the data at the front to the end of the queue
			push(front().data);
			
			//remove the data at the front
			pop();
		
		}

	}


};
