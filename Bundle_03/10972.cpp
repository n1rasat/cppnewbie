#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int N;

    std::cin >> N;

    std::vector<int> v;

    int flag = 0;

    for(int i=0; i<N; i++){
        int input;
        std::cin >> input;
        v.push_back(input);

        if(i>0){
            if(v[i] > v[i-1]){
                flag = 1;
            }
        }
    }

    if(flag == 0){
        std::cout << -1;
        return 0;
    }

    std::next_permutation(v.begin(), v.end());

    for(int i=0; i<v.size(); i++){
        std::cout << v[i] << " ";
    }


    return 0;
}