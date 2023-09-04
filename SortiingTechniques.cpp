#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bubbleSort(int arr[], int n){

}

void insertSort(int arr[], int n){
    //current element ko piche wale elements se comapre karna
    //aur uski sahi position par pkace krna 

    vector<int> ans;
    ans.push_back(arr[0]);
    for(int i=1; i<n; i++){
        int temp = arr[i];
        int j=i-1;
        for(; j>=0; j--){
            if(temp < arr[j])
               arr[j+1] = arr[j];
            else
                break;
        } 
        arr[j+1] = temp;
    }
}

vector<int> selectSort(int arr[], int n){
    vector<int> ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[i]){
                swap(arr[i], arr[j]);
            }
        }
        ans.push_back(arr[i]);
    }
    return ans;   
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectSort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
}