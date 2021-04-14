#include <iostream>
#include <queue>
#include <string>
#include <deque>

using namespace std;

            // 우상좌하
// 처음 우측: dx[0]
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

int map[101][101] = {0, };
int N, K;

int main(){
    cin >> N;
    cin >> K;
    for(int i=0; i<K; i++){
        int x, y;
        cin >> x >> y;
        map[x][y] = 2;
    }

    int L;
    cin >> L;

    priority_queue<pair<int, int>> pq;

    for(int i=0; i<L; i++){
        int x; 
        char ch;
        int D;
        cin >> x >> ch;
        if(ch == 'L'){
            D = 1;
        }
        else if(ch == 'D'){
            D = -1;
        }
        
        pq.push({-x, D});
    }

    pair<int, int> head;
    head.first = 1;
    head.second = 1;

    // 뱀 위치
    map[1][1] = 1;
    // 뱀 몸통 추적용
    deque<pair<int, int>> dq;
    dq.push_front({1, 1});

    int time = 0;
    int dir = 0;

    while(1){
        // 방향 전환의 시간이면
        if(time == -pq.top().first){
            // L
            if(pq.top().second == 1){
                dir += 1;
                if(dir == 4){
                    dir = 0;
                }
            }
            // D
            else if(pq.top().second == -1){
                dir -= 1;
                if(dir == -1){
                    dir = 3;
                }
            }
            pq.pop();
        }
        
        // 현재 방향으로 움직인다.
        head.first += dx[dir];
        head.second += dy[dir];

        // 맵 밖이면
        if(head.first < 1 || head.first > N || head.second < 1 || head.second > N){
            time += 1;
            break;
        }

        // 내 몸통이면
        if(map[head.first][head.second] == 1){
            time += 1;
            break;
        }

        // 사과면
        if(map[head.first][head.second] == 2){
            // 꼬리 그대로
            map[head.first][head.second] = 1;
            dq.push_front({head.first, head.second});
        }
        else{
            // 머리 그 방향으로 옮기기
            map[head.first][head.second] = 1;
            dq.push_front({head.first, head.second});
            // 꼬리 자르기
            int rmx = dq.back().first;
            int rmy = dq.back().second;
            map[rmx][rmy] = 0;
            dq.pop_back();
        }

        time += 1;
    }

    cout << time;

    return 0;
}