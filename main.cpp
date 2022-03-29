#include "GenStack.h"

int main(int args, char** argv){

    GenStack<int> *stack1 = new GenStack<int>();
    stack1->push(3);
    //cout << stack1->getSize() << endl;
    stack1->push(4);
   // cout << stack1->getSize() << endl;
    stack1->push(5);
    cout << stack1->peek() << endl;
    cout << stack1->pop() << endl;
    cout << stack1->peek() << endl;
    cout << stack1->pop() << endl;
    cout << stack1->peek() << endl;
    cout << stack1->pop() << endl;
    cout << stack1->getSize() << endl;
    return 0;
}