#include<iostream>
//pure virtual interface.
//template<typename ListNodeType>
class ListInterface{

public:
  //virtual void inserFront(ListNodeType d) = 0;
  //virtual void insertBack(ListNodeType d) = 0;
  virtual bool isEmpty() = 0;
  // insert
  // peek
  virtual int getSize() = 0;
  //virtual ListNodeType removeFront() = 0;
};
