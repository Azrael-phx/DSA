#include<iostream>
using namespace std;


void pattern1(int n){
    for(int i=1; i<=n; i++){
        cout << "i=" << i <<" ";
        for(int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern2(int n){
    for(int i=n; i>=0; i--){
        cout << "i=" << i <<" ";
        for(int j=1; j<=i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
}
void pattern3(int n){
    for(int i=n; i>=0; i--){
        cout << "i=" << i <<" ";
        for(int j=n; j>=i; j--){
            cout << j << " ";
        }
        cout << endl;
    }
}

void pattern4(int n){
    for(int i=n; i>=0; i--){
        cout << "i=" << i <<" ";
        for(int j=0; j<=n; j++){
            if(j>=i)
                cout << j;
            else
                cout << ' ' ;
        }
        cout << endl;
    }
}
void pattern5(int n){
    for(int i=n; i>=0; i--){
        cout << "i=" << i <<" ";
        for(int j=0; j<=n; j++){
            if(j>=i)
                cout << '*';
            else
                cout << '_' ;
        }
        cout << endl;
    }
}

int main(){
    int n = 5;
    pattern1(n);
}