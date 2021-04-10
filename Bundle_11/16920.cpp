#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int map[1001][1001] = {0, };

// 상하좌우
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M, P;
int D[10] = {0, };

queue<pair<int, int>> q[10];
int answer[10] = {0, };

void bfs(int p){
    // 거리만큼 움직일 수 있다. 도중에 방향전환 가능
    for(int i=1; i<=D[p]; i++){
        if(q[p].empty())
            return;

        //현재 있는 성만 움직여야된다.
        int now_castle = q[p].size();

        while(now_castle--){
            int x = q[p].front().first;
            int y = q[p].front().second;
            q[p].pop();

            for(int j=0; j<4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx < 1 || nx > N || ny < 1 || ny > M)
                    continue;

                if(map[nx][ny] != 0)
                    continue;

                map[nx][ny] = p;
                answer[p] += 1;
                q[p].push({nx, ny});
            }
        }
    }

    return;
}

int main(){
    cin >> N >> M >> P;

    for(int i=1; i<=P; i++){
        cin >> D[i];
    }

    getchar();

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            char ch = getchar(); 
                if(ch == '.'){
                    map[i][j] = 0;
                }
                else if(ch == '#'){
                    map[i][j] = -1;
                }
                else{
                    map[i][j] = ch-48;
                    q[ch-48].push({i, j});
                    answer[ch-48] += 1;
                }
        }
        getchar();
    }

    while(1){
        int flag = 0;
        for(int i=1; i<=P; i++){
            if(!q[i].empty()){
                bfs(i);
            }
            else{
                flag += 1;
                if(flag == P)
                    break;
            }
        }
        if(flag == P){
            break;
        }
    }
    
    for(int i=1; i<=P; i++){
        cout << answer[i] << " ";
    }

    return 0;
}