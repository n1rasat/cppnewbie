#include <iostream>

using namespace std;

int map [501][501] = {0, };
int N, M;

int answer = 0;

int dx[19][3] = {
    {0, 0, 0},
    {1, 2, 3},
    {1, 1, 1},
    {0, 1, 2},
    {0, 0, 1},
    {1, 2, 2},
    {0, 0, -1},
    {1, 2, 2},
    {0, 0, 1},
    {0, 1, 2},
    {0, 1, 1},
    {0, -1, -1},
    {1, 1, 2},
    {0, 1, 1},
    {1, 1, 2},
    {0, 0, -1},
    {0, 0, 1},
    {1, 2, 1},
    {1, 2, 1},
};

int dy[19][3] = {
    {1, 2, 3},
    {0, 0, 0},
    {0, 1, 2},
    {1, 0, 0},
    {1, 2, 2},
    {0, 0, -1},
    {1, 2, 2},
    {0, 0, 1},
    {1, 2, 0},
    {1, 1, 1},
    {1, 0, 1},
    {1, 1, 2},
    {0, 1, 1},
    {1, 1, 2},
    {0, -1, -1},
    {1, 2, 1},
    {1, 2, 1},
    {0, 0, 1},
    {0, 0, -1},
};

int main(){
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> map[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            for(int k=0; k<19; k++){
                int flag = 0;
                int tempans = map[i][j];
                for(int l=0; l<3; l++){
                    int nx = i+dx[k][l];
                    int ny = j+dy[k][l];

                    if(nx < 1 || nx >N || ny < 1 || ny > M){
                        flag = 1;
                        break;
                    }
                    tempans += map[nx][ny];
                }
                if(flag == 0){
                    // cout << "Tempans: " << tempans << "\n";
                    if(tempans > answer)
                        answer = tempans;
                }
            }
        }
    }

    cout << answer;

    return 0;
}