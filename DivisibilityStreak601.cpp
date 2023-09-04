#include<iostream>

int gcd(int a, int b){
    while(a!=0){
        int c = a;
        a = b%a;
        b = c;
    }
    return b;
}
int lcm(int a, int b){
    int lcm = a*(b/gcd(a,b));
    return lcm;
}

unsigned long long bruteForce(unsigned long long limit, unsigned long long streak){
    unsigned long long result = 0;
    for(int i = 2 ; i< limit; i++){
        unsigned int current = 1;
        while((i+current - 1)%current ==0)
            current++;
        current--;
        if(current == streak)
            result++;
    }
    return result ;
}

int main(){
    int a, b;
    std::cin>>a;
    std::cin>>b;
    int index = gcd(a,b);
    // int lcmofab = lcm(a,b);
    // std::cout << "GCD:" << index << std::endl <<  "LCM: " << lcmofab << std::endl;
    std::cout << bruteForce(a,b) << std::endl;

}