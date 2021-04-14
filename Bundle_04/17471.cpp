#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int map[11][11] = {0, };
int people[11] = {0, };
int visited[11] = {0, };
int N;
int answer = 987654321;

int bfs(vector<int> land){
    queue<int> q;

    q.push(land[0]);
    visited[land[0]] = 1;

    while(!q.empty()){
        int temp = q.front();

        q.pop();

        for(int i=1; i<=N; i++){
            if(map[temp][i] == 0)
                continue;

            if(visited[i] == 1)
                continue;

            if(binary_search(land.begin(), land.end(), i)){
                visited[i] = 1;
                q.push(i);
            }
            
        }
    }

    for(int i=0; i<land.size(); i++){
        if(visited[land[i]] == 0){
            return 1;
        }
    }

    return 0;
}

int main(){
    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> people[i];
    }

    for(int i=1; i<=N; i++){
        int x;
        cin >> x;
        for(int j=0; j<x; j++){
            int y;
            cin >> y;
            map[i][y] = 1;
            map[y][i] = 1;
        }
    }
    
    int perm = 1;

    while(1){
        if(perm > N/2)
            break;

        vector<int> filter;

        for(int i=0; i<perm; i++){
            filter.push_back(1);
        }
        for(int i=perm; i<N; i++){
            filter.push_back(0);
        }

        sort(filter.begin(), filter.end());

        do{
            // 1: red; 0: blue;
            vector<int> red;
            vector<int> blue;
            for(int i=0; i<N; i++){
                if(filter[i] == 1){
                    red.push_back(i+1);
                }
                else{
                    blue.push_back(i+1);
                }
            }

            int red_check = bfs(red);
            memset(visited, 0, sizeof(visited));
            int blue_check = bfs(blue);
            memset(visited, 0, sizeof(visited));

            if(red_check == 0 && blue_check == 0){
                int tempans = 0;
                for(int i=0; i<red.size(); i++){
                    tempans += people[red[i]];
                }
                for(int i=0; i<blue.size(); i++){
                    tempans -= people[blue[i]];
                }
                tempans = abs(tempans);

                if(tempans < answer)
                    answer = tempans;
            }

        }while(next_permutation(filter.begin(), filter.end()));

        perm += 1;
    }

    if(answer == 987654321){
        cout << -1;

    }
    else{
        cout << answer;
    }

    return 0;

}