#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int map[21][21] = {0, };

int N;

int answer = 0;
void dfs(int cnt, int m[][21]){

    if(cnt == 10){
        int tempans = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(m[i][j] > tempans)
                    tempans = m[i][j];
            }
        }

        if(tempans > answer)
            answer = tempans;

        return;
    }

    int temp[21][21] = {0, };
    memset(temp, 0, sizeof(temp));

    // 상
    for(int i=1; i<=N; i++){
        vector<int> v;
        vector<int> av;
        for(int j=1; j<=N; j++){
            if(m[j][i]>0){
                v.push_back(m[j][i]);
            }
        }
        int vs = v.size();
        for(int j=0; j<vs; j++){
            if(j == vs-1){
                av.push_back(v[j]);
            }
            else if(v[j] == v[j+1]){
                av.push_back(v[j]*2);
                j++;
            }
            else if(v[j] != v[j+1]){
                av.push_back(v[j]);
            }
        }
        for(int j=0; j<av.size(); j++){
            temp[j+1][i] = av[j];
        }
    }
    dfs(cnt+1, temp);
    memset(temp, 0, sizeof(temp));

    // 하
    for(int i=1; i<=N; i++ ){
        vector<int> v;
        vector<int> av;
        for(int j=N; j>=1; j--){
            if(m[j][i]>0){
                v.push_back(m[j][i]);
            }
        }
        int vs = v.size();
        for(int j=0; j<vs; j++){
            if(j == vs-1){
                av.push_back(v[j]);
            }
            else if(v[j] == v[j+1]){
                av.push_back(v[j]*2);
                j++;
            }
            else if(v[j] != v[j+1]){
                av.push_back(v[j]);
            }
        }
        for(int j=0; j<av.size(); j++){
            temp[N-j][i] = av[j];
        }
    }
    dfs(cnt+1, temp);
    memset(temp, 0, sizeof(temp));

    // 좌
    for(int i=1; i<=N; i++){
        vector<int> v;
        vector<int> av;
        for(int j=1; j<=N; j++){
            if(m[i][j]>0){
                v.push_back(m[i][j]);
            }
        }
        int vs = v.size();
        for(int j=0; j<vs; j++){
            if(j == vs-1){
                av.push_back(v[j]);
            }
            else if(v[j] == v[j+1]){
                av.push_back(v[j]*2);
                j++;
            }
            else if(v[j] != v[j+1]){
                av.push_back(v[j]);
            }
        }
        for(int j=0; j<av.size(); j++){
            temp[i][j+1] = av[j];
        }
    }
    dfs(cnt+1, temp);
    memset(temp, 0, sizeof(temp));

    // // 우
    for(int i=1; i<=N; i++){
        vector<int> v;
        vector<int> av;
        for(int j=N; j>=1; j--){
            if(m[i][j]>0){
                v.push_back(m[i][j]);
            }
        }
        int vs = v.size();
        for(int j=0; j<vs; j++){
            if(j == vs-1){
                av.push_back(v[j]);
            }
            else if(v[j] == v[j+1]){
                av.push_back(v[j]*2);
                j++;
            }
            else if(v[j] != v[j+1]){
                av.push_back(v[j]);
            }
        }
        for(int j=0; j<av.size(); j++){
            temp[i][N-j] = av[j];
        }
    }
    dfs(cnt+1, temp);
    memset(temp, 0, sizeof(temp));

    return;
}


int main(){
    cin >> N;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }

    dfs(0, map);

    cout << answer;


    return 0;
}