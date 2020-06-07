#include "avl.h"
#include "twofive.h"
#include <iostream> 
#include <fstream>


using namespace std; 


int main(int argc, char* argv[]){ 
    TwoFive t; 
    AVL a; 

    cout << t.insert("g") << endl;
    cout << t.insert("h") << endl;
    cout << t.insert("a") << endl;
    cout << t.insert("b") << endl;
  
    // 
    cout << t.insert("e") << endl;
    cout << t.insert("f") << endl;
    cout << t.insert("c") << endl; 
    cout << t.insert("d") << endl;


    cout << t.insert("y") << endl;
    cout << t.insert("z") << endl;
    cout << t.insert("w") << endl; 
    cout << t.insert("x") << endl;

    cout << t.insert("h") << endl;
    cout << t.insert("b") << endl;
    cout << t.insert("i") << endl; 
    //cout << t.insert("m") << endl;


    
    //cout << t.insert("l") << endl; 
    // << t.insert("m") << endl; 
     //cout << t.insert("n") << endl; 
    //cout << t.insert("o") << endl; 
    //cout << t.insert("p") << endl; 
    
    


    //t.rangeSearch("a", "z");
    t.printTraversal();
    t.printHeight();

    //a.printHeight();
   // a.printTraversal();

    return 1; 
}