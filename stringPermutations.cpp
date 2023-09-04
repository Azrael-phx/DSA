#include<iostream>
using namespace std;

void permute(string &S, int s, int e){
    if(s==e)
        cout << S << endl;
    else{
        for(int i=s; i<=e; i++){
            swap(S[s], S[i]);
            permute(S, s+1, e);
            //backtracking
            //another swap is used to recover our string to original world since we used a swap operation.
            swap(S[s], S[i]);
        }
    }
}

int main(){
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n-1);
    return 0;
}
