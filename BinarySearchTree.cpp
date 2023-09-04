#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;
class Node{
    public:
        int data;
        Node* right;
        Node* left;

        Node(int d){
            this->data = d;
            this->right = NULL;
            this->left = NULL;
        }
};

Node* insertIntoBST(Node* &root, int data) {
    if (root == NULL)
        root = new Node(data); 
    else if (data <= root->data)
        root->left = insertIntoBST(root->left, data); 
    else if (data > root->data)
        root->right = insertIntoBST(root->right, data);

    return root; // Return the updated root after insertion
}
//IMP -- Inorder of BST is sorted
bool validateBST(Node* root, int min, int max){
    if(root==NULL){
        return true;
    }
    if(root->data> min && root->data < max){
        bool left = validateBST(root->left, min, root->data);
        bool right = validateBST(root->right, root->data, max);
        return left&&right;
    }
    else    
        return false;
}

//Normal BST to Balanced BST -- 
/*
    step1 - convert to inorder (vector)
    step2 - inorder to BST 
*/

int kSmallestElement(Node* root, int &i, int k){
    if(root==NULL)
        return -1;

    int left = kSmallestElement(root->left, i, k);
    if(left!=-1)
        return left;
    i++;
    if(i==k)
        return root->data;
    return kSmallestElement(root->right, i, k);
}

Node* inorderToBST(vector<int> in, int s, int e){
    if(s>e)
        return NULL;
    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = inorderToBST(in, s, mid-1);
    root->right = inorderToBST(in, mid+1, e);
    return root;
}

vector<int> inOrderTraversal(Node* root, vector<int> &in) {
    if (root == NULL)
        return in;
    inOrderTraversal(root->left, in);
    in.push_back(root->data);
    inOrderTraversal(root->right, in);

    return in;
}
int main(){
    vector<int> in;
    Node* root = NULL;
    insertIntoBST(root, 45);
    insertIntoBST(root,30);
    insertIntoBST(root,76);
    insertIntoBST(root,53);
    insertIntoBST(root,25);
    inOrderTraversal(root, in);

    int i=0;
    cout << kSmallestElement(root, i, 2);

    //cout << validateBST(root, INT_MIN, INT_MAX);
}