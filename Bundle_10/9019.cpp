#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

int visited[10001] = {0, };
int answer;

void bfs(int x){
    queue<pair<int, string>> q;

    q.push({x, ""});
    visited[x] = 1;

    while(!q.empty()){
        int temp = q.front().first;
        string ts = q.front().second;
        q.pop();

        if(temp == answer){
            cout << ts << "\n";
            return;
        }

        int calc_temp;

        // D
        calc_temp = (temp*2) % 10000;
        if(visited[calc_temp] == 0){
            visited[calc_temp] = 1;
            q.push({calc_temp, ts+"D"});
        }
        
        //S
        calc_temp = temp-1;
        if(calc_temp < 0){
            calc_temp = 9999;
        }
        if(visited[calc_temp] == 0){
            visited[calc_temp] = 1;
            q.push({calc_temp, ts+"S"});
        }

        //L
        calc_temp = (temp%1000)*10 + (temp/1000);
        if(visited[calc_temp] == 0){
            visited[calc_temp] = 1;
            q.push({calc_temp, ts+"L"});
        }

        //R
        calc_temp = (temp/10) +(temp%10)*1000;
        if(visited[calc_temp] == 0){
            visited[calc_temp] = 1;
            q.push({calc_temp, ts+"R"});
        }
    }

    return ;
}

int main(){
    int N;

    cin >> N;

    for(int i=0; i<N; i++){
        int x;
        cin >> x >> answer;
        bfs(x);
        memset(visited, 0, sizeof(visited));
    }

    return 0;
}