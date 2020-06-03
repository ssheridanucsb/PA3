#include "twofive.h"

//constructor 
TwoFive::TwoFive(): root(NULL) {};

//destructor
TwoFive::~TwoFive(){
    delete root; 
}; 

//insert
int TwoFive::insert(string word){};
//search
int TwoFive::search(string word) const{
    TwoFiveNode* n = searchHelper(root, word);
    if(n==NULL) return 0; 

    for(int i = 0; i < n->key_length; i++){
        if(n->keys[i].first == word) return n->keys[i].second; 
    }
    return 0; 
}; 

//range serach
void TwoFive::rangeSearch(string s1, string s2) const{};

//print height by calling TwoFive.printHeight()
void TwoFive::printHeight() const {};

//print traversal by calling TwoFive.printTraversal()
void TwoFive::printTraversal(){};


//recursive insert helper function
TwoFiveNode* TwoFive::insertHelper(string word, TwoFiveNode* n){};

//split helper functions 
TwoFiveNode* TwoFive::split(TwoFiveNode* n){};

//search helper function 
TwoFiveNode* TwoFive::searchHelper(TwoFiveNode* n, string s) const{
    //if n is null return null
    if(n==NULL) return NULL;
    //otherwise check through node for value
    else{
        TwoFiveNode* p = NULL;
        for(int i = 0; i < n->key_length; i++){
            string w = n->keys[i].first;
            //if the value is found return it
            if(w == s) return n; 
        };
    };
};