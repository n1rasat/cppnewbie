#include <iostream>
#include <queue>

using namespace std;

int R, C, M;

            // 상, 하, 우, 좌
int dx[5] = {0, -1, 1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};

int cdir[5] = {0, 2, 1, 4, 3};

priority_queue<pair<int, pair<int, int>>> map[105][105];
priority_queue<pair<int, pair<int, int>>> moved_map[105][105];

int main(){

    cin >> R >> C >> M;

    // 상어가 왕복했을 때 걸리는 거리
    int x_axis_repeat = C+(C-2);
    int y_axis_repeat = R+(R-2);

    for(int i=0; i<M; i++){
        int ro, co, sp, di, z;
        cin >> ro >> co >> sp >> di >> z;
        map[ro][co].push({z, {sp, di}});
    }

    int fishking = 0;
    int answer = 0;

    while(1){
        fishking += 1;
        if(fishking > C){
            cout << answer;
            return 0;
        }

        for(int i=1; i<=R; i++){
            // 그 격자판에 상어가 있으면
            if(!map[i][fishking].empty()){
                int shark_size = map[i][fishking].top().first;
                answer += shark_size;
                map[i][fishking].pop();
                i = R;
                break;
            }
        }

        // 이제 각 상어들이 움직인다.
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(!map[i][j].empty()){
                    int speed = map[i][j].top().second.first;
                    int dir = map[i][j].top().second.second;
                    int size = map[i][j].top().first;

                    int sx = i;
                    int sy = j;

                    int spd = speed;

                    // 제자리로 돌아오는 횟수를 체크해서 나눠준다. 시간초과의 원인.
                    if(dir == 1 || dir == 2){
                        spd %= y_axis_repeat;
                    }
                    else if(dir == 3 || dir == 4){
                        spd %= x_axis_repeat;
                    }

                    while(spd--){
                        // 벽에 박았으면 방향전환
                        if(dir == 1 && sx == 1){
                            dir = cdir[dir];
                        }
                        else if(dir == 2 && sx == R){
                            dir = cdir[dir];
                        }
                        else if(dir == 3 && sy == C){
                            dir = cdir[dir];
                        }
                        else if(dir == 4 && sy == 1){
                            dir = cdir[dir];
                        }

                        sx += dx[dir];
                        sy += dy[dir];

                    }
                    moved_map[sx][sy].push({size,{speed, dir}});
                    // 어짜피 상어가 1마리만 있었을 거니까 pop 한 번으로 비워진다.
                    map[i][j].pop();
                }
            }
        }

        // 상어를 원래 위치로 옮겨준다.
        // 움직임과 동시에 맨 앞에 한마리 남겨놓고 전부 제거하면 된다. 
        // 실컷 이동하고 나서 moved_map의 front만 빼다가 map에 박으면 된다는 뜻.
        for(int i=1; i<=R; i++){
            for(int j=1; j<=C; j++){
                if(!moved_map[i][j].empty()){
                    int speed = moved_map[i][j].top().second.first;
                    int dir = moved_map[i][j].top().second.second;
                    int size = moved_map[i][j].top().first;

                    // 사이즈 제일 큰 한마리만.
                    map[i][j].push({size, {speed, dir}});
                    while(!moved_map[i][j].empty()){
                        moved_map[i][j].pop();
                    }
                }
            }
        }
    }

    return 0;
}