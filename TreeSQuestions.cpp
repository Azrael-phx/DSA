#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

int countLeafNodes(Node* &root){
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    // Otherwise, recursively count leaf nodes in left and right subtrees
    int leftCount = countLeafNodes(root->left);
    int rightCount = countLeafNodes(root->right);
    // Return the sum of leaf nodes from both subtrees
    return leftCount + rightCount;
}

int heightOFBinaryTree(Node* root){
    if(root==NULL)
        return 0;

    int left = heightOFBinaryTree(root->left);
    int right = heightOFBinaryTree(root->right);
    return max(left , right ) + 1;
}

pair<int, int> diameterOFBinaryTree(Node* root){
    //Approach - 1 --- simple Appraoch of recursion using height function - extra tc
    // if(root==NULL)
    //     return 0;
        //function returns int 
    // int left = diameterOFBinaryTree(root->left);
    // int right =diameterOFBinaryTree(root->right);
    // int case3 = heightOFBinaryTree(root->left) + heightOFBinaryTree(root->right)+1;
    // return max(left, max(right, case3));

    //Approach - 2 Uisng Pair<int, int> to store height and diameter - no height function
    if(root==NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameterOFBinaryTree(root->left);
    pair<int,int> right = diameterOFBinaryTree(root->right);

    int case1 = left.first;
    int case2 = right.first; //first refers to diameter
    int case3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(case1, max(case2, case3));
    ans.second = max(left.second, right.second)+1;

    return ans;
}

//Check for balanced Tree - height(left) - height(right) <= 1
bool checkForBalancedTree(Node* root){
    if(root==NULL)
        return true;

    int leftSubtree = checkForBalancedTree(root->left);
    int rightSubtree = checkForBalancedTree(root->right);
    
    bool diff = abs(heightOFBinaryTree(root->left) -heightOFBinaryTree(root->right))<=1;
    if(leftSubtree&& rightSubtree && diff)
        return true;
    else
        return false;
}
//Determine if two trees are identical

bool checkIdentical(Node* r1, Node* r2){
    if(r1==NULL || r2==NULL){
        return true;
    }
    if(r1==NULL && r2!=NULL){
        return false;
    }
    if(r1!=NULL && r2==NULL){
        return false;
    }

    int left = checkIdentical(r1->left, r2->left);
    int right = checkIdentical(r1->right, r2->right);

    bool check = r1->data == r2->data;
    return (check && left && right)?true:false ;
}

pair<bool, int> sumTree(Node* root){
    if(root==NULL){
        pair<bool, int> p = make_pair(0,0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }
    //first represent boolean if left + right == root second is the sum 
    pair<int,int> leftAns = sumTree(root->left);
    pair<int,int> rightAns = sumTree(root->right);

    int left = leftAns.first;
    int right = rightAns.first;

    bool condition = root->data == (leftAns.second + rightAns.second);
    pair<bool,int> ans;
    if(left&&right&& condition){
        ans.first = true;
        ans.second = 2*root->data; //bcz left+right subtree are equal to root
    }
    else   
        ans.first = false;
    return ans;
}

//My Appraoch for zig zag traversal
// void zigZagTraversalHelper(Node* root, int level, vector<int>& ans, bool leftToRight) {
//     if (root == NULL)
//         return;
//     if (level == 0) {
//         ans.push_back(root->data);
//         return;
//     }
//     if (leftToRight) {
//         zigZagTraversalHelper(root->left, level - 1, ans, leftToRight);
//         zigZagTraversalHelper(root->right, level - 1, ans, leftToRight);
//     } else {
//         zigZagTraversalHelper(root->right, level - 1, ans, leftToRight);
//         zigZagTraversalHelper(root->left, level - 1, ans, leftToRight);
//     }
// }
// vector<int> zigZagTraversal(Node* root){
//     vector<int> ans;
//     int height = heightOFBinaryTree(root);
//     int i=0;
//     while(i< height){
//         if (i % 2 == 0) {
//             // Traverse left to right
//             zigZagTraversalHelper(root, i, ans, true);
//         } else {
//             // Traverse right to left
//             zigZagTraversalHelper(root, i, ans, false);
//         ans.push_back(root->data);
//         }
//     }
//     return ans;
// }

vector<int> zigZagTraversal(Node* root){
    vector<int>result;
    queue<Node*>q;
    if(root==NULL)
        return result;
    q.push(root);
    bool leftToRight = true;
    while(!q.empty()){
        int size = q.size();
        vector<int>ans(size);
        for(int i=0; i<size; i++){            
            Node* temp = q.front();
            q.pop();

            int index = leftToRight? i : size-i-1;
            ans[index] = temp->data;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        leftToRight=!leftToRight;
        for(auto i: ans)
            result.push_back(i);
    }
    return result;
}

vector<int> VerticalOrderTraversal(Node*root){
    vector<int>ans;
    map<int, map<int, vector<int>>> mp;
    // map -- horizontal dist, level , list of elements in that level
    queue<pair<Node*, pair<int,int>>> q;
    
    if(root==NULL)
        return ans;
    q.push(make_pair(root, make_pair(0,0)));
    while(!q.empty()){
        pair<Node*, pair<int, int>> p = q.front();
        q.pop();

        Node* frontNode = p.first;
        int hd = p.second.first;
        int level = p.second.second;

        mp[hd][level].push_back(frontNode->data);
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
    }
    for(auto i: mp){
        for(auto j: i.second){
            for(auto k: j.second)
            ans.push_back(k);
        }
    }
    return ans;
}

Node* leastCommonAncestor(Node* root, int n1, int n2){
    if(root==NULL){
        return NULL;
    }

    if(root->left == NULL || root->right == NULL){
        return root;
    }

    Node* leftAns = leastCommonAncestor(root->left, n1, n2);
    Node* rightAns = leastCommonAncestor(root->right, n1, n2);

    if(leftAns!=NULL || rightAns==NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns!=NULL)
        return rightAns;
    else if(leftAns!=NULL && rightAns != NULL)
        return root;
    else    
        return NULL;
}



int main(){
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->left->left = new Node(15);
    root->left->right = new Node(7);
    root->right->left = new Node(14);
    root->right->right = new Node(69);
    // root->left->left->right = new Node(3);
    // root->left->left->left = new Node(3);

    // pair<int,int> p =  diameterOFBinaryTree(root);
    // cout << p.first ;
    // cout << checkForBalancedTree(root);

    // pair<bool, int> p = sumTree(root);
    // cout << p.first << " " << p.second << endl;

    // vector<int> ans = zigZagTraversal(root);
    // for(auto i : ans){
    //     cout << i << " ";
    // }
    // vector<int>v =  VerticalOrderTraversal(root);
    // for(auto i: v)
    //     cout << i << " ";

    Node* temp = leastCommonAncestor(root, 14, 69);
    cout << temp->data;
}
