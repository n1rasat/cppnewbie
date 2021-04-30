#include <iostream>

using namespace std;

int N, M, H;
int map[31][11] = {0, };

int answer = 987654321;

int ladder(int sy){
    int x = 1;
    int y = sy;
    while(1){
        if(x > H){
            return y;
        }
        if(map[x][y] == 1){
            y += 1;
        }
        else if(map[x][y-1] == 1){
            y -= 1;
        }
        x += 1;
    }
}

void dfs(int x, int ncnt, int cnt){
    if(answer != 987654321)
        return;

    if(ncnt == cnt){
        int flag = 0;
        for(int i=1; i<=N; i++){
            int chk = ladder(i);

            if(chk != i){
                flag  = 1;
                break;
            }
        }

        if(flag == 0)
            answer = ncnt;

        return;
    }

    for(int i=x; i<=H; i++){
        for(int j=1; j<N; j++){
            if(map[i][j-1] == 0 && map[i][j] == 0 && map[i][j+1] == 0){
                map[i][j] = 1;
                dfs(i, ncnt, cnt+1);
                map[i][j] = 0;
            }
        }
    }

    return;
}

int main(){
    cin >> N >> M >> H;

    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;

        map[x][y] = 1;
    }

    for(int i=0; i<4; i++){
        if(answer != 987654321)
            break;
        dfs(1, i, 0);
    }

    if(answer == 987654321)
        cout << -1;
    else
        cout << answer;
    return 0;
}