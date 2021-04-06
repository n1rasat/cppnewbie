#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int N, M;

int map[101][101] = {0, };
int visited[101] = {0, };
int answer_arr[101] = {0, };

void bfs(int V){   
    queue<pair<int, int>> q;
    q.push({V, 0});
    visited[V] = 1;

    int sum = 0;

    while(!q.empty()){
        int temp = q.front().first;
        int temp_depth = q.front().second;
        q.pop();

        for(int i=1; i<=N; i++){
            if(map[temp][i] == 1 && visited[i] == 0){
                q.push({i, temp_depth+1});
                visited[i] = 1;
                sum += temp_depth+1;
            }
        }
    }

    answer_arr[V] = sum;
}

int main(){
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1; 
    }

    int answer_temp = 987654321;
    int answer = 0;

    for(int i=1; i<=N; i++){
        bfs(i);
        memset(visited, 0, (N+1)*sizeof(int));
    }

    for(int i=1; i<=N; i++){
        // cout << answer_arr[i] << " ";
        if(answer_arr[i] < answer_temp){
            answer_temp = answer_arr[i];
            answer = i;
        }
    }
    // cout << "\n";
    
    cout << answer;
    
    return 0;
}