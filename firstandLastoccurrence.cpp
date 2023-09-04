#include<iostream>
#include<vector>

using namespace std;

vector <int> BinarySearch( vector <int>  &arr, int n, int key){
    int start= 0;
    int end = n-1;
    int mid = (start+end)/2;

    vector <int> ans;
    while(start<=end){
        if(arr[mid]==key){
            ans.push_back(mid);
        }
        if(arr[mid]<key){
            start = mid + 1;

        }
        else
            end = mid - 1;

        mid = (start + end)/2;
    }
    return ans;
    
}

int main(){
    vector <int> even {0,0,1,1,2,2,2,2};

    BinarySearch(even, 8, 2);
    for (auto it = even.begin(); it != even.end(); it++)
        cout << *it << " ";


}
