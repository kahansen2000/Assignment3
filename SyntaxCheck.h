/*
Katherine Hansen
2326665
Assignment 3
CPSC350-01
This program outlines the SyntaxCheck class
*/
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
