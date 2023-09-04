#include<iostream>
using namespace std;

    int hammingWeight(uint32_t n, uint32_t m) {
        int count1 = 0;
        int count2 =0;
        cin >> n >> m;

        while(n>0 && m>0){
        if(n&1)
            count1++;
        n= n>>1;
        if(m&1)
            count2++;
        m = m>>1;
        }
        return (count1 + count2) ;
    }