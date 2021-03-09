#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int arr[18][18] = {0, };

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    else{
        return a.first > b.first;
    }
}

bool comp2(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b){
    // dist가 같다면
    if(a.first == b.first){
        // 가로 좌표가 같다면
        if(a.second.second == b.second.second){
            return a.second.first > b.second.first;
        }
        else{
            return a.second.second < b.second.second;
        }
    }
    else{
        return a.first < b.first;
    }
}

int main(){

    int N, M, D;

    cin >> N >> M >> D;
    
    vector<int> filter;

    // 궁수 세 명
    filter.push_back(1);
    filter.push_back(1);
    filter.push_back(1);

    for(int i=3; i<M; i++){
        filter.push_back(0);
    }

    vector<int> perm;

    for(int i=1; i<=M; i++){
        perm.push_back(i);
    }

    // default: 오름차순 greater<int>();
    // 내림차순: parameter에 less<int>() 추가 
    sort(filter.begin(), filter.end());

    vector<pair<int, int>> monster_pos;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            int x;
            cin >> x;
            arr[i][j] = x;
            if(x == 1){
                monster_pos.push_back(make_pair(i, j));
            }
        }
    }

    // 제일 밑에있는, 왼쪽에 있는 monster부터 보게 정렬 
    sort(monster_pos.begin(), monster_pos.end(), comp);

    int answer = 0;

    // combination
    do{
        vector<pair<int, int>> archer_pos;
        vector<pair<int, int>> mons(monster_pos.begin(), monster_pos.end());

        for(int i=0; i<M; i++){
            if(filter[i] == 1){
                archer_pos.push_back(make_pair(N+1, perm[i]));
            }
        }

        int temp = 0;

        while(1){
            // 게임에 monster가 없으면 종료
            if(mons.empty()){
                break;
            }

            // 궁수의 타겟이 될 monster의 위치를 저장 (같은 것을 쏠 수 있으니 set으로)
            set<pair<int, int>> erase_pos;

            // (dist, (r, c))를 저장
            vector<pair<int, pair<int, int>>> archer1_target;
            vector<pair<int, pair<int, int>>> archer2_target;
            vector<pair<int, pair<int, int>>> archer3_target;

            for(int i=0; i<mons.size(); i++){
                // 여기서 모든 적에 대해 거리를 전부 다 계산해서 거리가 D보다 작거나 같은 경우에 vector에 (dist, pos) 추가한다.
                int dist1 = abs(mons[i].first-archer_pos[0].first) + abs(mons[i].second-archer_pos[0].second);
                int dist2 = abs(mons[i].first-archer_pos[1].first) + abs(mons[i].second-archer_pos[1].second);
                int dist3 = abs(mons[i].first-archer_pos[2].first) + abs(mons[i].second-archer_pos[2].second);

                if(dist1 <= D){
                    archer1_target.push_back(make_pair(dist1, make_pair(mons[i].first, mons[i].second)));
                }
                
                if(dist2 <= D){  
                    archer2_target.push_back(make_pair(dist2, make_pair(mons[i].first, mons[i].second)));
                }

                if(dist3 <= D){
                    archer3_target.push_back(make_pair(dist3, make_pair(mons[i].first, mons[i].second)));
                }
            }

            // 벡터 정렬
            if(!archer1_target.empty()){
                sort(archer1_target.begin(), archer1_target.end(), comp2);
                erase_pos.insert(make_pair(archer1_target[0].second.first, archer1_target[0].second.second));
            }
            if(!archer2_target.empty()){
                sort(archer2_target.begin(), archer2_target.end(), comp2);
                erase_pos.insert(make_pair(archer2_target[0].second.first, archer2_target[0].second.second));
            }
            if(!archer3_target.empty()){
                sort(archer3_target.begin(), archer3_target.end(), comp2);
                erase_pos.insert(make_pair(archer3_target[0].second.first, archer3_target[0].second.second));
            }

            // 화살 맞고 죽은 monster를 게임에서 제외 (vector에서 원소 검색하여 삭제)
            for(auto j=erase_pos.begin(); j!=erase_pos.end(); j++){
                mons.erase(remove(mons.begin(), mons.end(), make_pair(j->first, j->second)), mons.end());
            }

            // 죽은 monster 수 만큼 answer++;
            temp += erase_pos.size();

            // monster 전진 (vector에서 원소 삭제)
            for(int i=0; i<mons.size();){
                mons[i].first += 1;
                if(mons[i].first > N){
                    mons.erase(mons.begin()+i);
                }
                else{
                    i++;
                }
            }
        }
        
        if(temp > answer){
            answer = temp;
        }

    }while(next_permutation(filter.begin(), filter.end()));

    printf("%d", answer);

    return 0;
}