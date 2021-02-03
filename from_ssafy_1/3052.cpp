#include <iostream>
#include <set>

int main(){

    std::set<int> remainder;

    int N;
    for(int i=0; i<10; i++){
        std::cin >> N;
        N = N % 42;
        remainder.insert(N);
    }
    std::cout << remainder.size() << std::endl;

    return 0;
}