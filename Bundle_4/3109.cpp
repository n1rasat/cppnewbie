#include <iostream>

using namespace std;

int arr[10001][501] = {0, };
int visited[10001][501] = {0, };

int R = 0;
int C = 0;

int cnt = 0;

int dfs(int x, int y){
    if(y == C-1){
        visited[x][y] = 1;
        return 1;
    }
    else{
        for(int i=0; i<3; i++){
            int next_x = x+i-1;
            int next_y = y+1;

            if(next_x < 0 || next_x > R-1) continue;
            if(next_y < 0 || next_y > C-1) continue;
            if(arr[next_x][next_y] == 1) continue;
            if(visited[next_x][next_y] == 1) continue;

            visited[x][y] = 1;

            if(dfs(next_x, next_y) == 1) {
                return 1;
            }
        } 

        visited[x][y] = 1;
        return 0;
    }
}


int main(){

    cin >> R >> C;

    getchar();
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            char ch;
            ch = getchar();
            if(ch == 'x'){
                arr[i][j] = 1;
                visited[i][j] = 1;
            }
        }
        getchar();
    }

    for(int i=0; i<R; i++){
        cnt += dfs(i, 0);
    }

    printf("%d", cnt);

    return 0;
}