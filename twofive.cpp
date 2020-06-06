#include "twofive.h"

//constructor 
TwoFive::TwoFive(): root(NULL) {};

//destructor
TwoFive::~TwoFive(){
    delete root; 
}; 

//insert
int TwoFive::insert(string word){
    if(root==NULL){
        root = insertHelper(word, root);
        return root->count(word); 
    }
    insertHelper(word, root);
    return search(word); 
};
//search
int TwoFive::search(string word) const{
    TwoFiveNode* n = searchHelper(root, word);
    if(n==NULL) return 0; 
    return n->count(word); 
}; 

//range serach
void TwoFive::rangeSearch(string s1, string s2) const{
    rangeSearchHelper(s1, s2, root);
};

void TwoFive::rangeSearchHelper(string s1, string s2, TwoFiveNode* n) const {
    if(n==NULL) return; 
    for(int i = 0; i < n->key_length; i++){
        if(s1 <= n->keys[i].first && s2 >= n->keys[i].first){
            cout << n->keys[i].first << endl; 
        }
    }
    for(int i = 0; i < n->child_length; i++){
        rangeSearchHelper(s1, s2, n->children[i]);
    }
};

//print height by calling TwoFive.printHeight()
void TwoFive::printHeight() const {
    if(root==NULL){
        cout << "height = [" << 0 << "]" << endl; 
    }else{
        cout << "height = [" << root->height << "]" << endl; 
    }
};

//print traversal by calling TwoFive.printTraversal()
void TwoFive::printTraversal() const{
    printHelper(root);
};

void TwoFive::printHelper(TwoFiveNode* n) const {
    if(n==NULL){
        cout << "()"; 
    }
    else{
        cout << "("; 
        for(int i = 0; i < n->key_length; i++){
            cout << n->keys[i].first << ":" << n->keys[i].second;
            if(i < n->key_length - 1){
                cout << ","; 
            }
        }
        for(int i = 0; i < 5; i++){
            printHelper(n->children[i]);
        }
        cout << ")";
    }
};


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
        return n; 
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
        n->keys[n->key_length] = pair<string, int>(word, 1);
        n->key_length++;
        sort(n->keys, n->keys + n->key_length);
        return n;  
    }
};


//split helper functions 
TwoFiveNode* TwoFive::split(TwoFiveNode* n, TwoFiveNode* wordNode){
    if(n==NULL){
        root = wordNode;
        root->height++; 
        return root; 
    }else if(n->key_length!=4){
        //find where key should be inserted 
        int j = 0; 
        for(int i = 0; i < n->key_length; i++){
            if(n->keys[i] < wordNode->keys[0]) j++; 
        }

        //insert word from wordNode and update pointers. 
        for(int i = n->key_length; i >= j; i--){
            n->keys[i+1] = n->keys[i]; 
        }
        //insert word from wordNode
        n->keys[j] = wordNode->keys[0];

        //update pointers 
        for(int i = n->child_length; i > j; i--){
            n->children[i+1] = n->children[i]; 
        }
        n->children[j] = wordNode->children[0];
        n->children[j+1] = wordNode->children[1];
        wordNode->children[0] = NULL;
        wordNode->children[1] = NULL; 
        delete wordNode; 
        return n; 

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
        n->keys[4] = wordNode->keys[0];
        int k; 
        for(int i = 4; i > 0; i--){
            if(n->keys[i] < n->keys[i-1]){
                pair<string, int> temp = n->keys[i];
                n->keys[i] = n->keys[i-1];
                n->keys[i-1] = temp; 
                int k = i-1; 
            }
        }
      
        int med = 2;
        //NEED TO INCLUDE POINTERS WHEN UPDATING LEFT AND RIGHT 
        //words less than medValue go in left node, greater go in right node
        for(int i = 0; i < 5; i++){
            if (i < med)
            {
                left->keys[left->key_length] = n->keys[i];
                left->key_length++; 
            } else if(i==med){
                wordNode->keys[0] = n->keys[i];
            }else{
                right->keys[right->key_length] = n->keys[i];
                right->key_length++; 
            }
        }
        for(int i = 0; i < 5; i++){
            if(i <= k){
                left->children[i] = n->children[i];
                if(n->children[i]!=NULL) left->child_length++; 
            }else{
                right->children[i] = n->children[i];
                if(n->children[i]!=NULL) right->child_length++; 
            }
        }
        
        wordNode->children[0] = left; 
        wordNode->child_length++; 
        wordNode->children[1] = right; 
        wordNode->child_length++; 

        for(int i = 0; i < 6; i++){
            n->children[i] = NULL;
        }
        delete n; 


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