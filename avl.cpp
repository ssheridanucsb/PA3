#include "avl.h"

//constructor
AVL::AVL(): root(NULL) {};

//destructor 
AVL::~AVL(){
    delete root; 
};

//return height of node
int AVL::height(Node* n) const{
    return n->height;
};

//get balance factor of node
int AVL::balanceFactor(Node* n) const{
    if(n==NULL) return 0; 
    return height(n->left) - height(n->right);
};

int AVL::max(int a, int b){
    return (a<b)? b:a;
};

//perform a right rotation
Node* AVL::rightRotate(Node* y){
    Node* x = y->left;
    Node* t = x->right; 

    //rotate
    x->right = y; 
    y->left = t; 

    //update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x; 
};

//perform a left rotation
Node* AVL::leftRotate(Node* x){
    Node* y = x->right; 
    Node* t = y->left; 

    //rotate
    y->left = x; 
    x->right= t; 

    //update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y; 
};

//helper function
Node* AVL::getNodeFor(string word, Node* n) const{
    if(n){
      //check for value
      if(n->word == word){
        return n;
      }
      //if the value is smaller go left
      else if(n->word > word){
        return getNodeFor(word, n->left);
      }
      //if the value is larger go right
      else if(n->word < word){
        return getNodeFor(word, n->right);
      }

      }
    return 0;
};

//search funciton 
int AVL::search(string word) const{
     Node* n = getNodeFor(word, root);
  if(n){
    return n->count; 
  }
  return 0;
};

int AVL::insert(string word){

};


Node* AVL::insertHelper(string word, Node* n){
    if(n==NULL){
        n = new Node(word);
    }

    if(word < n->word){
        n->left = insertHelper(word, n->left);
    }
    else if(word > n->word){
        n->right = insertHelper(word, n->right);
    }
    else
    {
        (n->count)++;
        return n; 
    }

    n->height = max(height(n->left), height(n->right)) + 1;

    int balance = balanceFactor(n);

    //left left

    if(balance > 2 && word < n->left->word){
        return rightRotate(n);
    };

    //right right
    if(balance < -2 && word > n->right->word){
        return leftRotate(n);
    };

    //left right
    if(balance > 2 && word > n->left->word){
        n->left = leftRotate(n->left);
        return rightRotate(n);
    }

    //right left 
    if(balance < -2 && word <n->right->word){
        n->right = rightRotate(n->right);
        return leftRotate(n);
    }
    
    return n; 

};