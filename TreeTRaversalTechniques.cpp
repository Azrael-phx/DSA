#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    void preOrder(Node* root){
        if(root == NULL)
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void inOrder(Node* root){
        if(root == NULL)
            return;
        preOrder(root->left);
        cout << root->data << " ";
        preOrder(root->right);
    }
    void postOrder(Node* root){
        if(root == NULL)
            return;
        preOrder(root->left);
        preOrder(root->right);
        cout << root->data << " ";
    }
};

int main(){
    Node* root = new Node(4);
    root->left = new Node(5);
    root->right = new Node(6);
    root->left->left = new Node(7);
    root->left->right = new Node(5);

    //obj mei argument pass nhi kroge to "NO INSTANCE OF CONSTRUCTOR JESA
    //ERROR AYEGA - AS IN LEVEL ORDER TRAVERSAL"
    Node obj(9999);
    cout << "Preorder traversal: ";
    obj.preOrder(root);
    cout << endl;

}