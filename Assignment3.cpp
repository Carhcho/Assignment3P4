// Assignment3.cpp : Cesar Roncancio
//

#include <iostream>
#include <fstream>
#include "Employee.h"
#include "LinkedQueue.h"
using namespace std;

void readFile(LinkedQueue&);
void enQueueEmp(LinkedQueue&);

int main()
{
    Employee Cesar(100, "Cesar", "Roncancio", 5);
    Employee Emily(200, "Emily", "Siemons", 10);
    Employee Daron(300, "Daron", "Roncancio", 1);

    LinkedQueue employeeQueue;
   
    cout << "Adding elements to the Queue ..." << endl;
    readFile(employeeQueue);
    cout << "What is the Queue size? " << endl;
    employeeQueue.SIZE();
    cout << "Printing the Queue: " << endl;
    employeeQueue.PRINT();
    cout << "Add a New employee to the Queue:" << endl;
    enQueueEmp(employeeQueue);
    cout << "Printing the Queue: " << endl;
    employeeQueue.PRINT();
    cout << "What is the Queue size? " << endl;
    employeeQueue.SIZE();
    cout << "Removed the front element of the Queue" << endl;
    employeeQueue.REMOVE();
    cout << "Printing the Queue: " << endl;
    employeeQueue.PRINT();
    cout << "What is the Queue size? " << endl;
    employeeQueue.SIZE();
}
//this method uses ifstream to read from the Employees txt file and then uses the setters on the Employee class to create the object newEmp and finaly adds it to the LinkedQueue with the ADD method
//and does this for every line on the Employees txt
void readFile(LinkedQueue& employeeQueue) {
    int empNum, years;
    string firstName, lastName;
    Employee newEmp;
    ifstream input;

    input.open("Employees.txt");

    while (input) {
        input >> empNum >> firstName >> lastName >> years;
        if (input) {
            newEmp.setEmpNo(empNum);
            newEmp.setFirstName(firstName);
            newEmp.setLastName(lastName);
            newEmp.setYearsOfService(years);
            employeeQueue.ADD(newEmp);
        }
    }
    input.close();
}
//this method creates a new Employee object NewEmp and uses the method user() to fill all the employee information to that new object and then uses ADD() to add that object to the LinkedQueue
void enQueueEmp(LinkedQueue& employeeQueue) {
    Employee newEmp;
    newEmp.user();
    employeeQueue.ADD(newEmp);
}