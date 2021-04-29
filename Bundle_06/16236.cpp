#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;


int map[21][21] = {0, };
int visited[21][21] = {0, };
int N;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bulk = 2;
int eat = 0;
int time = 0;

int bfs(int sx, int sy, int vx, int vy, int step){
    queue<pair<int, pair<int, int>>> q;
    q.push({step, {sx, sy}});
    visited[sx][sy] = 1;

    int temp = 987654321;

    while(!q.empty()){
        int s = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;

        q.pop();

        if(x == vx && y == vy){
            if(s < temp){
                // 거리를 계속해서 갱신해준다.
                temp = s;
            }
        }

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > N || ny < 1 || ny > N)
                continue;

            if(visited[nx][ny] == 1)
                continue;

            if(map[nx][ny] > bulk)
                continue;

            q.push({s+1, {nx, ny}});
            visited[nx][ny] = 1;

        }        
    }    

    return temp;
}

int main(){
    cin >> N;
    int answer = 0;

    vector<pair<int, pair<int, int>>> v;

    int sx, sy;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];

            if(map[i][j] == 9){
               sx = i;
               sy = j; 
               // 내 위치는 0
               map[i][j] = 0;
            }
            else if(map[i][j] != 0){
                v.push_back({map[i][j], {i, j}});
            }
        }
    }

    while(1){
        sort(v.begin(), v.end());

        int ti = 0;
        int ts = 987654321;
        int tx = 0;
        int ty = 0;

        for(int i=0; i<v.size(); i++){
            if(v[i].first < bulk){
                int vx = v[i].second.first;
                int vy = v[i].second.second;
                int vs = bfs(sx, sy, vx, vy, answer);

                // 거리가 더 작은 물고기
                // 거리가 같으면 x값이 작은 물고기
                // x값이 같으면 y값이 더 작은 물고기
                if(vs < ts){
                    // 거리가 더 짧은 곳
                    ti = i;
                    ts = vs;
                    tx = vx;
                    ty = vy;
                }
                else if(vs == ts){
                    // x가 더 작은 곳
                    if(vx < tx){
                        ti = i;
                        ts = vs;
                        tx = vx;
                        ty = vy;
                    }
                    else if(vx == tx){
                        // y가 더 작은 곳
                        if(vy < ty){
                            ti = i;
                            ts = vs;
                            tx = vx;
                            ty = vy;
                        }
                    }
                }
                memset(visited, 0, sizeof(visited));
            }
        }

        // 상어 위치 옮기기
        sx = tx;
        sy = ty;

        if(ts == 987654321)
            break;

        // vector에서 ti번째 원소를 지운다(먹는다)
        v.erase(v.begin()+ti);
        map[tx][ty] = 0;

        // eat + 1 하고 eat == size면 size += 1한다.
        eat += 1;
        if(eat == bulk){
            eat = 0;
            bulk += 1;
        }

        // 현재까지 거리 갱신
        answer = ts;
    }

    cout << answer;

    return 0;

}