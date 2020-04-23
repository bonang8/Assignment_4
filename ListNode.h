#ifndef LISTNODE_H
#define LISTNODE_H
#include<iostream>
//#include "ListInterface.h"
using namespace std;
// ListNode file make a template class
 template<typename ListNodeType> class ListNode{
    public:
      ListNodeType data;
      ListNode<ListNodeType> *next;
      ListNode<ListNodeType> *prev;
      // ListNode implementation that will go in the template class
      // Constructor
      ListNode<ListNodeType>()
        {
           data = 0;
           next = NULL;
           prev = NULL;
        }
       // overloaded constructor
      ListNode<ListNodeType>(ListNodeType d)
        {
          data = d;
          next = NULL;
          prev = NULL;
        }
        //destructor
      ~ListNode<ListNodeType>()
        {
          // no need to insert stuff
           // research0000
           // build some character.

        }
  };

//==========Doubly Linked Lists is a template class same file =========//
   //give same type at doubly linked lists
   // header file for DoublyLinkedList
template<typename ListNodeType> class DoublyLinkedList {
   private:
       ListNode<ListNodeType>*front;
       ListNode<ListNodeType>*back;
       unsigned int size;
   public:
     /*
     DoublyLinkedList();
     ~DoublyLinkedList();
     // main operations
     void insertFront(ListNodeType data);
     void insertBack(ListNodeType data);
     int removeFront();
     int removeBack();
     // check and research
       //int search(ListNodeType val);
     // check and research
        //int removeAtPos(ListNodeType pos);
     // helper functions
     unsigned int getSize();
     bool isEmpty();
     void printList();
     */

// implementation file(.cpp) for NaiveList

    DoublyLinkedList<ListNodeType>()
    {
      size = 0;
      front = NULL;
      back = NULL;
    }
    ~DoublyLinkedList<ListNodeType>()
    {
     // Todo Later
    }
    unsigned int getSize()
    {
       return size;
    }
    bool isEmpty()
    {
       return (size == 0);
    }
    // whether single or double it works
    void printList()
    {
      // create a temp pointer
      ListNode<ListNodeType>*curr = front;
      // iterate
      while(curr != NULL)
      {
        cout << curr->data << endl;
        curr = curr->next;
      }
    }
    // from the front
    void insertFront(ListNodeType d)
    {
      ListNode<ListNodeType>*node = new ListNode<ListNodeType>(d);
      // check if isEMPTY
      if(isEmpty())
      {
        back = node;
        // front = node
      }
      else
      {
        // is not empty
        front->prev = node;
        node->next = front;
        // back->next = node;
        // node->prev = back;
      }
      front = node;
      //back = node;
      size++;
    }
    // insert from the back
    void insertBack(ListNodeType d)
    {
      //cout << "Diag: in insert back" << endl;
      ListNode<ListNodeType>*node = new ListNode<ListNodeType>(d);
      // check if isEMPTY
      if(isEmpty())
      {
        //Diag: Updated changes: commented out below
        //back = node;
         front = node;
      }
      else
      {
        // is not empty
        back->next = node;
        node->prev = back;
        // Changes: commented this out
          //node->next = back;
      }
      back = node;
      //back = node;
      size++;
    }

    // return clockTick at which student arrives
    // CHanges to ListNodeType
    //peedk() can only be called if the list is not empty
    ListNodeType peek()
    {
      //cout << "hello" << endl;
      ListNode<ListNodeType> *tempNode = front;
      ListNodeType temp = tempNode->data;
      return temp;
    }

    ListNodeType removeFront()
    {
      // when deleting a node
      ListNode<ListNodeType> *tempNode = front;
      //error check, make sure list is not empty before attempting to remove
      // if the list is empty
      // node is not the only one
      if(front->next == NULL)
      {
        // there is only one node in the List
        back = NULL;
      }
      else
      {
        // more thatn one node in the list
        front->next->prev = NULL;
      }
      front = front->next;
      tempNode->next = NULL;
      ListNodeType temp = tempNode->data;
      // Changes:
      //front = front->next;
      size--;
      delete tempNode;
      return temp;
    }

    //need to find the value in the list before we can delete
    // this function does not take in a position as a parameter

    #if 0

      ListNodeType remove(ListNodeType value)
      {
        ListNode *curr = front;
        // lets look for this value
        while(curr->data != value )
        {
          curr = curr->next;
          if(curr == NULL)
            return -1;
        }
        // if we get here, we found our node/value, now let's proceed to
        // delete
        if(curr == front)
        {
          // if node to be delete is the front
          front = curr->next;

        }
        else
        {
          // node to be delete is somewhere between front and back
          curr->prev->next = curr->next;

        }
        if(curr == back)
        {
          back = curr->prev;
        }
        else
        {
          // the node to be deleted is somewhere in between front and back
          curr->next->prev = curr->prev;
        }
        curr->next = NULL;
        curr->prev = NULL;
        int temp = curr->data;
        size--;
        delete curr;
        return temp;

      }
#endif

// NOTE: NOT NEEDED
  /* int NaiveList::search(int val)
  {
    return position;
  }
  int NaiveList::removeAtPos(int pos)
  {
    int pos = -1;

  }
  */

};
#endif
