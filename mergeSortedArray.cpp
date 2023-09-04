#include<iostream>

using namespace std;

//do it in o(1) space
void mergeArray(int arr1[], int arr2[], int n, int m){
    //merge the two arrays into one array
    int i=0;
    while(arr1[i]!=0 && i<n){
        i++;
    }
    int j=0;
    for(j=0; j<m; j++){
        arr1[i++] = arr2[j];
    }
}

int main(){
    int arr1[] = {1,2,3, 0, 0, 0};
    int arr2[] = {4,5,6};

    int n = 6;
    int m = 3;
    mergeArray(arr1, arr2, n, m);

    for(int i=0; i<n; i++){
        cout << arr1[i] << " ";
    }
}