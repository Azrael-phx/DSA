#include<iostream>

using namespace std;

int nfibonacci(int n){
    int a = 0;
    int b = 1;
    for(int i=2; i<=n; i++){
        int c = a+b;
        a = b;
        b = c;
    }
    return b;
}
int main(){
    int n = 9;
    cout << nfibonacci(n)<< endl;
}