#include <iostream>
#include <vector>
#include <algorithm>

int map[14][14] = {0, };
int N;
int K;

//D; 1: right, 2: left, 3: up, 4: down
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int nd[5] = {0, 2, 1, 4, 3};

using namespace std;

int main(){
    cin >> N >> K;

    // 0: white, 1:red, 2:blue
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> map[i][j];
        }
    }

    // 말 위치, 방향 저장
    vector<pair<pair<int, int>, int>> v;

    // 말 번호 저장
    vector<int> vmap[14][14];

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            vmap[i][j].reserve(10);
        }
    }

    //R, C, D
    //D; 1: right, 2: left, 3: up, 4: down
    for(int i=0; i<K; i++){
        int x, y, d;
        cin >> x >> y >> d;
        v.push_back({{x, y}, d});
        vmap[x][y].push_back(i);
    }

    int count = 1;

    while(1){
        if(count > 1000){
            cout << -1;
            return 0;
        }

        // 말 순서대로 보면서 움직이기.
        for(int i=0; i<K; i++){
            // 말 위치 확인하기
            int x = v[i].first.first;
            int y = v[i].first.second;
            int d = v[i].second;

            int nx = x+dx[d];
            int ny = y+dy[d];

            // 다음칸이 파란색 or 범위 밖
            if(nx < 1 || nx > N || ny < 1 || ny > N || map[nx][ny] == 2){
                // 방향을 바꿔줘야한다. d 갱신, nx, ny 갱신
                v[i].second = nd[d];
                d = v[i].second;
                nx = x+dx[d];
                ny = y+dy[d];

                // 바꾼 후에도 파란색이면 가만히
                if(nx < 1 || nx > N || ny < 1 || ny > N || map[nx][ny] == 2)
                    continue;
            }

            // vmap[x][y]에서 i번째 말의 위치를 찾는다.
            vector<int>& cur = vmap[x][y];
            vector<int>& next = vmap[nx][ny];
             
            auto it = find(cur.begin(), cur.end(), i);
            int idx = it-cur.begin();

            // 다음 칸이 붉은색
            if(map[nx][ny] == 1){
                // reverse(vmap[x][y].begin()+idx, vmap[x][y].end());
                reverse(it, cur.end());
            }

            // 옮기기
            // for(int j = idx; j<cur.size(); j++){
            //     v[vmap[x][y][j]].first.first = nx;
            //     v[vmap[x][y][j]].first.second = ny;
            //     vmap[nx][ny].push_back(vmap[x][y][j]);
            // }
            for(auto j = it; j != cur.end(); j++){
                v[*j].first.first = nx;
                v[*j].first.second = ny;
                next.push_back(*j);
            }

            // vmap[x][y].erase(vmap[x][y].begin()+idx, vmap[x][y].end());
            cur.erase(it, cur.end());

            if(vmap[nx][ny].size() >= 4){
                cout << count;
                return 0;
            }
        }
        
        count += 1;
    }


    return 0;
}

