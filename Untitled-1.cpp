    n->keys[4] = word; //add split word to end of keys
    sort(n->keys, n->keys+4); //sort to mind median 
    pair<string, int> medWord =  n->keys[2]; //find median key 

    TwoFiveNode* s = new TwoFiveNode(medWord.first);
    s->keys[0].second=medWord.second; 

    TwoFiveNode* left = new TwoFiveNode; 
    TwoFiveNode* right = new TwoFiveNode; 


    //update split nodes children
    s->children[0] = left; 
    s->child_length++; 

    s->children[1] = right; 
    s->child_length++; 

    //update split nodes parent
    s->parent=n->parent;

    if(n->parent!=NULL){
        for(int i = 0; i < n->parent->child_length; i++){
            if(n->parent->children[i]==n){
                n->parent->children[i] == s; 
            }
        }
    }

    int m = n->getIndex(medWord.first); 
    //update left and right children
    for(int i = 0; i < 6; i++){
        if(n->children[i]!=NULL){
            if(i<m){
                left->children[left->child_length] = n->children[i];
                left->child_length++; 
            }else if(i==m){
                if(n->children[i]->keys[0] < medWord){
                    left->children[left->child_length] = n->children[i];
                    left->child_length++; 
                }else{
                    right->children[right->child_length] = n->children[i]; 
                    right->child_length++; 
                }
            }else{
                right->children[right->child_length] = n->children[i]; 
                right->child_length++; 
            }