#include <iostream>
#include <fstream>
#include <string>
#include "GenStack.h"
using namespace std;

class SyntaxCheck {
    public:
        SyntaxCheck(); //Constructor
        ~SyntaxCheck(); //Destructor

        bool checkSymbols(string file); //Takes the file name from main
};
