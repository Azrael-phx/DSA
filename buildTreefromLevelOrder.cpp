#include<iostream>
#include<queue>
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

        void buildTreeLevel(Node* root){
            queue<Node*>q;
            int data;
            cin>> data;
            root = new Node(data);
            q.push(root);

            while(!q.empty()){
                Node* temp = q.front();
                q.pop();

                int leftdata;
                cin>>leftdata;
                if(leftdata != -1){
                    temp->left = new Node(leftdata);
                    q.push(temp->left);
                }
                int rightdata;
                cin>>rightdata;
                if(rightdata != -1){
                    temp->right = new Node(rightdata);
                    q.push(temp->right);
                }
            }
        }
};
int main(){
    Node* root = NULL;
    Node obj(-1);
    obj.buildTreeLevel(root);
    return 0;
}