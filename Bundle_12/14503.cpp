#include <iostream>
#include <queue>

using namespace std;

int N, M;
            // 북, 동, 남, 서
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int map[51][51] = {0, };
int visited[51][51] = {0, };
int sx, sy, sd;

int answer = 0;

void dfs(int sx, int sy, int sd){
    if(visited[sx][sy] == 0){
        //visited check를 해주는데?
        visited[sx][sy] = 1;
        answer += 1;
    }
    int gocheck = 0;

    for(int i=0; i<4; i++){
        // 왼쪽을 본다
        int nd = sd-(i+1);
        if(nd < 0)
            nd += 4;

        int nx = sx + dx[nd];
        int ny = sy + dy[nd];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        // 벽
        if(map[nx][ny] == 1)
            continue;

        // 이미 청소
        if(visited[nx][ny] == 1)
            continue;

        dfs(nx, ny, nd);  
    }

    // 후진방향
    int nd = sd-2;
    if(nd < 0)
        nd += 4;

    int nx = sx + dx[nd];
    int ny = sy + dy[nd];
    
    if(map[nx][ny] == 1){
        // cout <<"sx, sy, sd: " << sx << " " <<sy << " " << sd << "\n";
        cout << answer << "\n";
        // exit(0); 이 아니고 return; 으로 해버리면 모든 0을 세기 때문에 안된다. 
        // return;
        exit(0);
    }
    else{
    // 방향 유지하면서 후진
        dfs(nx, ny, sd);
    }

    return;
}

int main(){
    cin >> N >> M;

    cin >> sx >> sy >> sd;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }

    dfs(sx, sy, sd);

    return 0;
}