#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
    ListNode<T> *node = front;
    ListNode<T> *nodeToDelete = front;
    while(node != NULL) {
        nodeToDelete = node->next;
        delete node;
        node = nodeToDelete;
    }
    //delete front;
 //   delete back;
}

template <class T>
void LinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    }
    else{
        //not empty
        node->next = front;
        front->prev = node;
    }
    front = node;
    size++;
}

template <class T>
void LinkedList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    }
    else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    size++;
}

template <class T>
bool LinkedList<T>::isEmpty(){
    return size == 0;
}

template <class T>
T LinkedList<T>::removeFront(){
    
    if(isEmpty()){
        throw runtime_error("List is empty");
    }

    ListNode<T> *temp = front;
    
    if(front->next == NULL){
        back = NULL;
    }
    else{
        //more than one node in the list
        front->next->prev = NULL;
    }

    front = front->next;
    temp->next = NULL;
    int data = temp->data;
    --size;
    delete temp;
    return data;
}


template <class T>
T LinkedList<T>::removeBack(){
    if(isEmpty()){
        throw runtime_error("List is empty");
    }
    ListNode<T> *temp = front;

    if(back->prev == NULL){
        //only node in the list
        front = NULL;
    }
    else{
        //more than one node in the list
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    int data = temp->data;
    --size;
    delete temp;
    return data;
    
}

template <class T>
T LinkedList<T>::find(T value){
    int pos = -1;
    ListNode<T> *curr = front;
    
    while(curr!=NULL){
        pos++;
        if(curr->data==value){
            break;
        }
        curr = curr->next;
    }

    if(curr==NULL){
        return -1; //the value was not found.
    }
    return pos;
}

template <class T>
T LinkedList<T>::deleteAtPos(int pos){
    
    //check if empty aand if value exists


    int idx = 0;
    ListNode<T> *curr = front;
    ListNode<T> *prev = front;

    while(idx!=pos){
        prev = curr;
        curr = curr->next;
        idx++;
    }

    //We found it, lets procees to delete, also check if it is front or back (if statement)
    prev->next = curr->next;
    curr->next = NULL;
    int d = curr->data;
    size--;

    delete curr;
    return d;
}

template <class T>
unsigned int LinkedList<T>::getSize(){
    return size;
}

template class LinkedList<int>;
template class LinkedList<char>;