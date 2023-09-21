#include "tree.cpp"

class BST : public Tree{
private:
    Node* insert_process(Node* ptr,int value){
        if (ptr == NULL)
            return newNode(value);
        else if (value < ptr->data)
            ptr->left = insert_process(ptr->left,value);
        else if (value > ptr->data)
            ptr->right = insert_process(ptr->right,value);
        return ptr;
    }
    bool search_process(Node* ptr,int value){
        if (ptr == NULL)
            return false;
        else if (value < ptr->data)
            return search_process(ptr->left,value);
        else if (value > ptr->data)
            return search_process(ptr->right,value);
        else
            return true;
    }
public:
    void showBST(){
        cout << "show BST" << endl;
    }
    void insert(int value){
        root = insert_process(root,value);
    }
    void search(int value){
        if (search_process(root,value))
            cout << "found : " << value << endl;
        else
            cout << "not found : " << value << endl;
    }
};
