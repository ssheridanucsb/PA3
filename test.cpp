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

    return 1; 
}