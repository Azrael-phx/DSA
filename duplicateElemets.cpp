#include<iostream>
#include <unordered_set>
#include<vector>

using namespace std;

vector<int> duplicateElemets(vector <int> &a, vector <int>& b, int n, int m){
    
    vector <int> ans;
    unordered_set <int> s;
    for(int i=0; i<n; i++ ){
        s.insert(a[i]);
    }

    for(int i=0; i<m; i++){
        int key = b[i];
        if(s.find(key)!=s.end()){
            ans.push_back(key);
            s.erase(key);
        }
    }
    return ans;

}
int main(){
   int n= 7;
   int m = 3;
   vector<int> a{ 1,2,1,3,2,4,3 };
   vector<int> b{1,2,3};


   vector <int> elements = duplicateElemets(a,b,7,3);
   for (auto it = elements.begin(); it != elements.end(); it++)
        cout << *it << " ";
}

