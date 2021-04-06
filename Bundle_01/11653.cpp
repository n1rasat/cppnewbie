#include <iostream>

int main(){

    int N;

    std::cin >> N;

    int modulo = 2;

    while(1){
        if(N == 1){
            break;
        }

        if(N % modulo == 0){
            N /= modulo;
            std::cout << modulo << std::endl;
        }
        else{
            modulo += 1;
            continue;
        }

        if(N == modulo){
            std::cout << modulo;
            break;
        }
    }

    return 0;
}