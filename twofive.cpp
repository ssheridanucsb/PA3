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
int TwoFive::search(string word) const{}; 

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
TwoFiveNode* TwoFive::searchHelper(TwoFiveNode* n, string s) const{};