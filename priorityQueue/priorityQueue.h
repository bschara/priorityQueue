/*-- priorityQueue.h --------------------------------------------------------

 This header file defines the data type priorityQueue for processing
 priority queues.
 Basic operations are:
   Default Constuctor
   Copy Constructor
   Assignment Operator
   Destructor
   isEmpty: checks if the queue is empty
   enqueue: modifies a queue by adding a value
   dequeue: modifies queue by removing the value at the front
   front: Accesses the top value; leaves queue unchanged
   display: output the queue
   <<: output operator
 ----------------------------------------------------------------------------*/




#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE

#include <iostream>
using namespace std;

template <typename ElementType>
class priorityQueue
{
private:
	//private class Node
	template <typename ElementType>
	class Node {
	public:
		ElementType data; //data member representing data of the node
		int priority; //data memeber representing priority of the node 
		Node* next; //pointer to the next node
		
		//class constructor
		Node(ElementType data, int priority) {
			this->data = data;
			this->next = NULL;
			if (priority > 5 || priority < 1) { //if the priority is invalid sets it
				this->priority = 1;             //to 1
			}
			else { 
				this->priority = priority;
			}
		
		}
		/*-------------------------------------------------------------------
		   Constructs a Node object
		   
		   Precondition: None
		   Postcondition: constructs a new node, data is set to value,
						  priority is set to priority and next  equal to NULL
		---------------------------------------------------------------------*/



	};
	typedef Node<ElementType>* NodePtr;
	NodePtr myBack; //data member representing back of the queue
	NodePtr myFront; //data member representing front of the queue
	int mySize; //data member representing size of the queue


public:
	priorityQueue();
	/*-----------------------------------------------------------------------
     Constructs a PriorityQueue object
  
     Precondition: None
     Postcondition: An empty queue object has been constructed;
				 mySize is equal to 0, myBack and myFront equal to NULL
    -------------------------------------------------------------------------*/

	
	priorityQueue(const priorityQueue&);
	/*-----------------------------------------------------------------------
     Constructs a copy of PriorityQueue object
     
	 Precondition: A copy of orig is needed; orig is a const reference
				parameter
     Postcondition: A copy of orig has been constructed
     -------------------------------------------------------------------------*/
	
	
	~priorityQueue();
	/*-----------------------------------------------------------------------
     Destroys a PriorityQueue object
     
	 Precondition: The life of a PriorityQueue object is over
     Postcondition: The memory dynamically allocated by the constructor
				  has been returned to the heap
     -------------------------------------------------------------------------*/

	
	priorityQueue<ElementType>& operator=(const priorityQueue<ElementType>&);
	/*-----------------------------------------------------------------------
     Assign a copy of a PriorityQueue object to the current object
     
	 Precondition: None
     Postcondition: A copy of rightHandSide has been assigned to this
				  object. A copy reference to this list is returned
     -------------------------------------------------------------------------*/



	inline bool isEmpty() const;
	/*-----------------------------------------------------------------------
     Checks if the list is empty
    
	 Precondition: None
     Postcondition: true is returned if the list is empty, false if not
    -------------------------------------------------------------------------*/
	

	bool enqueue(ElementType, int);	
	/*-----------------------------------------------------------------------
	 insert  value in a queue
	 
	 Precondition: data is to be added to this queue
	 Postcondition: value is added after the last existing element with
					  higher or equal priority
	-------------------------------------------------------------------------*/
	
	
	bool dequeue();
	/*-----------------------------------------------------------------------
	 Remove value at front of queue
	   
	 Precondition: Queue is nonempty
	 Postcondition: Value at front of queue has been removed, unless
					  queue is empty; in that case, an error message is
					  displayed and execution allowed to proceed
	-------------------------------------------------------------------------*/


	ElementType front() const;
	/*-----------------------------------------------------------------------
     Retrieve value at front of queue
     
	 Precondition: Queue is nonempty
     Postcondition: Value at front of queue is retrieved, unless the queue
				  is empty; in that case, an error message is displayed
				  and a "garbage value" is returned
     -------------------------------------------------------------------------*/


	ostream& display(ostream&) const;
	/*-----------------------------------------------------------------------
	 Display values stored in the queue
	   
	 Precondition: ostream out is open
	 Postcondition: Queue's contents, from front to back, have been
					  output to out
	-------------------------------------------------------------------------*/


};


       template <typename ElementType>
       ostream& operator<<(ostream& out, const priorityQueue<ElementType>& queue);
      /*-----------------------------------------------------------------------
	   Display values stored in the queue
	   
	   Precondition: ostream out is open
	   Postcondition: Queue's contents, from front to back, have been
					  output to out
	   -------------------------------------------------------------------------*/


	   
	   
//============== FUNCTION DEFINITIONS ===============




//--Definition of constructor
template <typename ElementType>
priorityQueue<ElementType>::priorityQueue() {

	this->mySize = 0;
	this->myBack = NULL;
	this->myFront = NULL;

};

//--Deifinition of copy constructor 
template <typename ElementType>
priorityQueue<ElementType>::priorityQueue(const priorityQueue& queue2) {
	if (!queue2.isEmpty()) {

		NodePtr temp = queue2.myFront; //copy first element of the second queue
		myFront = myBack = new Node(temp->data, temp->priority);

		temp = temp->next;
		while (temp != NULL) {
			//enqueue values from the parameter queue
			myBack->next = new Node(temp->data, temp->priority); 
			myBack = myBack->next;
			temp = temp->next;
		}
	} 
	}


//--Definition of Assignment Operator
template <typename ElementType>
priorityQueue<ElementType>& priorityQueue<ElementType>::operator=
(const priorityQueue<ElementType>& queue2) {
	if (this != &queue2) {

		this->~priorityQueue(); //delete old queue

		if (queue2.isEmpty())
			myFront = myBack = 0;

		else {
			NodePtr temp = queue2.myFront;
			//insert values of parameter queue for myback and myfront
			myFront = myBack = new Node(temp->data, temp->priority);

			temp = temp->next;
			while (temp != NULL) {
				//insert values of parameter queue
				myBack->next = new Node(temp->data, temp->priority);
				myBack = myBack->next;
				temp = temp->next;
			}
		}
	}
	return *this;

}

//--Definiton of class destructor
template <typename ElementType>
priorityQueue<ElementType>::~priorityQueue() {

	if (myFront != NULL) {
		NodePtr temp = myFront;

		while (myFront != NULL) {
			myFront = temp->next;
			delete temp;
			temp = myFront;
		}
	}
}


//--Definition of function is empty
template <typename ElementType>
inline bool priorityQueue<ElementType>::isEmpty() const {
	return (myFront == NULL || mySize == 0);
}

//--Definition of function enqueue
template <typename ElementType>
bool priorityQueue<ElementType>::enqueue(ElementType data, int priority) {
	NodePtr newNode = new Node<ElementType>(data, priority);
	if (isEmpty()) {
		myFront = newNode;
		mySize++;
		myBack = newNode;
		return true;
	}
	//check if list has only one node = myfront
	if (myFront->next == NULL) {
		if (myFront->priority >= newNode->priority) {
			myFront->next = newNode;
			myBack = newNode;
			mySize++;
			return true;
		}
		else {
			newNode->next = myFront;
			myFront = newNode;
			myBack = newNode->next;
			mySize++;
			return true;
		}
	}
	
	else {
		NodePtr temp = myFront;
		//traverse queue to reach element with smaller or equal priotrity
		while (temp->next != NULL && temp->next->priority >= newNode->priority){
			temp = temp->next;
		 }
		
		//check if we have to change myfront after new insertion (priority)
		if (myFront->priority >= newNode->priority && 
			myFront->next->priority < newNode->priority) {
			newNode->next = myFront->next;
			myFront->next = newNode;
			mySize++;
			return true;
		}
		//check if we have to insert after the last element
		if (temp->next == NULL) {
			temp->next = newNode;
			mySize++;
			myBack = newNode;
			return true;

		}

		newNode->next = temp->next;
		temp->next = newNode;
		mySize++;
		return true;
	
	}
	return false;
};

//--Definition of fucntion dequeue
template <typename ElementType>
bool priorityQueue<ElementType>::dequeue() {
	if (isEmpty()) {
		cout << "cannot dequeue queue is empty!" << endl;
		return false;
	}

	NodePtr temp = myFront;
	myFront = myFront->next;
	delete temp;
	mySize--;
	return true;

};

//--Definition of function display
template <typename ElementType>
ostream& priorityQueue<ElementType>::display(ostream& out) const {
	if (isEmpty()) {
		cout << "queue is empty!" << endl;
		return out;
	}
	NodePtr temp = myFront;
	while (temp->next != NULL) {
		out << temp->data << " -> ";
		temp = temp->next;
	}
	out << temp->data << endl;
	return out;
};

//--Definition of function front
template <typename ElementType>
ElementType priorityQueue<ElementType>::front() const{
	if (isEmpty()) {
		return NULL;
	}

	else {
		return myFront->data;
	}
};

//--Definition of overloaded << operator
template <typename ElementType>
ostream& operator<<(ostream& out, const priorityQueue<ElementType>& queue) {
	return queue.display(out);
}

#endif // !PRIOORITY_QUEUE
