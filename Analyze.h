#ifndef ANALYZE_H
#define ANALYZE_H
#include <string>
#include "GenStack.h"
using namespace std;


/*
Basic header class for Analyze
*/
template <class T>
class Analyze{
    private:
        string file;
        int count;
    public:
        Analyze(string a);
        ~Analyze();
        string content();
        string delimeter(string a);
        void changeFile(string a);
};

#endif