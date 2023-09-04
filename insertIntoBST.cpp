#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node*right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* inserIntoBST(Node* root, int data){
    if(root==NULL)
        return new Node(data); 
    
    if(data < root->data)
        root->left = inserIntoBST(root->left, data);
    else if(data > root->data)
        root->right = inserIntoBST(root->right, data);

    return root;
}

Node* minValue(Node* root){
    if(root==NULL)
        return NULL;
    Node* temp = root;
    while(temp->left!=NULL){
        temp = temp->left;
    }
    return temp;
}

int main(){
    Node* root = NULL;
    
    int data;
    cin>> data;
    while(data!=-1){
        root = inserIntoBST(root, data);
        cin>>data;
    }
    cout << endl;
    Node* temp = minValue(root);
    cout << temp->data;
}