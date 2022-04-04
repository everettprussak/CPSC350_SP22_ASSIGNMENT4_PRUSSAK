
#include "Analyze.h"

int main(int args, char** argv){


//filename gets text from the command line
    string filename = argv[1];
    Analyze<char> *a = new Analyze<char>(filename); //a sends our filename to analyzer class
  //  string c = a->content();
   // cout << a->delimeter(c) << endl;
    string response = "yes";
    while (response=="yes"||response=="YES"||response=="y"||response=="Yes"){ //allows the user to have multiple files checked
        string c = a->content(); //a->content() is simply the content in the file, returned as a string and stored in c
        cout << a->delimeter(c) << endl; //delimeter expresses either the error or the correct message
        cout << endl;

        if(a->delimeter(c)!="Syntax is Correct"){ //file has an error, allow user to fix it
            response = "no";
            break;
        }

        cout << "Type 'yes' to enter another file: " << endl;
        cin >> response;
        cout << endl;
        if(response=="yes"||response=="YES"||response=="y"||response=="Yes"){ //user wants to start process over again
            cout << "Enter file name: " << endl;
            cin >> filename;
            cout << endl;
            a->changeFile(filename);
            cout << endl;
        }
    }

    return 0;
}
// 
// (

