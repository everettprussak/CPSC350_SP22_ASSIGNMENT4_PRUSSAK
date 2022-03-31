#include "GenStack.h"
#include <exception>


//Constructorof Genstack where size is 0, and code is created, and top is NULL
template <class T>
GenStack<T>::GenStack(){
  size = 0;
  code = new LinkedList<T>();
  top = NULL;
}

template <class T>
GenStack<T>::~GenStack(){
  cout << "Stack Destructed." << endl;
  delete code; //deletes code
}

template <class T>
void GenStack<T>::push(T data){
    ListNode<T> *node = new ListNode<T>(data); 
    if(isEmpty()){ //checks if our Stack is empty
        top = node; //if it is, the top is simply the node
    }
    else{
        node->next = top; //the stack is not empty,
        top = node; //top becomes the node, and top->next was what top previously was
    }
    size++; //size increaserd
    code->insertFront(data); //main linkedlist "code" has the data inserted into the list
}

template <class T>
T GenStack<T>::pop(){

  if(isEmpty()){ //if empty, error
    throw runtime_error("stack is empty");
  }
  
  top = top->next; //top becomes top->next
  T rem = code->removeFront(); //T rem is a template for whichever type it may be, and has the value of removeFront from code.
  size--;
  return rem;
}
template <class T>
T GenStack<T>::peek(){

  if(isEmpty()){
    throw runtime_error("stack is empty");
  }

  return top->data; //simply shows the tops data
}

template <class T>
bool GenStack<T>::isEmpty(){
  return (size < 1); 
}

template <class T>
int GenStack<T>::getSize(){
  return size;
}

template class GenStack<int>;
template class GenStack<char>;
