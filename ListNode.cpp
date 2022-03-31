#include "ListNode.h"

template <class T>
ListNode<T>::ListNode(){
}

template <class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL;
    prev = NULL;
}

template <class T>
ListNode<T>::~ListNode(){
    delete next;
}

template class ListNode<int>;
template class ListNode<char>;