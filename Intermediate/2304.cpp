/*
7
2 4
15 4
11 8
4 6
5 3
8 10
13 6

86
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){

    int N;

    cin >> N;

    vector<pair<int, int>> v;

    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());

    int answer = 0;

    int fx = v[0].first;
    int fy = v[0].second;
    int start = 0;

    int area = 0;

    for(int i=1; i<N; i++){
        // 높이가 더 크면
        if(v[i].second >= fy){
            // 거기까지 면적 구해서 더해주기
            area = (v[i].first-fx)*fy;
            answer += area;
            fx = v[i].first;
            fy = v[i].second;
            start = i;
        }
    }

    // fx부터 면적 채워주기
    area = (v[N-1].first+1 - fx)*fy;
    answer += area;

    // 가장 큰 높이 다음부터 보기
    start += 1;
    
    int nx = 0;
    int ny = 0;
    int temp = 0;

    while(1){
        // 끝까지 봤으면 종료
        if(start > N-1)
            break;

        // 남은 것들중에 높이가 제일 높은 것을 찾는다. (물이 고이지 않게)
        for(int i=start; i<N; i++){
            if(v[i].second > ny){
                ny = v[i].second;
                nx = v[i].first;
                temp = i;
            }
        }

        // 찾은 위치까지의 면적을 제거
        area = (nx-fx)*(fy-ny);
        answer -= area;

        // 다음 위치를 보기 위한 값 초기화
        start = temp+1;
        fx = nx;
        ny = 0;
    }

    cout << answer;

    return 0;
}