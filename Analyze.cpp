#include "Analyze.h"
#include <fstream>


template <class T>
Analyze<T>::Analyze(string a){
    file = a;
    count = 1;
}

template <class T>
Analyze<T>::~Analyze(){

}

template <class T>
string Analyze<T>::content(){
    ifstream infile;
    string line;
    string contents;
    infile.open(file);
    while(getline(infile,line)){
        contents = contents + line + "\n";
    }
    return contents;
}

template <class T>
string Analyze<T>::delimeter(string contents){
    GenStack<char> *stack = new GenStack<char>();
    string ret;
    char temp;
    int par=0, brac=0, sci=0;

    for(char x: contents){
        if(x=='('||x=='{'||x=='['){
            stack->push(x);
            if(x=='('){
                par++;
            }
            else if(x=='['){
                brac++;
            }
            else{
                sci++;
            }
        }
        
        else if(x=='\n'){
            count++;
        }

        else if(x=='}'){
            if(stack->isEmpty()==false){
                if(stack->peek()=='{'){
                    stack->pop();
                }
                else if(sci>0){
                    if(stack->peek()=='['){
                        return "Missing ] on line " + to_string(count);
                    }
                    else if(stack->peek()=='('){
                        return "Missing ) on line " + to_string(count);
                    }
                    else{
                        return "Missing {  on line " + to_string(count);
                    }
                }
                else{
                    return "Missing { on line " + to_string(count);
                }
            }
            else{
                return "Missing { on line " + to_string(count);
            }
        }

        else if (x==']'){
            if(stack->isEmpty()==false){
                if(stack->peek()=='['){
                    stack->pop();
                }
                else if(brac>0){
                    if(stack->peek()=='{'){
                        return "Missing } on line " + to_string(count);
                    }
                    else if(stack->peek()=='('){
                        return "Missing ) on line " + to_string(count);
                    }
                    else{
                        return "Missing [  on line " + to_string(count);
                    }
                }
                else{
                    return "Missing [ on line " + to_string(count);
                }
            }
            else{
                return "Missing [ on line " + to_string(count);
            }
        }

        else if(x==')'){
            if(stack->isEmpty()==false){
                if(stack->peek()=='('){
                    stack->pop();
                }
                else if(par>0){
                    if(stack->peek()=='['){
                        return "Missing ] on line " + to_string(count);
                    }
                    else if(stack->peek()=='{'){
                        return "Missing } on line " + to_string(count);
                    }
                    else{
                        cout << stack->peek() << endl;
                        return "Missing (  on line " + to_string(count);
                    }
                }
                else{
                    return "Missing ( on line " + to_string(count);
                }
            }
            else{
                return "Missing ( on line " + to_string(count);
            }
        }
    }

    if(stack->isEmpty()==false){
        if(stack->peek()=='('){
            return "Reached End of File. Missing: )";
        }
        else if(stack->peek()=='['){
            return "Reached End of File. Missing: ]";
        }
        else if(stack->peek()=='{'){
            return "Reached End of File. Missing: }" ;
        }
    }
    return "Syntax is Correct";
}


template <class T>
void Analyze<T>::changeFile(string a){
    file = a;
    count = 1;
}


template class Analyze<int>;
template class Analyze<char>;