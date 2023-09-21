#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

class Tree{
private:
    void printTree(string prefix, Node* ptr, bool isLeft){
        if( ptr != NULL ){
            cout << prefix;
            cout << ((prefix == "") ? "-- " : isLeft ? "L--" : "R--");
            cout << ptr->data << endl;
            printTree( prefix + (isLeft ? "|   " : "    "), ptr->left, true);
            printTree( prefix + (isLeft ? "|   " : "    "), ptr->right, false);
        }
    }

    void inorder_process(Node* ptr){
        if (ptr == NULL)
            return;
        inorder_process(ptr->left);
        cout << ptr->data << " ";
        inorder_process(ptr->right);
    }
    void preorder_process(Node* ptr){
        if (ptr == NULL)
            return;
        cout << ptr->data << " ";
        preorder_process(ptr->left);
        preorder_process(ptr->right);
    }
    void postorder_process(Node* ptr){
        if (ptr == NULL)
            return;
        postorder_process(ptr->left);
        postorder_process(ptr->right);
        cout << ptr->data << " ";
    }
protected:
    Node* root;
    Node* newNode(int val){
        Node* result = new Node();
        result->data = val;
        result->left = NULL;
        result->right = NULL;
        return result;
    }
public:
    Tree(){
        root = NULL;
    }
    void show(){
        printTree("",root,false);
    }
    void createExTree(){
        root = newNode(5);
        root->left = newNode(1);
        root->left->left = newNode(11);
        root->left->right = newNode(16);
        root->left->left->right = newNode(66);
        root->right = newNode(10);
        root->left->right->left = newNode(7);
    }
    void inorder(){
        cout << "inorder : ";
        inorder_process(root);
        cout << endl;
    }
    void preorder(){
        cout << "preorder : ";
        preorder_process(root);
        cout << endl;
    }
    void postorder(){
        cout << "postorder : ";
        postorder_process(root);
        cout << endl;
    }
};

