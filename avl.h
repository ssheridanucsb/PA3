#ifndef AVL_H
#define AVL_H

#include <string>
#include <iostream>

using namespace std; 

struct Node{
    string word; 
    int count; 
    Node* left; 
    Node* right; 
    int height; 

    Node(string word): word(word), count(1), left(NULL), right(NULL), height(1) {}; 
    ~Node(){
        delete left;
        delete right;
        };
};

class AVL{
    public:
    //constructor and destructor
    AVL();
    ~AVL(); 

    //search function
    int search(string word) const;

    //insert function 
    int insert(string word);
    
    //range search
    void rangeSearch(string s1, string s2) const;
    //traversal and Height
    void printTraversal() const;
    void printHeight() const; 

    private:
    Node* root; 

    //helper functions 
    int height(Node *n) const;

    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);

    int balanceFactor(Node* n) const; 

    int max(int a, int b); 

    Node* getNodeFor(string word, Node* n) const; 

    //recursive helper function for insert
    Node* insertHelper(string word, Node* n);

    void rangeSearchHelper(Node* n, string s1, string s2) const;

    void printHelper(Node* n) const;

};


#endif