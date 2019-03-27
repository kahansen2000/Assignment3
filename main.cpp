/*
Katherine Hansen
2326665
Assignment 3
CPSC350-01
This program includes the main method that tests the SyntaxCheck class
*/
#include <iostream>
#include "SyntaxCheck.h"

using namespace std;

int main(int argc, char** argv) {
	SyntaxCheck sc;
	string file;
	if(argc<2){//if no file was specified
		cout <<"No valid file entered"<<endl;
		cout <<"Please enter valid file name now"<<endl;
		cin >>file;
	}
	else{//if file was specified
		file=argv[1];
	}
	while(sc.checkSymbols(file)){
		cout <<"No errors found."<<endl;
		char answer;
		cout <<"Would you like to go again? (Y/N)"<<endl;//asks if user wants to go again
		cin>>answer;
		if(answer=='Y'){
			cout <<"Please enter new file name"<<endl;
			cin >>file;
		}
		else{
			break;
		}
		
	}
	return 0;
}
