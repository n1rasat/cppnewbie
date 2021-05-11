#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[9][9] = {0, };

vector<pair<int, int>> v;

void dfs(int pos){
    if(pos == v.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << arr[i][j];
            }
        cout << "\n";
        }
        exit(0);
    }

    int cx = v[pos].first;
    int cy = v[pos].second;

    int sqx = (cx/3)*3;
    int sqy = (cy/3)*3;

    // 1부터 9까지 집어넣는다.
    for(int i=1; i<=9; i++){
        // row
        int flag = 0;
        for(int j=0; j<9; j++){
            // 같은게 있었으면
            if(arr[cx][j] == i){
                flag = 1;
                break;
            }
        }

        // col
        for(int j=0; j<9; j++){
            if(arr[j][cy] == i){
                flag = 1;
                break;
            }
        }

        // square
        for(int j=sqx; j<sqx+3; j++){
            for(int k=sqy; k<sqy+3; k++){
                if(arr[j][k] == i){
                    flag = 1;
                    break;
                }
            }
        }
        
        // 모든 기준 만족
        if(flag == 0){
            arr[cx][cy] = i;
            dfs(pos+1);
            arr[cx][cy] = 0;
        }
    }

    return;
}

int main(){

    for(int i=0; i<9; i++){
        string s;
        cin >> s;
        for(int j=0; j<9; j++){
            arr[i][j] = s[j]-48;
            if(arr[i][j] == 0){
                v.push_back({i, j});   
            }
        }
    }

    dfs(0);

    return 0;
}