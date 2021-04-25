#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> arr[51][51];
int N, M, K;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    cin >> N >> M >> K;

    for(int i=0; i<M; i++){
        int ri, ci, mi, si, di;
        cin >> ri >> ci >> mi >> si >> di;
                            // 방향, 질량, 속력
        arr[ri-1][ci-1].push_back({di, {mi, si}});
    }

    for(int tc=0; tc<K; tc++){
        vector<pair<int, pair<int, int>>> temparr[51][51];  
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                // 파이어볼이 있으면
                for(int k=0; k<arr[i][j].size(); k++){
                    int di = arr[i][j][k].first;
                    int mi = arr[i][j][k].second.first;
                    int si = arr[i][j][k].second.second;

                    int nr = i;
                    int nc = j;

                    for(int l=0; l<si; l++){
                        nr += dx[di];
                        nc += dy[di];

                        if(nr == N)
                            nr = 0;
                        else if(nr == -1)
                            nr = N-1;

                        if(nc == N)
                            nc = 0;
                        else if(nc == -1)
                            nc = N-1;
                    }

                    temparr[nr][nc].push_back({di, {mi, si}});
                }
                arr[i][j].clear();
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                arr[i][j] = temparr[i][j];
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(arr[i][j].size() >= 2){
                    int msum = 0;
                    int ssum = 0;
                    // 그리고 짝홀체크
                    int even = 0;
                    int odd = 0;
                    for(int k=0; k<arr[i][j].size(); k++){
                        msum += arr[i][j][k].second.first;
                        ssum += arr[i][j][k].second.second;
                        if(arr[i][j][k].first % 2 == 0){
                            even += 1;
                        }
                        else{
                            odd+=1;
                        }
                    }

                    msum /= 5;
                    ssum /= arr[i][j].size();

                    arr[i][j].clear();

                    if(msum == 0)
                        continue;

                    // 전부 짝이거나 전부 홀
                    if((even!=0 && odd==0) || (even == 0 && odd != 0)){
                        // 0 2 4 6
                        for(int k=0; k<8; k++){
                            if(k%2 != 0)
                                continue;
                            arr[i][j].push_back({k, {msum, ssum}});
                        }
                    }
                    else{
                        // 1 3 5 7
                        for(int k=0; k<8; k++){
                            if(k%2 == 0)
                                continue;
                            arr[i][j].push_back({k, {msum, ssum}});
                        }
                    }
                }
            }
        }
    }

    int answer = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<arr[i][j].size(); k++){
                answer += arr[i][j][k].second.first;
            }
        }
    }

    cout << answer;


    return 0;
}