#include "avl.h"
#include "twofive.h"
#include <iostream> 

using namespace std; 


int main(int argc, char* argv[]){ 

    TwoFive t; 
    cout << t.insert("hello") << endl; 
    cout << t.insert("there") << endl;
    cout << t.insert("general") << endl; 
    cout << t.insert("kenobi") << endl; 
    cout << t.insert("hello") << endl;
    cout << t.insert("izzy") << endl; 
    cout << t.insert("can") << endl;
    cout << t.insert("suck") << endl; 
    cout << t.insert("my") << endl; 
    cout << t.insert("nuts") << endl;
    t.printHeight(); 
    t.printTraversal(); 


    return 1; 
}