// 303_Assignment03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Queue.h"

#include "Functions.h"

#include <iostream>

using namespace std;

int main()
{
	/* PART 1

	//instantiate the queue with integers and push 10 values onto the queue
	//display all the elements in a queue only using the above functions
	
	Queue<int> queue; //create queue of integers

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

	//display all of the elements in the queue, only using defined functions
	for (int i = 0; i < queue.size(); i++){
		
		//create placeholder to store item at the front of the queue and print
		int element = queue.front().data;
		cout << element << " ";
		
		//remove the item at the front of the queue 
		//ensures the next value will be printed
		queue.pop();
		
		//push the original element back onto the queue 
		//ensures the queue size stays the same, therefore all values will print
		queue.push(element);
	}

	//expected output: 10, 45, 1, 7, 50, 25, 99, 40, 30, 23

	cout << endl;
	cout << "\n";

	//testing move to rear
	cout << "Testing move_to_rear()..." << endl;
	queue.move_to_rear();
	
	//display all of the elements in the queue, only using defined functions
	for (int i = 0; i < queue.size(); i++) {

		//create placeholder to store item at the front of the queue and print
		int element = queue.front().data;
		cout << element << " ";

		//remove the item at the front of the queue 
		//ensures the next value will be printed
		queue.pop();

		//push the original element back onto the queue 
		//ensures the queue size stays the same, therefore all values will print
		queue.push(element);
	}

	//expected output: 45, 1, 7, 50, 25, 99, 40, 30, 23, 10

	cout << endl;
	cout << "\n";

	*/

	//PART 2: Recursive Linear Search
	vector<string> vectorTest;

	//add values to the vector
	vectorTest.push_back("A");
	vectorTest.push_back("B");
	vectorTest.push_back("B");
	vectorTest.push_back("C");

	cout << "\n\n" << endl;
	cout << "------- TESTING LINEAR SEARCH ------" << endl;
	cout << "\nVector contains the following: " << endl;
	for (int i = 0; i < vectorTest.size(); i++) {
		cout << vectorTest[i] << " ";
	}
	cout << "\n\nTesting Linear Search with B as target..." << endl;
	
	string target = "B";

	int position = linear_search(vectorTest, target, vectorTest.size() - 1);

	cout << "The last occurrence of B in the vector is at index: " << position << endl; //expected output: 2

}
