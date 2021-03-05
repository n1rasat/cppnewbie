#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> shipp;
std::vector<int> boxx;

int main(){

    int N;

    std::cin >> N;

    for(int i=0; i<N; i++){
        int x;
        scanf("%d", &x);
        shipp.push_back(x);
    }

    int M;

    std::cin >> M;

    for(int i=0; i<M; i++){
        int x;
        scanf("%d", &x);
        boxx.push_back(x);
    }

    std::sort(shipp.begin(), shipp.end(), std::greater<int>());
    std::sort(boxx.begin(), boxx.end(), std::greater<int>());

    int box_count = 0;
    int playtime = 0;

    if(boxx[0] > shipp[0]){
        std::cout << -1;
        return 0;
    }

    while(1){
        // 남은 박스가 없으면 종료
        if(boxx.empty()){
            break;
        }

        int i=0;
        int j=0;

        while(i < N){
            // 박스 끝까지 봤으면 종료
            if(j == boxx.size()){
                break;
            }
            if(shipp[i] >= boxx[j]){
                boxx.erase(boxx.begin()+j);
                i++;
            }
            else if(shipp[i] < boxx[j]){
                j++;
            }
        }
        playtime += 1;
    }

    std::cout << playtime;

    return 0;
}