#include "LinkedList.h"

template <class T>
LinkedList<T>::LinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList(){
    ListNode<T>* current = front;
    while(current != NULL) {
        ListNode<T> *next1 = current->next;
        current->~ListNode();
        current = next1;
    }
    delete front;
    delete back;
}

template <class T>
void LinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    }
    node->next = front; //if empty, makes next null, and then front points to same node as back. 
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
        cout << "List is Empty" << endl;
        return -1;
    }
    else if(size==1){
        back = NULL;
    }

    int temp = front->data;
    ListNode<T> *ft = front;

    front = front->next;
    ft->next = NULL;
    delete ft;

    size--;
    return temp;
}

//do removeBack() ??

template <class T>
T LinkedList<T>::removeBack(){
    if(isEmpty()){
        cout << "List is Empty" << endl;
        return -1;
    }
    else if(size==1){
        front = NULL;
    }

     int temp = back->data;
     ListNode<T> *bt = NULL;
     bt->next = back;
     back = bt;
     delete bt;
    
    size--;
    return temp;
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
T LinkedList<T>::findAtPos(int val){

}
template class LinkedList<int>;