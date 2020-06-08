#include "avl.h"

//constructor
AVL::AVL(): root(NULL) {};

//destructor 
AVL::~AVL(){
    delete root; 
};

//return height of node
int AVL::height(Node* n) const{
    if(n==NULL) return 0; 
    return n->height;
};

//get balance factor of node
int AVL::balanceFactor(Node* n) const{
    if(n==NULL) return 0;
    return height(n->left) - height(n->right);
};

int AVL::max(int a, int b){
    return (a<b) ? b:a;
};

//helper function
Node* AVL::getNodeFor(string word, Node* n) const{
    if(n!=NULL){
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
    return NULL;
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
    root = insertHelper(word, root); 
    return getNodeFor(word, root)->count; 
};

Node* AVL::insertHelper(string word, Node* n){
    if(n==NULL){
        return new Node(word); 
    }
    if(word < n->word){
        n->left = insertHelper(word, n->left);
    }else if(word > n->word){
        n->right = insertHelper(word, n->right); 
    }else{
        n->count++; 
        return n; 
    }
    
    n->height = 1 + max(height(n->left), height(n->right));
    int b = balanceFactor(n); 

    if (b > 1 && word < n->left->word)  
        return rightRotate(n);  
  
    // Right Right Case  
    if (b < -1 && word > n->right->word)  
        return leftRotate(n);  
  
    // Left Right Case  
    if (b > 1 && word > n->left->word)  
    {  
        n->left = leftRotate(n->left);  
        return rightRotate(n);  
    }  
  
    // Right Left Case  
    if (b < -1 && word < n->right->word)  
    {  
        n->right = rightRotate(n->right);  
        return leftRotate(n);  
    } 

    return n; 
};

    Node* AVL::rightRotate(Node* y){
        Node* x = y->left; 
        Node* t = x->right; 

        x->right = y; 
        y->left = t; 

        y->height = max(height(y->left), 
                    height(y->right)) + 1;  

        x->height = max(height(x->left), 
                    height(x->right)) + 1; 

        return x;  
    };
        
    Node* AVL::leftRotate(Node* x){
            Node *y = x->right;  
            Node *T2 = y->left;  
  
      
            y->left = x;  
            x->right = T2;  
  
      
            x->height = max(height(x->left),     
                    height(x->right)) + 1;  
            y->height = max(height(y->left),  
                    height(y->right)) + 1;  
  
 
            return y;
    }; 



void AVL::rangeSearchHelper(Node* n, string s1, string s2) const{
    if(!n) return;
    if(s1 < n->word) rangeSearchHelper(n->left, s1, s2);
    if(s1<=n->word && s2>=n->word){
        cout << n->word << endl;
    }
    if(s2 > n->word) rangeSearchHelper(n->right, s1, s2);
};

void AVL::rangeSearch(string s1, string s2) const{
  rangeSearchHelper(root, s1, s2);
};

void AVL::printTraversal() const{
    cout << "(" ;
    printHelper(root);
    cout << ")";
};

void AVL::printHelper(Node* n) const{
    if(!n) {cout << "()";}
    else{
        cout << "(" <<  n->word << ":" << n->count;
        printHelper(n->left);
        printHelper(n->right);
        cout << ")";
    }
};

void AVL::printHeight() const{
    cout << "Height = [" << root->height << "]" << endl; 

}