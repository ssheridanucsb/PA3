#include "avl.h"
#include "twofive.h"
#include <iostream> 

using namespace std; 


int main(int argc, char* argv[]){ 

    AVL tree; 
    cout << tree.insert("a") << endl;
    cout << tree.insert("b") << endl;
    cout << tree.insert("c") << endl;
    cout << tree.insert("d") << endl;
    cout << tree.insert("e") << endl;
    cout << tree.insert("f") << endl;
    cout << tree.insert("g") << endl;
     cout << tree.insert("a") << endl;
    cout << tree.insert("b") << endl;
    cout << tree.insert("c") << endl;
    cout << tree.insert("d") << endl;
    cout << tree.insert("e") << endl;
    cout << tree.insert("f") << endl;
    cout << tree.insert("g") << endl;
    tree.printHeight();
    tree.printTraversal();

return 1; 
}