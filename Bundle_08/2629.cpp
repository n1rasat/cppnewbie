#include <iostream>

using namespace std;

int N;
int M;

int pend_weight[31] = {0, };
int marble_weight[8] = {0, };

int map[31][15001] = {0, };

void dfs(int pos, int sum){
    // 추 N개
    if(pos > N){
        return;
    }
    // 이미 계산한 무게
    if(map[pos][sum] == 1){
        return;
    }

    // cout << "pos: " << pos << ", sum: " << sum << "\n"; 

    // 만들 수 있음.
    map[pos][sum] = 1;

    // 왼쪽
    dfs(pos+1, abs(sum - pend_weight[pos]));
    // 오른쪽
    dfs(pos+1, sum + pend_weight[pos]);
    // 이 추 안 씀
    dfs(pos+1, sum);
}

int main(){

    cin >> N;

    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        pend_weight[i] = x;
    }

    cin >> M;

    for(int i=0; i<M; i++){
        int x;
        cin >> x;
        marble_weight[i] = x;
    }

    dfs(0, 0);

    for(int i=0; i<M; i++){
        if(marble_weight[i] > 15000){
            cout << "N ";
        }
        else if(map[N][marble_weight[i]] == 1){
            cout << "Y ";
        }
        else{
            cout << "N ";
        }
    }

    return 0;
}