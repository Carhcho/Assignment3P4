#include "LinkedQueue.h"
using namespace std;

LinkedQueue::LinkedQueue()
{
	front = nullptr;
	rear = nullptr;
	size = 0;
}

LinkedQueue::~LinkedQueue()
{
	free(front);
	front = nullptr;
	free(rear);
	rear = nullptr;
}
//this method adds a employee to the LinkedQueue
void LinkedQueue::ADD(Employee a)
{
	//first create the ADDNode and assign the value on its data part and the link to null
	Node* ADDNode = new Node(a);
	ADDNode->data = a;
	ADDNode->link = nullptr;
	//Then if it is the first node on the queue meaning front will be Null then make front and rear equal to ADDNode
	if (front == nullptr) {
		front = ADDNode;
		rear = ADDNode;
		size++;
	}
	//If it is not the first element on the queue then the rear link needs to be pointing to the ADDNode and then rear needs to be equal to ADDNode so we know that this newly added Node is the rear 
	else
	{
		rear->link = ADDNode;
		rear = ADDNode;
		//and increase the size on each one to know the current size
		size++;
	}
}
//this method removes the first element following the FIFO structure
void LinkedQueue::REMOVE()
{
	if (EMPTY()) {
		cout << "Queue is already empty" << endl;
	}
	//if there is only one element in the queue then we free front and make it equal to rear and to NULL
	else if (front == rear) {
			free(front);
			front = rear = nullptr;
			size--;
	}
	//if there are more than 1 element in the queue. I created a RemoveNode to replace front and move front to the next element, then free RemovedNode to make the memory allocated free
	else
	{
		Node* RemovedNode = front;
		front = front->link;
		free(RemovedNode);
		//and reduce size for each deletion
		size--;
	}
}
//this method just count the elements by using size in ADD and REMOVE
int LinkedQueue::SIZE()
{
	cout << "#: " << size << endl;
	return size;
}
//This method will print the queue
void LinkedQueue::PRINT()
{
	if (EMPTY()) {
		cout << "Queue is already empty" << endl;
	}
	//if is not empty I created the node ptr equal to front and while is not null it will use the Employee print() method to display the objects inside moving ptr until it points to nullptr of the last element
	else
	{
		Node* ptr = front;
		while (ptr != nullptr)
		{
			ptr->data.print();
			ptr = ptr->link;
		}
	}
}
//this method is just to check if the queue is empty meaning front and rear will be equal to nullptr, I use this method on other methods to make sure there are elements in the queue.
bool LinkedQueue::EMPTY()
{
	if (front == nullptr && rear == nullptr) {
		return true;
	}
	else
	{
		return false;	
	}
}
