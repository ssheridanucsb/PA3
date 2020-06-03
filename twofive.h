#ifndef TWOFIVE_H
#define TWOFIVE_H

#include <string>
#include <utility>
#include <iostream>

using namespace std; 

struct TwoFiveNode{
    //key/values 
    pair<string, int> keys[4];
    //children
    TwoFiveNode* children [5];
    //height
    int height;
    //lenth of key array
    int key_length; 
    //length of child pointer array; 
    int child_length;  

    //constructor
    TwoFiveNode(string word){
        pair<string, int> p(word, 1);
        keys[0] = p; 
        for(int i = 1; i < 5; i++){
            children[i] = NULL; 
        };
        height = 1; 
        key_length = 1; 
        child_length = 0; 
    };
    //recursive destructor 
    ~TwoFiveNode(){
        delete [] children; 
    };

    bool contains(string word){
        for(int i = 0; i < key_length; i++){
            if(keys[i].first == word) return true;   
        }
        return false; 
    }

    void increment(string word){
         for(int i = 0; i < key_length; i++){
            if(keys[i].first == word) keys[i].second++;    
        }
    }
};

class TwoFive{
    
    public: 
    //constructor 
    TwoFive(); 

    //destructor
    ~TwoFive(); 

    //insert
    int insert(string word);
    //search
    int search(string word) const; 

    //range serach
    void rangeSearch(string s1, string s2) const;

    //print height by calling TwoFive.printHeight()
    void printHeight() const;

    //print traversal by calling TwoFive.printTraversal()
    void printTraversal();

    private: 
    //root pointer
    TwoFiveNode* root;

    //recursive insert helper function
    TwoFiveNode* insertHelper(string word, TwoFiveNode* n);

    //split helper functions 
    TwoFiveNode* split(TwoFiveNode* n, string word);

    //recursive search helper funciton 
    TwoFiveNode* searchHelper(TwoFiveNode* n, string s) const; 

    //check if node contains value
    bool nodeContains(string word) const; 

};


#endif