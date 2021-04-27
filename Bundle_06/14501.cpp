#include <iostream>

using namespace std;

int N;
int ti[16] = {0, };
int pi[16] = {0, }; 

int answer = 0;

void dfs(int day, int cost){
    
    if(day == N+1){
        if(cost > answer)
            answer = cost;
        return;    
    }

    // 그 날 선택했을때
    if(day+ti[day] <= N+1){
        dfs(day+ti[day], cost+pi[day]);
    }
    else{
        if(cost > answer)
            answer = cost;
    }
    //그 날 선택 안했을 때
    dfs(day+1, cost);
}

int main(){
    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> ti[i] >> pi[i];
    }

    // 지금 날짜, 이익;
    dfs(1, 0);

    cout << answer;

    return 0;
}