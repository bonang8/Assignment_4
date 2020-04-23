#ifndef GENQUEUE_H
#define GENQUEUE_H
#include<iostream>
#include "ListNode.h"
#include "ListInterface.h"

struct Student{
   unsigned int waitTimeAtWindow;
   unsigned int timeEnteredQueue;
 public:
   Student(){
      this->waitTimeAtWindow = 0;
      this->timeEnteredQueue = 0;
    }
   Student(int waitTimeAtWindow, int timeEnteredQueue){
      this->waitTimeAtWindow = waitTimeAtWindow;
      this->timeEnteredQueue = timeEnteredQueue;
   }
   int getTimeEnteredQueue()
   {
     return timeEnteredQueue;
   }
   int getWaitTimeAtWindow()
   {
     return waitTimeAtWindow; 
   }
   friend ostream& operator<<(ostream& os, const Student& stu);

};
ostream& operator<<(ostream& os, const Student& stu)
{
    os << stu.waitTimeAtWindow << ';' << stu.timeEnteredQueue;
    return os;
}

class GenQueue: ListInterface{

  //DoublyLinkedList<ListNodeType> * dll;
  DoublyLinkedList<Student> * ptr_dll;

  public:
    GenQueue()
    {
      ptr_dll = new DoublyLinkedList<Student>();

    }

    ~GenQueue(){
      //delete myQueue;
    }

    void push_back(Student studentToEnqueue)
    {

     // call the DoublyLinkedList class
      ptr_dll->insertBack(studentToEnqueue);
    }
    // pops the front
    Student pop_front()
    {
      return ptr_dll->removeFront();
    }
    // prints whats in the queue
    void print()
    {
      ptr_dll->printList();
    }
    bool isEmpty()
    {
      ptr_dll->isEmpty();
    }
    int getSize()
    {
      ptr_dll->getSize();
    }

};
#endif
