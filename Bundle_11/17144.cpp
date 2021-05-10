#include <iostream>
#include <string.h>

using namespace std;

int map[51][51] = {0, };
int tempmap[51][51] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int R, C, T;

int up_air;
int down_air;

int main(){
    cin >> R >> C >> T;
    int flag = 0;

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            cin >> map[i][j];

            if(flag == 0 && map[i][j] == -1){
                up_air = i;
                flag = 1;
                down_air = i+1;
            }
        }
    }

    for(int tc = 0; tc < T; tc++){
        // 미세먼지 확산
        // 좌표를 받아서 상하좌우를 체크하고 확산시킨다.
        // 위치를 계속해서 추적해야되는데.

        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                // 미세먼지가 있으면 확산을 시킨다.
                if(map[i][j] > 0){
                    int diffusion_cnt = 0;
                    for(int k=0; k<4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if(nx < 1 || nx > R || ny < 1 || ny > C)
                            continue;
                        
                        if(map[nx][ny] == -1)
                            continue;

                        // 확산될 수 있는 지역이면.
                        tempmap[nx][ny] += map[i][j]/5;
                        diffusion_cnt += 1;
                    }
                    map[i][j] -= (map[i][j]/5)*diffusion_cnt;
                }
            }
        }

        // map과 tempmap을 합친다.
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                map[i][j] += tempmap[i][j];
            }
        }

        // 공기청정기를 돌린다.
        // 상단좌표: (up_air, 1)
        // 좌
        for(int i=up_air-1; i>1; i--){
            map[i][1] = map[i-1][1];
        }
        // 상
        for(int i=1; i<C; i++){
            map[1][i] = map[1][i+1];
        }
        // 우
        for(int i=1; i<up_air; i++){
            map[i][C] = map[i+1][C];
        }
        // 하
        for(int i=C; i>1; i--){
            map[up_air][i] = map[up_air][i-1];
        }
        // 혹시 모르니까 공기청정기 다시 두기
        map[up_air][1] = -1;
        map[up_air][2] = 0;
        // 하단좌표: (down_air, 1)
        // 좌
        for(int i = down_air+1; i <R; i++){
            map[i][1] = map[i+1][1];
        }
        // 하
        for(int i=2; i<=C; i++){
            map[R][i-1] = map[R][i];
        }
        // 우
        for(int i=R; i>down_air-1; i--){
            map[i][C] = map[i-1][C];
        }
        // 상
        for(int i=C; i >2; i--){
            map[down_air][i] = map[down_air][i-1];
        }
        
        // 혹시 모르니까 공기청정기 다시 두기
        map[down_air][1] = -1;
        map[down_air][2] = 0;

        memset(tempmap, 0, sizeof(tempmap));
    }

    int answer = 0;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            answer += map[i][j];
        }
    }
    // 공기청정기만큼 추가
    answer += 2;

    cout << answer;


    return 0;
}