#include <iostream>

using namespace std;

int arr[501][501] = {0, };
int dp[501][501] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int M, N;

int answer = 0;

int dfs(int cx, int cy){
    if(cx == M-1 && cy == N-1){
        return 1;
    }

    // 이미 밟았던 곳
    if(dp[cx][cy] != -1)
        return dp[cx][cy];

    dp[cx][cy] = 0;

    for(int i=0; i<4; i++){
        int nx = cx+dx[i];
        int ny = cy+dy[i];

        if(nx < 0 || nx > M || ny < 0 || ny > N)
            continue;

        if(arr[cx][cy] <= arr[nx][ny])
            continue;

        if(dp[nx][ny] != -1){
            dp[cx][cy] += dp[nx][ny];
        }
        else{
            dp[cx][cy] += dfs(nx, ny);
        }
    }

    return dp[cx][cy];
}

int main(){
    
    cin >> M >> N;

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    answer = dfs(0, 0);

    cout << answer;

    return 0;
}