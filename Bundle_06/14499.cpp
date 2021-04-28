#include <iostream>
#include <string.h>

using namespace std;

int map[21][21] = {0, };
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

                //1, 2, 3, 4, 5, 6
                //1-6; 2-5; 3-4 pair
int dice[7] = {0, 0, 0, 0, 0, 0, 0};
int N, M;
int K;
int sx, sy;
int main(){
    cin >> N >> M >> sx >> sy >> K;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> map[i][j];
        }
    }
                    
    for(int i=0; i<K; i++){
        int d;
        cin >> d;

        int nx = sx + dx[d];
        int ny = sy + dy[d];

        if(nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        int temp[7];
        memcpy(temp, dice, sizeof(dice));

        // 동
        if(d == 1){
            dice[1] = temp[3];
            dice[3] = temp[6];
            dice[4] = temp[1];
            dice[6] = temp[4];
        }
        // 서
        else if(d == 2){
            dice[1] = temp[4];
            dice[3] = temp[1];
            dice[4] = temp[6];
            dice[6] = temp[3];
        }
        // 북
        else if(d == 3){
            dice[1] = temp[2];
            dice[2] = temp[6];
            dice[5] = temp[1];
            dice[6] = temp[5];
            
        }
        // 남
        else if(d == 4){
            dice[1] = temp[5];
            dice[2] = temp[1];
            dice[5] = temp[6];
            dice[6] = temp[2];
        }

        if(map[nx][ny] == 0){
            map[nx][ny] = dice[1];
        }
        else{
            dice[1] = map[nx][ny];
            map[nx][ny] = 0;
        }

        // 위치 갱신
        sx = nx;
        sy = ny;

        cout << dice[6] << "\n";
        
    }



    return 0;    
}