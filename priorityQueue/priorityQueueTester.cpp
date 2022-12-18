/*--priorityQueueTester.cpp------------------------------------------------------------

This file is a program for testing class priorityQueue.

------------------------------------------------------------------------ - */


#include "priorityQueue.h"

    //menu prototype
	int menu();


	int main() {
		priorityQueue<string> queue1; //empty list 

		int choice,priority;
		string element,front;

		do {
			choice = menu(); //call menu method to get user choice
			switch (choice) {
			case 1: //enqueue an element
				cout << " pick value to insert" << endl;
				cin >> element;
				cout << " pick priority of the value" << endl;
				cin >> priority;
				queue1.enqueue(element, priority);
				cout << endl;
				break;

			case 2: //dequeue an element 
					queue1.dequeue();
				break;

			case 3: //display my front
				if (queue1.isEmpty()) {
					cout << "queue is empty front element is null!" << endl;
				}
				else {
					cout << "my front is: ";
					cout << queue1.front();
					cout << endl;
				}
				break;

			case 4: //display queue
				
					cout << "displaying queue: " << endl;
					cout << queue1;
					cout << endl;
				break;

			case 5: //exit program 
				cout << "\n Exiting queue" << endl;
				break;

			default: cout << "\n Invalid selection";
				break;

			}
			cout << "\n";
		} while (choice != 5); //keep showing menu if choice is not to exit
	}

	int menu() {
		int selection; //user selection
		do {
			cout << "Welcome to the Priority Queue Test program.\n"
				<< "An Empty DCList of integers has been created for you.\n"
				<< "Please choose one of the following options : \n";
			cout << "\n 1 - enqueue element\n";
			cout << "\n 2 - dequeue element \n";
			cout << "\n 3 - get front element \n";
			cout << "\n 4 - display queue \n";
			cout << "\n 5 - exit \n";
			cout << endl;
			cin >> selection;
		} while (selection < 1 || selection > 5); //keep showing menu if choice is not valid

		return selection; //return choice
	}
	
