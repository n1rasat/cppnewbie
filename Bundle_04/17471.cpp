#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int graph[11][11];
int people[11];
int region[11];

int N;

int answer = 987654321;

int bfs(std::vector<int>& region){
    int visited[11] = {0, };
    std::queue<int> q;

    visited[region[0]] = 1;

    q.push(region[0]);

    while(!q.empty()){
        int temp = q.front();
        q.pop();

        for(int i=1; i<=N; i++){
            // 연결된 vertex가 있으면
            if(graph[temp][i] == 1){
                if(visited[i] == 1){
                    continue;
                }
                
                if(std::binary_search(region.begin(), region.end(), i)){
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    for(int i=0; i<region.size(); i++){
        if(visited[region[i]] == 0){
            return 0;
        }
    }
    
    return 1;
}

int main(){
    std::cin >> N;

    for(int i=1; i<=N; i++){
        int x;
        std::cin >> x;
        people[i] = x;
    }

    // 선거구 수 만큼
    for(int i=1; i<=N; i++){
        int x;
        std::cin >> x;
        for(int j=0; j<x; j++){
            int y;
            std::cin >>y;
            
            // make graph
            graph[i][y] = 1;
            graph[y][i] = 1;
        }
    }

    // bitmask로 combination
    for(int bit=1; bit < (1 << N)-1; bit++){
        std::vector<int> red, blue;
        for(int i=0; i<N; i++){
            // bit == 1: red
            // bit == 0: blue
            if(bit & 1 << i){
                red.push_back(i+1);
            }
            else{
                blue.push_back(i+1);
            }
        }

        if(bfs(red) && bfs(blue)){
            int diff = 0;

            for(int i=0; i<red.size(); i++){
                diff += people[red[i]];
            }
            
            for(int i=0; i<blue.size(); i++){
                diff -= people[blue[i]];
            }
            diff = abs(diff);

            if(answer > diff){
                answer = diff;
            }
        }
    }

    if(answer == 987654321){
        std::cout << -1;
        return 0;
    }

    std::cout << answer;


    return 0;
}