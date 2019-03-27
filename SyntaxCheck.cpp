#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include "SyntaxCheck.h"


SyntaxCheck::SyntaxCheck(){
	
}
SyntaxCheck::~SyntaxCheck(){
	
}
bool SyntaxCheck::checkSymbols(string file){
	GenStack<char> g(10);
	
	string all; 
    int lineNum = 1; //to keep track of the line number
    
	ifstream is; 
    is.open(file.c_str());//opening the file given by the user
    
    while(getline(is, all)!=NULL){//gets each line of the file and saves it
    	for(int i=0; i< all.size();i++){
    		if(all[i]=='('||all[i]==')'||all[i]=='{'||all[i]=='}'||all[i]=='['||all[i]==']'){//finds all instances of brackets
    			//if the bracket is an opening bracket, push it to the stack
    			if(all[i]=='('||all[i]=='{'||all[i]=='['){
    				g.push(all[i]);
				}
				
				//if the symbols match, they can be removed from the stack
				else if((g.peek()=='('&&all[i]==')')||(g.peek()=='{'&&all[i]=='}')||(g.peek()=='['&&all[i]==']')){
					g.pop();
				}
				
				//if the symbols are mismatched
				else if(g.peek()=='('&&(all[i]=='}'||all[i]==']')){
					cout << "Error. Line " << lineNum << ": expected ) and found " << all[i] << " instead" << endl;
					return false;
				}
				else if(g.peek()=='{'&&(all[i]==')'||all[i]==']')){
					cout << "Error. Line " << lineNum << ": expected } and found " << all[i] << " instead" << endl;
					return false;
				}
				else if(g.peek()=='['&&(all[i]=='}'||all[i]==')')){
					cout << "Error. Line " << lineNum << ": expected ] and found " << all[i] << " instead" << endl;
					return false;
				}
			}
		}
		lineNum++;
	}
	if(g.isEmpty())
		return true;
	//Throws error if there are leftover symbols
	else{
		cout << "Error. Missing" <<g.peek()<<endl;
	}
	return false;
    
}
