#ifndef GENSTACK_H
#define GENSTACK_H
#include "LinkedList.h"

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
    ListNode<T> *top;
    LinkedList<T> *code;
    int size;
};


#endif