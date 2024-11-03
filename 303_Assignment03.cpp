//CS303 ASSIGNMENT 03: Queue, Linear Search, and Insertion Sort
//NAME: Marie Biernacki
//CREATED: November 3rd 2024
//DUE: November 7th 2024

#include "Queue.h"
#include "Functions.h"

#include <iostream>

using namespace std;

int main()
{
	//PART 1: create a Queue using linked list as base, display elements using given functions
	
	cout << "------- TESTING QUEUE ------" << endl;

	Queue<int> queue; //create queue of integers

	cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << endl; //expected: yes

	//push 10 values onto the queue
	queue.push(10);
	queue.push(45);
	queue.push(1);
	queue.push(7);
	queue.push(50);
	queue.push(25);
	queue.push(99);
	queue.push(40);
	queue.push(30);
	queue.push(23);


	
	cout << "\nElements in queue:" << endl;

	queue.displayQueue();
	//expected output: 10, 45, 1, 7, 50, 25, 99, 40, 30, 23

	cout << "\n\nIs the queue empty? " << (queue.empty() ? "Yes" : "No") << endl; //expected: no

	cout << endl;

	//testing move to rear
	cout << "Testing move_to_rear()..." << endl;
	queue.move_to_rear();
	cout << "\nElements in queue:" << endl;

	queue.displayQueue();
	//expected output: 45, 1, 7, 50, 25, 99, 40, 30, 23, 10

	cout << endl;
	cout << "\n";

	

	//PART 2: Recursive Linear Search
	vector<string> vectorTest;

	//add values to the vector
	vectorTest.push_back("A");
	vectorTest.push_back("B");
	vectorTest.push_back("B");
	vectorTest.push_back("C");

	cout << "\n------- TESTING LINEAR SEARCH ------" << endl;
	cout << "Vector contains the following: " << endl;
	for (int i = 0; i < vectorTest.size(); i++) {
		cout << vectorTest[i] << " ";
	}
	cout << "\n\nTesting Linear Search with B as target..." << endl;
	
	string target = "B";

	int position = linear_search(vectorTest, target, vectorTest.size() - 1);

	cout << "The last occurrence of B in the vector is at index: " << position << endl; //expected output: 2




	//PART 3: Insertion Sort on Queue of Integers
	cout << "\n\n------- TESTING ASCENDING INSERTION SORT ON QUEUE ------" << endl;

	cout << "Current Queue: " << endl;
	
	
	queue.displayQueue();
	//expected output: 45, 1, 7, 50, 25, 99, 40, 30, 23, 10



	//call insertion_sort
	queue.insertion_sort();

	cout << "\n\nQueue After Inserton Sort: " << endl;

	queue.displayQueue();
	//expected output: 1, 7, 10, 23, 25, 30, 40, 45, 50, 99

	cout << "\n\n";

}
