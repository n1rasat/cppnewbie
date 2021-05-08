#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

int map[11][11] = {0, };
int N, M, H;
int sx, sy;

int answer = 0;
vector<pair<int, int>> milk;

void dfs(int x, int y, int hp, int cnt){

    if(abs(x-sx) + abs(y-sy) <= hp){
        if(cnt > answer)
            answer = cnt;
    }

    for(int i=0; i<milk.size(); i++){
        int milkx = milk[i].first;
        int milky = milk[i].second;

        //아직 안 먹은 민초
        if(map[milkx][milky] == 2){
            int D = abs(x-milkx) + abs(y-milky);
            if(D <= hp){
                // 먹고 초기화
                map[milkx][milky] = 0;
                dfs(milkx, milky, hp+H-D, cnt+1);
                map[milkx][milky] = 2;
            }
        }
    }

    return;
}

int main(){
    cin >> N >> M >> H;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> map[i][j];

            if(map[i][j] == 1){
                sx = i;
                sy = j;
            }
            
            if(map[i][j] == 2){
                milk.push_back({i, j});
            }
        }
    }

    dfs(sx, sy, M, 0);
    
    cout << answer;

    return 0;
}