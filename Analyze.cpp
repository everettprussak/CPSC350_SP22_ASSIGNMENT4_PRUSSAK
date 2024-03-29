#include "Analyze.h"
#include <fstream>

//constructor of analyze, 
template <class T>
Analyze<T>::Analyze(string a){
    file = a; //holds value of file in a string
    count = 1; //count for each line in the file
}

template <class T>
Analyze<T>::~Analyze(){

}

template <class T>
string Analyze<T>::content(){
    ifstream infile;
    string line;
    string contents;
    infile.open(file); //opens file from user
    while(getline(infile,line)){
        contents = contents + line + "\n"; //adding each character and line into contents then returned
    }
    return contents;
}


/*
Determines the syntax error, no syntac error, and which line.
*/
template <class T>
string Analyze<T>::delimeter(string contents){
    GenStack<char> *stack = new GenStack<char>(); //stack being used 
    int par=0, brac=0, sci=0; //counters for each individual first part for the bracket family
    int comm1=0, pos=-1, temp=-2;
    bool comment = false;
    string doe = "";

    for(char x: contents){
        pos = pos + 1;
        if(x=='/'){ //checks comments and ignores if "//" is in place
            if(temp == pos){
                comment = true;
                temp = -2;
            }
            else{
                temp = pos+1;
            }
        }

        else if((x=='('||x=='{'||x=='[') && comment==false){
           // cout << count << " : " << x << endl;
            stack->push(x);
            if(x=='('){
                par++; //( is added to stack, par is incremented
            }
            else if(x=='['){
                brac++;
            }
            else{
                sci++;
            }
        }
        
        else if(x=='\n'){
            count++; //newline allow for the count to be incremented,
            comment = false;
        }

        else if(x=='}' && comment==false){ //}, ], ) all have their own else if statement, but do the same overall thing, just in different order to secure correctness.
            if(stack->isEmpty()==false){
                if(stack->peek()=='{'){
                    stack->pop(); //was right next to their bracket "buddy" and simply pops it from the stack
                }
                else if(sci>0){
                    if(stack->peek()=='['){
                        return "Missing ] on line " + to_string(count); //if [} is the case, and there are { present in the stack, then it is missing ]
                    }
                    else if(stack->peek()=='('){
                        return "Missing ) on line " + to_string(count); //same as [} case, but (}
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

        else if (x==']' && comment==false){
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

        else if(x==')' && comment==false){
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


template <class T> //this is used if the user wants a new file. count is restarted, and the file is renamed.
void Analyze<T>::changeFile(string a){
    file = a;
    count = 1;
}


template class Analyze<int>;
template class Analyze<char>;