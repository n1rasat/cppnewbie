#include <iostream>

using namespace std;

int map[17][17] = {0, };

int N = 0;

int dxw[2] = {0, 1};
int dyw[2] = {1, 1};

int dxh[2] = {1, 1};
int dyh[2] = {0, 1};

int dxd[3] = {0, 1, 1};
int dyd[3] = {1, 0, 1};

int answer = 0;

// pos; 0: 가로, 1: 세로, 2: 대각선
void dfs(int sx, int sy, int pos){
    if(sx == N && sy == N){
        answer += 1;
        return;
    }
    int nx;
    int ny;

    // 가로, dxw
    if(pos == 0){
        for(int i=0; i<2; i++){
            nx = sx+dxw[i];
            ny = sy+dyw[i];

            if(nx > N || ny > N)
                continue;

            if(i == 0){
                if(map[nx][ny] == 1)
                    continue;
                dfs(nx, ny, 0);
            }
            else if(i == 1){
                if(map[sx+1][sy] == 1 || map[sx][sy+1] == 1 || map[nx][ny] == 1 )
                    continue;
                dfs(nx, ny, 2);
            }
        }
    }
    // 세로, dxh
    else if(pos == 1){
        for(int i=0; i<2; i++){
            nx = sx+dxh[i];
            ny = sy+dyh[i];

            if(nx > N || ny > N)
                continue;

            if(i == 0){
                if(map[nx][ny] == 1)
                    continue;
                dfs(nx, ny, 1);
            }
            else if(i == 1){
                if(map[sx+1][sy] == 1 || map[sx][sy+1] == 1 || map[nx][ny] == 1 )
                    continue;
                dfs(nx, ny, 2);
            }
        }
    }
    // 대각선, dxd
    else if(pos == 2){
        for(int i=0; i<3; i++){
            nx = sx+dxd[i];
            ny = sy+dyd[i];

            if(nx > N || ny > N)
                continue;

            if(i == 0){
                if(map[nx][ny] == 1)
                    continue;
                dfs(nx, ny, 0);
            }
            else if(i == 1){
                if(map[nx][ny] == 1)
                    continue;
                dfs(nx, ny, 1);
            }
            else if(i == 2){
                if(map[sx+1][sy] == 1 || map[sx][sy+1] == 1 || map[nx][ny] == 1 )
                    continue;
                dfs(nx, ny, 2);
            }
        }
    }

    return;
}

int main(){
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j]; 
        }
    }
    dfs(1, 2, 0);

    cout << answer;

    return 0;
}