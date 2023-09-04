#include<iostream>
using namespace std;
void sumofArray(int arr[], int size){
    int sum =0;
    
    for(int i =0; i<size; i++){
        sum = sum + arr[i];   
    }
    cout<< sum << endl;
    
}
int main(){

   int size;
   cin>>size;
    int num[10];

    for(int i=0; i<size; i++){
        cin>> num[i];
    }

   sumofArray(num,size);
    
}

