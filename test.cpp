#include "avl.h"
#include "twofive.h"
#include <iostream> 
#include <fstream>


using namespace std; 


int main(int argc, char* argv[]){ 
    TwoFive t; 
    AVL a; 

    string home = "PA3_dataset.txt";
    ifstream ifs(home);
    string line;
    if(ifs.is_open()){
        while(true){
            getline(ifs, line);
            if(!ifs) break;
            t.insert(line); 
        }
        ifs.close();
    }

    //t.rangeSearch("a", "z");
    t.printTraversal();

    //a.printHeight();
   // a.printTraversal();

    return 1; 
}