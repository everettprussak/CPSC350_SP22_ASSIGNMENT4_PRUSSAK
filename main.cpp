
#include "Analyze.h"

int main(int args, char** argv){

    string filename = argv[1];
    Analyze<char> *a = new Analyze<char>(filename);
  //  string c = a->content();
   // cout << a->delimeter(c) << endl;
    string response = "yes";
    while (response=="yes"||response=="YES"||response=="y"||response=="Yes"){
        string c = a->content();
        cout << a->delimeter(c) << endl;
        cout << endl;

        if(a->delimeter(c)!="Syntax is Correct"){
            response = "no";
            break;
        }

        cout << "Type 'yes' to enter another file: " << endl;
        cin >> response;
        cout << endl;
        if(response=="yes"||response=="YES"||response=="y"||response=="Yes"){
            cout << "Enter file name: " << endl;
            cin >> filename;
            cout << endl;
            a->changeFile(filename);
            cout << endl;
        }
    }

    return 0;
}