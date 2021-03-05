#include <iostream>
#include <algorithm>

int ship[51];
int box[10001];
int visited[10001] = {0, };

int main(){

    int N;

    std::cin >> N;

    for(int i=0; i<N; i++){
        int x;
        std::cin >> x;
        ship[i] = x;
    }

    int M;

    std::cin >> M;

    for(int i=0; i<M; i++){
        int x;
        std::cin >> x;
        box[i] = x;
    }

    std::sort(ship, ship+50, std::greater<int>());
    std::sort(box, box+10000, std::greater<int>());

    int box_count = 0;
    int playtime = 0;

    if(box[0] > ship[0]){
        std::cout << -1;
        return 0;
    }

    while(1){
        if(box_count == M){
            break;
        }

        for(int i=0; i<N;i++){
            for(int j=0; j<M; j++){
                // visited == 0 이고 ship >= box면 visited == 1로 하고 다음 박스로
                if(visited[j] == 0 && ship[i] >= box[j]){
                    visited[j] = 1;
                    box_count += 1;
                    // 다음 배로
                    i += 1;
                }
                else{
                    continue;
                }
            }
        }
        playtime += 1;
    }

    std::cout << playtime;


    return 0;
}