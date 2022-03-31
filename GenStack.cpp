#include "GenStack.h"
#include <exception>

template <class T>
GenStack<T>::GenStack(){
  size = 0;
  code = new LinkedList<T>();
  top = NULL;
}

template <class T>
GenStack<T>::~GenStack(){
  cout << "Stack Destructed." << endl;
  delete code;
}

template <class T>
void GenStack<T>::push(T data){
    ListNode<T> *node = new ListNode<T>(data);
    if(isEmpty()){
        top = node;
    }
    else{
        node->next = top;
        top = node;
    }
    size++;
    code->insertFront(data);
}

template <class T>
T GenStack<T>::pop(){

  if(isEmpty()){
    throw runtime_error("stack is empty");
  }
  
  top = top->next;
  T rem = code->removeFront();
  size--;
  return rem;
}
template <class T>
T GenStack<T>::peek(){

  if(isEmpty()){
    throw runtime_error("stack is empty");
  }

  return top->data;
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
