#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int map[5][9] = {0, };

int r[4] = {0, 3, 0, 1};

int K;

void rotate(int x, int dir){
    // 반시계
    if(dir == 1){
        int temp = map[x][1];

        for(int i=1; i<=7; i++){
            map[x][i] = map[x][i+1];
        }
        map[x][8] = temp;
    }
    // 시계
    else if(dir == 3){
        int temp = map[x][8];
        for(int i=7; i>=1; i--){
            map[x][i+1] = map[x][i];
        }
        map[x][1] = temp;
        
    }

}
int main(){
    for(int i=1; i<=4; i++){
        for(int j=1; j<=8; j++){
            char ch;
            ch = getchar();
            map[i][j] = ch-48;
        }
        getchar();
    }

    cin >> K;

    vector<pair<int, int>> v;

    for(int i=0; i<K; i++){
        int x, y;
        cin >> x >> y;

        v.push_back({x, y+2});
    }

    for(int i=0; i<K; i++){
        int x = v[i].first;
        int d = v[i].second;

        // 경우의 수가 적으니까 모든 경우를 나열
        if(x == 1){
            if(map[1][3]!= map[2][7]){
                if(map[2][3] != map[3][7]){
                    if(map[3][3] != map[4][7]){
                        rotate(2, r[d]);
                        rotate(3, d);
                        rotate(4, r[d]);
                    }
                    else{
                        rotate(2, r[d]);
                        rotate(3, d);
                    }
                }
                else{
                    rotate(2, r[d]);
                }
            }
        }
        else if(x == 2){
            if(map[1][3] != map[2][7]){
                rotate(1, r[d]);
            }

            if(map[2][3] != map[3][7]){
                if(map[3][3] != map[4][7]){
                    rotate(3, r[d]);
                    rotate(4, d);
                }
                else{
                    rotate(3, r[d]);
                }
            }

        }
        else if(x == 3){
            if(map[3][3] != map[4][7]){
                rotate(4, r[d]);
            }
            if(map[2][3] != map[3][7]){
                if(map[1][3] != map[2][7]){
                    rotate(2, r[d]);
                    rotate(1, d);
                }
                else{
                    rotate(2, r[d]);
                }
            }
        }
        else if(x == 4){
            if(map[3][3] != map[4][7]){
                if(map[2][3] != map[3][7]){
                    if(map[1][3] != map[2][7]){
                        rotate(3, r[d]);
                        rotate(2, d);
                        rotate(1, r[d]);
                    }
                    else{
                        rotate(3, r[d]);
                        rotate(2, d);
                    }
                }
                else{
                    rotate(3, r[d]);
                }
            }
        }

        // 마지막에 본체 돌리기
        rotate(x, d);

    }

    int answer = 0;
    for(int i=1; i<=4; i++){
        if(map[i][1] == 1){
            answer += pow(2, i-1);
        }
    }

    cout << answer;



    return 0;
}