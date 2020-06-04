#include "twofive.h"

//constructor 
TwoFive::TwoFive(): root(NULL) {};

//destructor
TwoFive::~TwoFive(){
    delete root; 
}; 

//insert
int TwoFive::insert(string word){
    TwoFiveNode* n = insertHelper(word, root);
    return n->count; 
};
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
void TwoFive::printHeight() const {
    if(root==NULL){
        cout << "height = [" << 0 << "]" << endl; 
    }else{
        cout << "height = [" << root->height << "]" << endl; 
    }
};

//print traversal by calling TwoFive.printTraversal()
void TwoFive::printTraversal(){};


//recursive insert helper function
TwoFiveNode* TwoFive::insertHelper(string word, TwoFiveNode* n){
    //if null
    if(n==NULL){
        //add new node
        n = new TwoFiveNode(word);
        return n; 
    } //if node contains word
    else if(n->contains(word)){
        //increment word
        n->increment(word);
    }// if not a leaf node 
    else if(n->child_length!=0){
        TwoFiveNode* p = n->children[0];
        for(int i = 0; i < n->key_length; i++){
            string w = n->keys[i].first;
            if(word > w){
                p = n->children[i+1];
            }
        }
        return insertHelper(word, p); 
    }// if node is full leaf 
    else if(n->key_length==4 && n->child_length==0){
        TwoFiveNode* w = new TwoFiveNode(word);
        return split(n, w); 
    }//else empty leaf 
    else{
        //add key to the end of the list
        n->keys[n->key_length] = pair(word, 1);
        n->key_length++;
        sort(n->keys, n->keys + n->key_length);
        return n;  
    }
};


//split helper functions 
TwoFiveNode* TwoFive::split(TwoFiveNode* n, TwoFiveNode* wordNode){
    if(n==NULL){
        root = wordNode;
        return root; 
    }else if(n->key_length!=4){
    

    }else{
        //create singular node with desired word to insert  
        wordNode->parent = n->parent; 
        //create left and right nodes to split n 
        TwoFiveNode* left = new TwoFiveNode;
        left->parent = wordNode; 
        TwoFiveNode* right = new TwoFiveNode;
        right->parent = wordNode;
        //if theres a parent change the parents pointer to new wordNode
        if(wordNode->parent!=NULL){
            TwoFiveNode* p = wordNode->parent; 
            for(int i = 0; i < p->child_length; i++){
                if(p->children[i]==n){
                    p->children[i]=wordNode; 
                }
            }
        }
        //find median 
        pair<string, int> s[5]; 
        for(int i = 0; i < n->key_length; i++){
            s[i] = n->keys[i];
        }
        s[5] = wordNode->keys[0];
        sort(s, s + 5);
        int med = 5/3;

        //words less than medValue go in left node, greater go in right node
        for(int i = 0; i < 5; i++){
            if(i < med){
                left->keys[left->key_length] = s[i];
                left->key_length++;
            } else if (i==med){
                wordNode->keys[0] = s[i];
            }else{
                right->keys[right->key_length] = s[i];
                right->key_length++; 
            }
        }
        wordNode->children[0] = left; 
        wordNode->child_length++; 
        wordNode->children[1] = right; 
        wordNode->child_length++; 


        //now call split on the parent node put the entry node in the correct place. 
        return split(wordNode->parent, wordNode);
    }
};

//search helper function 
TwoFiveNode* TwoFive::searchHelper(TwoFiveNode* n, string s) const{
    //if n is null return null
    if(n==NULL) return NULL;
    //otherwise check through node for value
    else{
        TwoFiveNode* p = n->children[0];
        for(int i = 0; i < n->key_length; i++){
            string w = n->keys[i].first;
            //if the value is found return it
            if(w == s) return n; 
            else if(s > w){
                p = n->children[i+1];
            };
        };
        return searchHelper(p, s);
    };
};