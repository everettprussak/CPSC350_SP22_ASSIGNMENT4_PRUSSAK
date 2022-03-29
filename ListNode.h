#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
using namespace std;

template <class T>
class ListNode{
    public:
        ListNode();
        ~ListNode();
        ListNode(T d);
        T data;
        ListNode *next;  //just an address
};

#endif