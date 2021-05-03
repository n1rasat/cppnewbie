#include <iostream>

using namespace std;

int map[12] = {0, };
int agg[4] = {0, };

int N;

int maxans = -1000000000;
int minans = 1000000000;

void dfs(int pos, int ta){
    if(pos == N){
        if(ta > maxans)
            maxans = ta;
        
        if(ta < minans)
            minans = ta;

        return;
    }
    
    int tempans = ta;

    int nextnum = map[pos];

    // +
    if(agg[0] > 0){
        agg[0] -= 1;
        tempans += nextnum;
        dfs(pos+1, tempans);
        tempans = ta;
        agg[0]+=1;
    }
    // -
    if(agg[1]>0){
        agg[1] -= 1;
        tempans -= nextnum;
        dfs(pos+1, tempans);
        tempans = ta;
        agg[1] += 1;
    }

    // *
    if(agg[2] > 0){
        agg[2] -= 1;
        tempans *= nextnum;
        dfs(pos+1, tempans);
        tempans = ta;
        agg[2] += 1;
    }
    // /
    if(agg[3] > 0){
        agg[3] -= 1;
        tempans /= nextnum;
        dfs(pos+1, tempans);
        tempans = ta;
        agg[3] += 1;
    }

    return;
}

int main(){
    cin >> N;

    for(int i=0; i<N; i++){
        cin >> map[i];
    }

    for(int i=0; i<4; i++){
        cin >> agg[i];
    }

    dfs(1, map[0]);

    cout << maxans << "\n" << minans;

    return 0;
}