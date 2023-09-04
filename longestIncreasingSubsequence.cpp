#include<iostream>
#include<string>
#include<unordered_map>
#include<vector>
#include<Algorithm>

using namespace std;

int longestSubsequence(int n, int a[])
    { 
      vector<int>dp; 
      
      dp.push_back(a[0]); 
      
      for(int i=1; i<n; i++){  
          int s=dp.size(); 
          if(a[i]>dp[s-1]) 
            dp.push_back(a[i]); 
          else{
            auto it=lower_bound(dp.begin(),dp.end(),a[i]); 
            *it=a[i]; 
          } 
      }  
      return dp.size(); 
    }

int main(){

  int n = 8;
  int a[] = {10, 22, 9, 33, 21, 50, 41, 60};

  vector<int> ans;
  int result = longestSubsequence(n,a);
  cout << result;
  // for(auto it: ans){
  //   cout << it << " ";
  // }
}