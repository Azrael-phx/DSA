#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* BuildTree(){
    cout << "Enter the data" << endl;
    int data;
    cin>> data;
    Node*root = new Node(data);
    if(data == -1){
        return NULL;
    } 
    root->left = BuildTree();
    root->right = BuildTree();
    return root;
}
int main(){
    Node* root = NULL;
    root = BuildTree();
    return 0;
}
//program stops when all the child nodes become -1 