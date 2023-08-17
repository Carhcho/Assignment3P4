#include "Node.h"
using namespace std;

bool isEmpty()
{
    if (front == nullptr && rear == nullptr)
        return true;
    else
        return false;
}

void ADD(Employee x)
{
    Node* ptr = front;
    ptr->data = x;
    ptr->link = nullptr;

    if (front == nullptr) {
        front = ptr;
        rear = ptr;
    }
    else {
        rear->link = ptr;
        rear = ptr;
    }
}

void REMOVE()
{
    if (isEmpty())
        cout << "Queue is empty" << endl;
    else
        if (front == rear) {
            free(front);
            front = rear = nullptr;
        }
        else {
            Node* ptr = front;
            front = front->link;
            free(ptr);
        }
}
