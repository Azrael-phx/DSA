#include<iostream>
using namespace std;
void swapAlternate(int arr[], int size){
    
    for(int i = 0; i< size; i=i+2){
        if(i+1 < size){
            swap(arr[i], arr[i+1]);
        }
    }
    for(int i=0; i<size; i++)
        cout<< arr[i]<< " ";

}
int main(){

   int even[6] = {1,2,3,4,5,6};
   int odd[5] = {1,2,3,4,5};

   swapAlternate(odd, 5);
    
}

