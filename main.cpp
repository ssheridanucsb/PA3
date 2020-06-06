#include "twofive.h"
#include "avl.h"

#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <sstream>
#include <cstring>

int main(int argc, char* argv[]){ 
    TwoFive tree25; 
    AVL treeAVL;  

    string autograder = "/autograder/submission/PA3_dataset.txt";
    string home = "PA3_dataset.txt";
    ifstream ifs(home);
    string line;

       if(ifs.is_open()){
        while(true){
            getline(ifs, line);
            if(!ifs) break;
            tree25.insert(line);
            treeAVL.insert(line);
        }
        ifs.close();
    }

    stringstream ss(argv[1]);
    string command;
    while(getline(ss, command, ',')){
        vector<string> v; 
        stringstream ss(command);
        string token; 
        while(ss >> token){
            v.push_back(token);
        }
        if(v.size()==5){
            tree25.rangeSearch(v[2], v[4]);
            treeAVL.rangeSearch(v[2], v[4]);
        }else{
            if(v[0]=="insert"){
                cout << v[1] << " inserted, new count = " << treeAVL.insert(v[1]) << endl;
                cout << v[1] << " inserted, new count = " << tree25.insert(v[1]) << endl;

            }
            else if(v[0] == "search"){
                int c1 = treeAVL.search(v[1]);
                int c2 = tree25.search(v[1]);

                if(!c1){
                    cout << v[1] << " not found" << endl; 
                } else if(c1){
                    cout << v[1] << " found, count = " << c1 << endl; 
                }

                 if(!c2){
                    cout << v[1] << " not found" << endl;
                } else if(c2){
                    cout << v[1] << " found, count = " << c2 << endl; 
                }
                
            }
        } 
    }

tree25.printTraversal();
treeAVL.printTraversal();
      
return 1; 
}