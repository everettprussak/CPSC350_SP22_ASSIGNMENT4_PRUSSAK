#ifndef GENSTACK_H
#define GENSTACK_H
#include "LinkedList.h"


/*
header class for GenStack
*/
template <class T>
class GenStack{
  public:
    GenStack(); //default
    ~GenStack();  //destructor

    //core functions
    void push(T data);
    T pop();
    T peek(); //aka top();

    //aux functions
    bool isEmpty();
    int getSize();

  private:
    ListNode<T> *top; //top in our stack
    LinkedList<T> *code; //main LinkedList behind our stack
    int size; //size of stack
};


#endif