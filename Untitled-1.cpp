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
                        if(p->parent==NULL){
                            root = p; 
                        }
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
                        s->right=NULL; 
                        s->left=NULL;  
                    }else if(p->left->right == i){//left right
                        Node* s = p->right;
                        p->parent = gp->parent; 
                        if(p->parent==NULL){
                            root = p; 
                        }
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
                        p->left = i;
                        i->left=n; 
                        i->right=NULL;  

                        n->parent=i; 
                        n->right=NULL; 
                        n->left=NULL; 
                    }else if(p->right->left == i){//right left 
                        Node* s = p->left; 
                        i->parent = gp->parent; 
                        if(i->parent==NULL){
                            root = i; 
                        }
                        p->parent = i; 
                        if(s!=NULL){
                            s->parent=p;
                            s->right=NULL;
                            s->left=NULL;  
                        }
                        i->right = n; 
                        i->left = p; 

                        n->right = gp; 
                        n->left=NULL; 

                        gp->right=NULL; 
                        gp->left=NULL; 
                        gp->parent = n; 

                    }else{//right right
                        Node* s = p->left;
                        n->parent=gp->parent; 
                        if(n->parent==NULL){
                            root = n; 
                        }
                        i->parent=n; 
                        i->right=gp;

                        gp->parent=i; 
                        gp->right=NULL; 
                        gp->left=NULL; 

                        p->right=NULL; 
                        p->left = s;
                        if(s!=NULL){
                            s->right=NULL;
                            s->left=NULL; 
                        }  
                        p->parent = n; 
                    }
                }else if(gp->left==NULL){//right sided sub tree 
                    if(p->left->left==i){//left left
                    Node* s = p->right; 
                    n->parent=gp->parent; 

                    if(n->parent == NULL){
                        root = n; 
                    }
                    gp->parent = i;

                    n->left = i; 
                    n->right = p; 

                    i->left = gp; 
                    i->right = NULL; 

                    gp->left = NULL; 
                    gp->right = NULL;  

                    p->parent = n; 
                    p->left = NULL;

                    p->right = s; 
                    if(s!=NULL){
                        s->right=NULL;
                        s->left=NULL; 
                    } 

                    }else if(p->left->right==i){//left right
                    Node* s = p->right; 
                    i->parent = gp->parent;
                    if(i->parent==NULL){
                        root = i; 
                    }
                    i->right=p; 
                    i->left=n;

                    p->parent = i; 
                    p->right = s; 
                    p->left = NULL;
                    if(s!=NULL){
                        s->right=NULL;
                        s->left=NULL; 
                    }


                    n->left=gp; 
                    n->parent=i; 
                    n->right=NULL;

                    gp->parent=n;  
                    gp->right=NULL; 
                    gp->left=NULL; 

                    }else if(p->right->left==i){//right left
                    Node* s = p->left; 
                    p->parent = gp->parent; 
                    if(p->parent==NULL){
                        root = p; 
                    }

                    p->right = i; 
                    i->right = n; 
                    i->parent = p; 
                    i->left = NULL; 
                    
                    n->right = NULL; 
                    n->left = NULL; 

                    if(s==NULL){
                        p->left=gp;
                        gp->parent=p;
                    }else{
                        p->left = s; 
                        s->parent = p; 
                        s->left = gp; 
                        s->right = NULL; 
                        gp->parent = s; 
                    }
                    gp->right=NULL;
                    gp->left =NULL; 
    
                    }else{//right right
                    Node* s = p->left;  
                    p->parent = gp->parent; 
                    if(p->parent==NULL){
                        root = p; 
                    }

                    p->right = n; 
                    n->parent = p; 
                    n->left=NULL; 
                    n->right=i; 
                    i->parent=n; 
                    if(s==NULL){
                        p->left=gp; 
                        gp->parent=p; 
                    }else{
                        p->left=s; 
                        s->parent=p; 
                        s->left=gp; 
                        s->right=NULL; 
                        gp->parent=s; 
                    }
                    gp->left=NULL; 
                    gp->right=NULL;
                    }

                }else{
                    return; 
                }
            } 
        }
    }
};