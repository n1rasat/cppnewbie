#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int map[9][9] = {0, };
int temp[9][9] = {0, };
int visited[9][9] = {0, };
int N, M;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;
queue<pair<int, int>> tq;

void bfs(){
    int tqsize = tq.size();

    while(tqsize--){
        int x = tq.front().first;
        int y = tq.front().second;

        tq.pop();

        visited[x][y] = 1;

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > N || ny < 1 || ny > M)
                continue;

            if(visited[nx][ny] == 1 || temp[nx][ny] != 0)
                continue;

            temp[nx][ny] = 2;
            tq.push({nx, ny});
        }
    }
}

int main(){
    cin >> N >> M;

    vector<pair<int, int>> v;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
            if(map[i][j] == 2){
                q.push({i, j});
            }
            else if(map[i][j] == 0){
                v.push_back({i, j});
            }
        }
    }

    vector<int> filter;

    for(int i=0; i<3; i++){
        filter.push_back(1);
    }
    for(int i=3; i<v.size(); i++){
        filter.push_back(0);
    }

    sort(filter.begin(), filter.end());

    int answer = 0;

    do{
        memcpy(temp, map, sizeof(map));
        tq = q;
        for(int i=0; i<filter.size(); i++){
            if(filter[i] == 1){
                int tx = v[i].first;
                int ty = v[i].second;
                temp[tx][ty] = 1;
            }
        }

        // temp로 bfs를 돌린다. 
        while(!tq.empty()){
            bfs();
        }

        int cnt = 0;

        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                if(temp[i][j] == 0){
                    cnt += 1;
                }
            }
        }
        if(cnt > answer)
            answer = cnt;

        memset(visited, 0, sizeof(visited));

    }while(next_permutation(filter.begin(), filter.end()));

    cout << answer;

    return 0;

}