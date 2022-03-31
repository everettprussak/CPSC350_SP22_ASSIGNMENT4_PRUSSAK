#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ListNode.h"

/*
Header Class for LinkedList
*/
template <class T>
class LinkedList{
    private:
        ListNode<T> *front;
        ListNode<T> *back;
        unsigned int size;

    public:
        LinkedList();
        ~LinkedList();
        void insertFront(T d);
        void insertBack(T d);
        T removeFront();
        T removeBack();
        T find(T value); //value that we are looking for
        bool isEmpty();
        unsigned int getSize();
        T deleteAtPos(int pos); //the position of the node, and delete it

};

#endif