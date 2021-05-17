#include <iostream>
#include <string>

using namespace std;

// greatest common divisor
unsigned long long gcd(unsigned long long a,unsigned long long b){
    if(a % b==0){
        return b;
    }else{
        return gcd(b, a % b);
    }
}

// least common multiple
unsigned long long lcm(unsigned long long a,unsigned long long b){
    return a*b/gcd(a,b);
}

int main(){

    unsigned long long A, B;
    cin >> A >> B;

    unsigned long long C = gcd(A, B);

    string s;

    for(unsigned long long int i = 0; i<C; i++){
        s += "1";
    }

    cout << s;

    return 0;
}