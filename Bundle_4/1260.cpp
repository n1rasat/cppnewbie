#include <iostream>
#include <queue>
#include <string.h>

int graph[1001][1001] = {0, };
int visited[1001] = {0, };

int N;
int M;
int V;

void dfs(int V){
    visited[V] = 1;
    printf("%d ", V);

    for(int j=1; j<=N; j++){
        if(graph[V][j] == 1){
            if(visited[j] == 0){
                dfs(j);
            }
        }
    }
}

void bfs(int V){
    std::queue<int> q;

    q.push(V);
    visited[V] = 1;

    while(!q.empty()){
        int temp = q.front();
        q.pop();
        printf("%d ", temp);

        for(int j=1; j<=N; j++){
            if(graph[temp][j] == 1){
                if(visited[j] == 0){
                    q.push(j);
                    visited[j] = 1;
                }
            }
        }
    }
}

int main(){

    std::cin >> N >> M >> V;

    for(int i=0; i<M; i++){
        int x, y;
        std::cin >> x >> y;

        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    dfs(V);
    printf("\n");

    memset(visited, 0, 1001 * sizeof(int));

    bfs(V);

    return 0;
}