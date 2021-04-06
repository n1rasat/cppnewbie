#include <iostream>
#include <string>

int main(){
    int N;

    std::cin >> N;

    for(int i=0; i<N; i++){
        int count;
        std::string s;

        std::cin >> count >> s;

        for(auto ch : s){
            for(int j=0; j<count; j++){
                std::cout << ch;
            }
        }
        std::cout << std::endl;
    }

    return 0;
}