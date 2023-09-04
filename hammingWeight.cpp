#include<iostream>
using namespace std;

int hW(int n){
    //count no. of 1 bits 
    int count = 0;
    while(n>0){
        if(n&1)
        // 1&1 = 1 , 1&0=0&1=0&0==0
            count++;
        n = n >> 1;
    }
    return count;
}

int main(){
    int n = 5;
    cout << hW(n);
}