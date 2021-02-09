#include <iostream>
#include <string>

int main(){
    int N;

    std::cin >> N;

    int flag = 0;
    std::string s;

    int accumulate = 0;
    int sum = 0;
    for(int i=0; i<N; i++){
        std::cin >> s;

        for(auto OX : s){
            if(OX == 'O'){
                accumulate += 1;
                sum += accumulate;
            }
            else{
                accumulate = 0;
            }
        }
        std::cout << sum << std::endl;
        sum = 0;
        accumulate = 0;
    }

    return 0;
}