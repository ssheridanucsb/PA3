#include "twofive.h"

//constructor 
TwoFive::TwoFive(): root(NULL), height(0) {};

//destructor
TwoFive::~TwoFive(){
    delete root; 
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
        cout << "height = [" << height << "]" << endl; 
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

int TwoFive::insert(string word){
    if(root==NULL){
        root = new TwoFiveNode(word);
        height++; 
        return 1; 
    }
    insertHelper(word, root);
    return search(word); 
};
//recursive insert helper function
TwoFiveNode* TwoFive::insertHelper(string word, TwoFiveNode* n){
    //if is not leaf, find correct path to follow 
    if(n==NULL){
        TwoFiveNode* t = new TwoFiveNode(word); 
        return t; 
    }
    else if(n->contains(word)){
        n->increment(word);  
    }
    else if(n->child_length!=0){ //not a leaf
        TwoFiveNode* p = n->children[0];
        for(int i = 0; i < n->key_length; i++){
            if(word > n->keys[i].first){
                p = n->children[i+1]; 
            }
        }
        //recursive call to new path 
        return insertHelper(word, p); 

    }else if(n->key_length==4 && n->child_length==0){//if n is a full leaf split
        TwoFiveNode* m = new TwoFiveNode(word);
        return split(n, m);
    }else{
        //otherwise add the word to the leaf 
        n->keys[n->key_length] = pair<string, int>(word, 1); 
        n->key_length++; 
        sort(n->keys, n->keys + n->key_length);
        return n; 
    }
};


//split helper functions 
TwoFiveNode* TwoFive::split(TwoFiveNode* n, TwoFiveNode* m){
    if(n==NULL){
        root = m;
        height++;  
        return root; 
    }else if(n->key_length<4){
        n->keys[n->key_length] = m->keys[0];
        n->key_length++; 
        sort(n->keys, n->keys + n->key_length); 
        for(int i = 0; i < 5; i++){
            if(n->children[i]==m){
                for(int j = n->key_length; j > i; j--){
                    n->children[j+1] = n->children[j]; 
                }
                n->children[i] = m->children[0]; 
                n->children[i+1] = m->children[1]; 
                n->child_length++; 
            }
        }

        int l = 0; 
        for(int i = 0; i < 5; i++){
            m->children[i] = NULL; 
            if(n->children[i]!=NULL){
                n->children[i]->parent = n; 
                l++;
            }
        }
        n->child_length=l; 
        delete m; 
        return n; 

    }else{
        n->keys[4] = m->keys[0];
        sort(n->keys, n->keys+5); 
        int med = 5/2; 
        pair<string, int> medP = n->keys[med]; 

        //create left and right nodes
        TwoFiveNode* left = new TwoFiveNode; 
        TwoFiveNode* right = new TwoFiveNode; 
        left->parent = m; 
        right->parent = m; 

        if(m->child_length!=0){
            for(int i = 0; i < 6; i++){
                if(n->children[i]==m) n->children[i] = m->children[0];
            }
            n->children[5] = m->children[1];

            if(m->children[0]!=NULL){
                m->children[0]->parent=NULL; 
                 }
            if(m->children[1]!=NULL){
                m->children[1]->parent=NULL; 
            }
        }

        TwoFiveNode* tempArray[6];
        for(int i = 0; i < 6; i ++){
            tempArray[i] = n->children[i]; 
        }

        for(int i = 0; i <6; i++){
            TwoFiveNode* p = tempArray[i]; 
            if(p!=NULL){
                //re-sort children pointers 
                if(p->keys[0] < n->keys[0]){
                    n->children[0] = p; 
                }else if(n->keys[0] < p->keys[0] && p->keys[0] < n->keys[1]){
                    n->children[1] = p; 
                }else if(n->keys[1] < p->keys[0] && p->keys[0] < n->keys[2]){
                    n->children[2] = p; 
                }else if(n->keys[2] < p->keys[0] && p->keys[0] < n->keys[3]){
                    n->children[3] = p; 
                }else if(n->keys[3] < p->keys[0] && p->keys[0] < n->keys[4]){
                    n->children[4] = p; 
                }else{
                    n->children[5] = p; 
                }
            }
        } 

        m->parent = n->parent; 
        m->children[0] = left; 
        m->children[1] = right; 
        m->child_length = 2; 

        if(n->parent!=NULL){
            for(int i = 0; i < 6; i++){
                if(n->parent->children[i] == n){
                    n->parent->children[i] = m;
                    }
            }
        }

        //split values
        for(int i = 0; i < 5; i++){
            if(i < med){
                left->keys[left->key_length] = n->keys[i]; 
                left->key_length++; 
            }else if(i == med){
                m->keys[0] = n->keys[i];
            }else{
                right->keys[right->key_length] = n->keys[i]; 
                right->key_length++; 
            }
        }

        //split child pointers
        for(int i = 0; i < 6; i++){
            if(n->children[i] != NULL){
                if(i <= med){
                    n->children[i]->parent = left; 
                    left->children[left->child_length] = n->children[i]; 
                    left->child_length++; 
                }else{
                    n->children[i]->parent = right; 
                    right->children[right->child_length] = n->children[i]; 
                    right->child_length++; 
                }

            }
        }


        for(int i = 0; i < 6; i++){
            n->children[i] = NULL;
        } 

        delete n; 
        return split(m->parent, m); 
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