#include <iostream>
#include <vector>

int main(){

    int N;

    std::cin >> N;

    std::vector<int> weight(N, 0);
    std::vector<int> height(N, 0);
    std::vector<int> rank(N, 1);

    for(int i=0; i<N; i++){
        std::cin >> weight[i] >> height[i];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i != j){
                //뒷 사람이 둘 다 크면
                if(weight[j] > weight[i] && height[j] > height[i]){
                    //내 등수는 1개 밀린다.
                    rank[i] += 1;
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        std::cout << rank[i] << " ";
    }

    return 0;
}