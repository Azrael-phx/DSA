#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<set>

using namespace std;

void reverseArray(int arr[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        swap(arr[s++], arr[e--]);
    }
}

void swapAlternate(int arr[], int n){
    for(int i=0; i<n; i+=2){
        if(i+1<n)
            swap(arr[i], arr[i+1]);
    }
}

int findUnique(int arr[], int n){
    //assuming we always have only one unique element
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans^arr[i];
    }
    return ans;
}

int findDuplicate(vector<int> &arr) 
{
    //assuming only one duplicate is present 
     int ans=0;
    for(int i=0;i<arr.size();i++){
        ans=ans^arr[i];
    }
    cout << ans << " ";
    for(int i=1;i<arr.size();i++){
        ans=ans^i;
    }
    cout << ans << " ";
    return ans;
}
vector<int> printAllDuplicates(vector<int>& arr, int n){
    map<int, int>mp;
    //ordered_map == map
    vector<int> ans;
    for(auto i: arr){
        mp[i]++;
    }
    for(auto i: mp){
        if(i.second == 2)
            ans.push_back(i.first);
    }
    return ans;
}

//Two pointer Approach
vector<int> intersectionOFtwoArrays(int arr1[], int arr2[], int m, int n){
    // //apply Two pointer given the array "is sorted "
    //approach applicable if we have duplicate elements
    // vector<int> ans;
    // int i=0, j=0;
    // while(i<n && j <m){
    //     if(arr1[i] == arr2[j]){
    //         ans.push_back(arr1[i]);
    //         i++;
    //         j++;
    //     } 
    //     else if( arr1[i] < arr2[j])
    //         i++;
    //     else   
    //         j++;
    // }
    // return ans;

    //Approach - 2 Using hashmap -- common elements nikalne hain
    unordered_set<int> s;
    vector<int> ans;
    for(int i=0; i<n; i++){
        s.insert(arr1[i]);
    }
    for(int i=0; i<m; i++){
        if (s.find(arr2[i]) != s.end()){
            ans.push_back(arr2[i]);
            s.erase(arr2[i]); // 1 3 4 4 output ki jagah 1 3 4 output mile isiliye esa kia 
        }
    }
    return ans;
}

unordered_set<int> unionOFArrays(int arr1[], int arr2[], int n, int m){
    // arr1 = {1,2,3,3,4} arr2 = {2,3,4,4,5} union = {1,2,3,4} -- we dont want duplicate elements
    //unordered_multiset<int> s;// multi set means it can contain same element multiple times
    vector<int> ans;
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        s.insert(arr1[i]);
    }
    for(int i=0; i<m; i++){
        s.insert(arr2[i]);
    }
    return s;
}

vector<vector<int>> pairSum(vector<int> &arr, int k, int n){
    //Approach -1 
    //find the two integers whose sum equal to k 
    // {1,2,3,4,5} k = 5 == O/P {1,4} & {2,3}
    // vector<vector<int>>ans;
    // for(int i=0; i<n; i++){
    //     for(int j=i+1; j<n; j++){
    //         if(arr[i]+arr[j] == k)
    //             ans.push_back({arr[i], arr[j]});
    //     }
    // }
    // return ans;

    //Approach - 2 -- using hashmap 
    unordered_map<int, int>mp;
    vector<vector<int>> ans;
    for(auto i : arr){
        mp[i]++;
    }

    for(auto i: arr){
        int target = k - i;
        if(mp.find(target)!= mp.end()){
            ans.push_back({i, target});
        }
        mp[arr[i]] = i;
    }
    return ans;
}

vector<vector<int>> findTriplets(vector<int> arr, int n, int sum){
    // given k=12, {1,2,3,4,5} O/P = {5,4,3} == 5+4+3 = 12
    //Approach -1 == Three loops O(n3) complexity

    //Approach - 2  == Two Pointer Approach 
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i= 0; i<n-2; i++){
        int s = i+1;
        int e = n-1;
        while(s<e){
            if(arr[i]+arr[s]+arr[e] == sum){
                ans.push_back({arr[i], arr[s], arr[e]});
                s++;
                e--;
            }
            else if(arr[i]+arr[s] + arr[e] < sum){
                s++;
            }
            else    
                e--;
        }
    }
    return ans;
}

int main(){
    vector<int>arr = { 1, 4, 45, 6, 10, 8 };
    int n = arr.size();
    vector<vector<int>>ans = findTriplets(arr,n, 22);

    for(const vector<int>v : ans ){
        for(auto element : v){
            cout << element << " ";
        }
        cout << endl;
    }
    // int arr1[] = {1,2,3};
    // int arr2[] = {4,7};

    // int n = sizeof(arr1)/sizeof(arr1[0]);
    // int m = sizeof(arr2)/sizeof(arr2[0]);
    // // reverseArray(arr , n);
    // // swapAlternate(arr, n);
    // // for(int i=0; i<n; i++){
    // //    cout << arr[i];
    // // }
    // // vector<int> arr = {1,1,2,3,3};
    // // int n = arr.size();
    // // vector<int> duplicates = printAllDuplicates(arr, n);
    // // for(auto i: duplicates)
    // //     cout << i << " ";
    // vector<int> ans = intersectionOFtwoArrays(arr1, arr2, n, m);
    // for (int x : ans)
    //     cout << x << " ";

    // unordered_set<int> s = unionOFArrays(arr1, arr2, n, m);
    // for(auto i : s)
    //     cout << i << " ";
}