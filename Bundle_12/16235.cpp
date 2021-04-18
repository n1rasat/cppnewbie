#include <iostream>
#include <deque>

using namespace std;

int N, M, K;
int map[11][11] = {0, };
int map_yb[11][11] = {0, };
deque<int> tree[11][11];

int main(){
    cin >> N >> M >> K;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map_yb[i][j];
            map[i][j] = 5;
        }
    }

    for(int i=0; i<M; i++){
        int x, y, age;
        cin >> x >> y >> age;
        tree[x][y].push_back(age);
    }

    // K년동안
    for(int tc=0; tc<K; tc++){
        // 봄
        // cout << tc << "st year\n";
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                for(int l=0; l<tree[i][j].size(); l++){
                    if(tree[i][j][l] <= map[i][j]){
                        map[i][j] -= tree[i][j][l];
                        tree[i][j][l] += 1;
                    }
                    else{
                        // 여름
                        while(l < tree[i][j].size()){
                            map[i][j] += (tree[i][j].back()/2);
                            tree[i][j].pop_back();
                        }
                    }
                }
            }
        }

        // cout << "fall\n";
        // 가을
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                for(int l=0; l<tree[i][j].size(); l++){
                    if(tree[i][j][l] % 5 == 0){
                        for(int p = i-1; p<=i+1; p++){
                            for(int q = j-1; q<=j+1; q++){
                                if(p < 1 || p > N || q < 1 || q > N)
                                    continue;

                                if(p == i && q == j)
                                    continue;
                                tree[p][q].push_front(1);
                            }
                        }
                    }
                }
                // 겨울
                map[i][j] += map_yb[i][j];
            }
        }
    }
    
    int answer = 0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            answer += tree[i][j].size();
        }
    }

    cout << answer;


    return 0;
}