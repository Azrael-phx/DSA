#include<iostream>
#include<queue>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                v.push_back(temp->data);
            }
            ans.push_back(v);
        }
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(15);   
    root->right->right = new TreeNode(7);

    TreeNode obj;

    vector<vector<int>> result = obj.levelOrder(root);
    
    for(const vector<int>v : result){
        for(auto element : v){
            cout << element << " ";
        }
        cout << endl;
    }

}

