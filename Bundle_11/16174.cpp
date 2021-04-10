#include <iostream>
#include <queue>

using namespace std;

int map[65][65] = {0, }; 
int visited[65][65] = {0, };

int N = 0;

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx, sy});

    while(!q.empty()){
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();

        if(visited[tx][ty] == 1){
            continue;
        }

        visited[tx][ty] = 1;

        if(tx == N && ty == N){
            cout << "HaruHaru";
            return;
        }

        int nx = tx + map[tx][ty];
        int ny = ty;

        if(nx <= N){
            q.push({nx, ny});
        }

        nx = tx;
        ny = ty + map[tx][ty];

        if(ny <= N){
            q.push({nx, ny});
        }
    }

    cout << "Hing";
    
    return;
}

int main(){
    cin >> N;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }

    bfs(1, 1);

    return 0;

}