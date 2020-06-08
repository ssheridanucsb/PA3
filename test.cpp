#include "avl.h"
#include "twofive.h"
#include <iostream> 
#include <fstream>


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
            cout << a.insert(line) << endl; 
            count++; 
            cout << count << endl; 
        }
        ifs.close();
    }

    //tree.printTraversal(); 
    //tree.printHeight(); 
    //cout << tree.search("broadcasting") << endl; 
    //cout << tree.insert("computers") << endl; 

    a.printTraversal(); 
    a.printHeight(); 
    cout << a.search("broadcasting") << endl; 
    cout << a.insert("computers") << endl; 

    return 1; 
}