#include "avl.h"
#include "twofive.h"
#include <iostream> 
#include <fstream>


using namespace std; 


int main(int argc, char* argv[]){ 
    TwoFive t; 
    AVL a; 

    //cout << t.insert("m") << endl;


    
    //cout << t.insert("l") << endl; 
    // << t.insert("m") << endl; 
     //cout << t.insert("n") << endl; 
    //cout << t.insert("o") << endl; 
    //cout << t.insert("p") << endl; 
    
    


    //t.rangeSearch("a", "z");
    //t.printTraversal();
    //t.printHeight();

    //a.printHeight();
   // a.printTraversal();

    TwoFive tree; 
    string home = "PA3_dataset.txt";
    ifstream ifs(home);
    string line;

    if(ifs.is_open()){
        while(true){
            getline(ifs, line);
            if(!ifs) break;
            line = line.substr(0, line.size( )-1);
            tree.insert(line);
        }
        ifs.close();
    }

    tree.printTraversal(); 
    tree.printHeight(); 


    return 1; 
}