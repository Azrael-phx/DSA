#include<iostream>
#include<cmath>
using namespace std;

int BiToDec(int n){
    int ans= 0;
    int i=0;
    while(n!=0){
        int digit = n%10;
        if(digit == 1)
            ans = ans + pow(2,i);
        n = n/10;
        i++;
    }
    return ans;   
}

int DecToBi(int n){
    int ans = 0;
    int i=0;
    while(n!=0){
        int bit = n&1;
        ans = bit*pow(10,i) + ans;
        n = n>>1;
        i++;
    }
    return ans;
}
int reverseInt(int n){
    int ans = 0;
    
    while(n!=0){
        int digit = n%10;
        if(ans > INT_MAX/10 || ans<INT_MIN/10)
            return 0;
        ans= (ans*10) + digit;
        n = n/10;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    // cout << "Reverse of the number is: "<<reverseInt(n);
    // cin >> n;
    cout<< "Bianry to Dec:" <<BiToDec(n) ;
}