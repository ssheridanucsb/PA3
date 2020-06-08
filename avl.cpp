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
    Node* i = getNodeFor(word, root); 
    int c = i->count; 
    balance(i); 
    return c; 
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
    
    if(n->right!=NULL) n->right->parent = n; 
    if(n->left!=NULL) n->left->parent = n;

    n->height = 1 + max(height(n->left), height(n->right));
    return n; 
};

void AVL::balance(Node* i){
    if(i->parent!=NULL){//check if parent exists
        if(i->parent->parent!=NULL){//check if greatgrandparent exists, there must be a greatgrandparent to violate the balance condition
            if(i->parent->parent->parent!=NULL){
                Node* n = i->parent; //parent of inserted node i, which may violate the balance constraint 
                Node* p = n->parent; //parent of that nodes
                Node* gp = p->parent; //grandparent of that node
                if(gp->right==NULL){//left sided sub tree
                    if(p->left->left == i){//left left 
                        Node* s = p->right;
                        p->parent = gp->parent; 
                        if(s==NULL){
                            p->right = gp;
                            gp->parent = p;  
                        }else{
                            p->right = s; 
                            s->right=gp; 
                            gp->parent=s; 
                        }
                        gp->right = NULL; 
                        gp->left = NULL; 
                    }else if(p->left->right == i){//left right
                        Node* s = p->right;
                        p->parent = gp->parent; 
                        if(s==NULL){
                            p->right=gp; 
                            gp->parent=p; 
                        }else{
                            s->right = gp;
                            gp->parent = s;  
                        }
                        gp->right=NULL; 
                        gp->left=NULL; 
                        i->parent=p; 
                        n->parent=i; 
                        n->right=NULL; 
                        n->left=NULL; 
                    }else if(p->right->left == i){//right left 
                        Node* s = p->left; 
                        i->parent = gp->parent; 
                        p->parent = i; 
                        if(s!=NULL){
                            s->parent=i; 
                        }
                        i->right = n; 
                        n->right = gp; 
                        n->left=NULL; 
                        gp->right=NULL; 
                        gp->left=NULL; 
                    }else{//right right
                        Node* s = p->left;
                        n->parent=gp->parent; 
                        i->parent=n; 
                        i->right=gp;
                        gp->parent=i; 
                        gp->right=NULL; 
                        gp->left=NULL; 
                        p->right=NULL; 
                        p->left = s;  
                        p->parent = n; 
                    }
                }else if(gp->left==NULL){//right sided sub tree 


                }else{
                    return; 
                }
            } 
        }
    }
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