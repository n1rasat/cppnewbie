#include <iostream>

using namespace std;

int map[101][101] = {0, };
int N, L;

int main(){
    cin >> N >> L;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }

    int answer = 0;

    // 가로 검사
    for(int i=1; i<=N; i++){
        int curnum = -1;
        int curnumcnt = 0;

        int flag = 0;
        
        for(int j=1; j<=N; j++){
            if(map[i][j] != curnum){
                // 초기화
                if(curnum == -1){
                    curnum = map[i][j];
                    curnumcnt = 1;
                }
                // 이전 높이가 지금 내 높이보다 높으면 
                else if( curnum > map[i][j]){
                    // 높이차이가 2 이상
                    if(abs(curnum - map[i][j]) > 1){
                        flag = 1;
                        break;
                    }

                    // L개만큼이 map[i][j]랑 같아야 경사로 설치 가능.
                    for(int k=j; k<j+L; k++){
                        // 범위 밖
                        if(k > N){
                            flag = 1;
                            j = N;
                            break;
                        }

                        if(map[i][k] == map[i][j]){
                            continue;
                        }
                        else{
                            flag = 1;
                            j = N;
                            break;
                        }
                    }
                    
                    // 다음 위치로 옮겨준다
                    curnum = map[i][j];
                    curnumcnt = 0;
                    j = j+L-1;
                }
                // 이전 높이가 지금 내 높이보다 작으면
                else if(curnum < map[i][j]){
                    // 높이차이가 2 이상
                    if(abs(curnum - map[i][j]) > 1){
                        flag = 1;
                        break;
                    }
                    
                    if(curnumcnt < L){
                        flag = 1;
                        break;
                    }
                    else{
                        curnum = map[i][j];
                        curnumcnt = 1;
                    }
                }
            }
            else if(map[i][j] == curnum){
                curnumcnt += 1;
            }
        }

        // 무사히 건넜으면
        if(flag == 0){
            answer += 1;
        }
    }

    // 세로 검사
    for(int i=1; i<=N; i++){
        int curnum = -1;
        int curnumcnt = 0;

        int flag = 0;
        
        for(int j=1; j<=N; j++){
            if(map[j][i] != curnum){
                // 초기화
                if(curnum == -1){
                    curnum = map[j][i];
                    curnumcnt = 1;
                }
                // 이전 높이가 지금 내 높이보다 높으면 
                else if( curnum > map[j][i]){
                    // 높이차이가 2 이상
                    if(abs(curnum - map[j][i]) > 1){
                        flag = 1;
                        break;
                    }
                    // L개만큼이 map[i][j]랑 같아야 경사로 설치 가능.
                    for(int k=j; k<j+L; k++){
                        // 범위 밖
                        if(k > N){
                            flag = 1;
                            j = N;
                            break;
                        }
                        
                        if(map[k][i] == map[j][i]){
                            continue;
                        }
                        else{
                            flag = 1;
                            j = N;
                            break;
                        }
                    }

                    // 다음 위치로 옮겨준다
                    curnum = map[j][i];
                    curnumcnt = 0;
                    j = j+L-1;
                }
                // 이전 높이가 지금 내 높이보다 작으면
                else if(curnum < map[j][i]){
                    // 높이차이가 2 이상
                    if(abs(curnum - map[j][i]) > 1){
                        flag = 1;
                        break;
                    }

                    if(curnumcnt < L){
                        flag = 1;
                        break;
                    }
                    else{
                        curnum = map[j][i];
                        curnumcnt = 1;
                    }
                }
            }
            else if(map[j][i] == curnum){
                curnumcnt += 1;
            }
        }

        // 무사히 건넜으면
        if(flag == 0){
            answer += 1;
        }
    }

    cout << answer; 

    return 0;
}