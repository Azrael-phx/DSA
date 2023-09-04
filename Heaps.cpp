//Heaps are complete Binary Trees with Heap Order Property
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void heapify(vector<int> arr, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left<=n && arr[left] > arr[largest])
        largest = left;
    else if(right<=n && arr[right] > arr[largest])
        largest  = right;
    
    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}
vector<int> buildHeap(vector<int> arr, int n)
{	
    //heapify or heap creation
    for(int i = n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }
    return arr;
}
void HeapSort(vector<int> arr, int n){
    int size = n;
    while(size>1){
        swap(arr[1], arr[--size]);
        size--;

        heapify(arr, size,1);
    }
}