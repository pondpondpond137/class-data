#include "bstree.cpp"

int main(){
    BST* bst = new BST();
    bst->insert(5);
    bst->insert(1);
    bst->insert(10);
    bst->insert(98);
    bst->insert(16);
    bst->insert(66);
    bst->insert(7);
    bst->insert(3);
    bst->show();
    bst->inorder();
    bst->search(8);
    return 0;
}
