#include <iostream>
#include <vector>

int main(){

    int N;
    int input;

    std::cin >> N;

    for(int i=0; i<N; i++){
        std::cin >> input;
        // 홀수, 짝수 결정
        // i=0이 홀수. i%2 == 0이 홀수. 
        if (i % 2 == 0){
            if(input % 2 == 0){
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
        else{
            if(input % 2 == 1){
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "YES" << std::endl;

    return 0;
}