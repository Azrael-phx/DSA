#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

class BitManipulation{
    public:
        int DecimalToBinary(int n){
            // n= 12 binAary = 1100
            int ans;
            int i=0;
            while(n!=0){
                int bit = n&1;
                //n&1 is always 0 or 1 ------ 1 & 1 = 1, 1 & 2 = 0, 1 & 3 = 1
                ans += bit*pow(10, i);
                n = n>>1;
                i++;
            }
            return ans;
        }
        int BinaryToDecimal(int n){
            int i=0, ans=0;
            while(n!=0){
                int digit = n%10;
                if(digit == 1){
                    ans+= pow(2, i);
                }
                n/=10;
                i++;
            }
            return ans;
        }
};

int sumofNumbers(int arr[], int n){
    if(n==0)
        return 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum+= arr[i];
    }
    return sum;
}

void isPrime(int n){
    if(n<=1)
        return;
    for(int i=2; i<=n; i++){
        if(n%i == 0)
            cout << i << " ";
    }
}
//algo to print prime numbers till n
void SieveOfEratosthenes(int m){
    //even though it shows error it runs 
    bool prime[m+1];
    memset(prime, true, sizeof(prime));

    for(int i=2; i*i<=m; i++){
        if(prime[i] == true){
            for(int j=i*i; j<=m; j+=i){
                prime[j] = false;
            }
        }
    }
    for (int p = 2; p <= m; p++)
        if (prime[p])
            cout << p << " ";

}

int fact(int n){
    // if(n==0 || n==1 )
    //     return 1;
    // int facto = 1;
    // for(int i=2; i<=n; i++){
    //     facto = facto*i;
    // }
    // return facto;
    return (n==0 || n==1) ? 1 : n*fact(n-1);
}
vector<int> sumProductOfnumbers(int n){
    // n = 123 sum = 1+2+3 prodcut = 1*2*3
    int sum=0, prod=1;
    while(n>0){
        int digit = n%10;
        prod*= digit;
        sum+= digit;
        n/=10;
    }
    return {sum, prod};
}

int main(){
    // int n = 1100;
    // BitManipulation obj;
    // cout << obj.BinaryToDecimal(n);
    int arr[] = {1,2,3,4,5};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 456;
    // int a = 'a';
    // cout << a;
    // n+= n+ ++n;
    // cout << n ; ans = 12 when n = 3 -- 4+4+4 when n is incremented pura operation hone se pehle hi n increment hojaega
    // vector<int> result = sumProductOfnumbers(n);
    // cout << result[0] <<" " << result[1]; 
}

// int main(){
  // size of array --  int m = sizeof(arr)/sizeof(arr[0]);
//     int t;
//     cin>>t;
//     while(t!=0){
//         int size;
//         cin>>size;
//         int arr[10];
//         for(int i=0; i<size; i++){
//             cin>>arr[i];
//         }
//         cout << sumofNumbers(arr, size);
//         t--;
//     }
// }

