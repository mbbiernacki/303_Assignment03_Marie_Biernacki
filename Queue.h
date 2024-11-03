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

	void displayQueue() {
		
		if (empty()) {
			cout << "ERROR: displayQueue() called on empty queue" << endl;
			return;
		}

		for (int i = 0; i < size(); i++) {

			//create placeholder to store item at the front of the queue and print
			int element = front().data;
			cout << element << " ";

			//remove the item at the front of the queue 
			//ensures the next value will be printed
			pop();

			//push the original element back onto the queue 
			//ensures the queue size stays the same, therefore all values will print
			push(element);
		}
	
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
	

	//sorts a given queue in ascending order
	void insertion_sort() {
		
		if (empty()) {
			cout << "ERROR: insertion_sort() called on empty queue." << endl;
			return;
		}

		//queue to store sorted elements
		Queue<T> sortedQueue;

		//while loop to process each element in the original queue
		while (!empty()) {
			//set the top item in the queue to key and remove
			T key = front().data;
			pop();

			bool inserted = false;

			//temporary queue to hold elements while finding the insertion spot
			Queue<T> tempQueue;

			//loop through the sortedQueue if it is not empty
			while (!sortedQueue.empty()) {
				//if insertion is false and the key is less than the front of the sortedQueue
				if (!inserted && key < sortedQueue.front().data) {
					
					tempQueue.push(Item_Type<T>(key)); //add key to the tempQueue
					inserted = true; // set insertion to true (an element was inserted)
				}
				
				tempQueue.push(sortedQueue.front()); //move the front of sortedQueue to tempQueue
				sortedQueue.pop(); //remove the front from sortedQueue
			}

			//if key is the largest, add it at the end of tempQueue
			if (!inserted) {
				tempQueue.push(Item_Type<T>(key));
			}

			//move all elements back from tempQueue to sortedQueue
			while (!tempQueue.empty()) {
				sortedQueue.push(tempQueue.front());
				tempQueue.pop();
			}
		}

		//after the sortedQueue is done, add the elements back to the original queue
		while (!sortedQueue.empty()) {
			push(sortedQueue.front());
			sortedQueue.pop();
		}

	}
	
};
