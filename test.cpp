#include "avl.h"
#include "twofive.h"
#include <iostream> 
#include <fstream>
#include <string>


using namespace std; 


int main(int argc, char* argv[]){ 

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
    AVL a; 
    string home = "PA3_dataset.txt";
    ifstream ifs(home);
    string line;

    int count = 0; 

    if(ifs.is_open()){
        while(true){
            getline(ifs, line);
            if(!ifs) break;
            line = line.substr(0, line.size( )-1);
            tree.insert(line);
            a.insert(line);
            count++; 
            cout << count << endl; 
        }
        ifs.close();
    }

    cout << "here" << endl; 
    //tree.printTraversal(); 
    //tree.printHeight(); 
    //cout << tree.search("broadcasting") << endl; 
    //cout << tree.insert("computers") << endl; 

    return 1; 
}