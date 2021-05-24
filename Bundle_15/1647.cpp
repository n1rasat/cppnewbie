#include <iostream>
#include <vector>
#include <queue>

using namespace std;

        // weight, next
vector<pair<long long, int>> node[100001];
int visited[100001] = {0, };
int N, M;

long long answer = 0;
long long maxdist = 0;

void prim(int v){
    // 일반적인 BFS에서 queue를 pq로 바꾸고 pq에 weight가 추가된 것?
    priority_queue<pair<long long, int>> pq;

    for(int i=0; i<node[v].size(); i++){
        int dist = node[v][i].first;
        int next = node[v][i].second;

        pq.push({-dist, next});
    }

    visited[v] = 1;

    while(!pq.empty()){
        int dist = -pq.top().first;
        int cur = pq.top().second;

        pq.pop();

        if(visited[cur] == 1)
            continue;

        visited[cur] = 1;

        answer += dist;
        if(dist> maxdist)
            maxdist = dist;

        for(int i=0; i<node[cur].size(); i++){
            int ndist = node[cur][i].first;
            int next = node[cur][i].second;

            if(visited[next] == 1)
                continue;

            pq.push({-ndist, next});
        }
    }

    return;
}

int main(){

    cin >> N >> M;

    for(int i=0; i<M; i++){
        int x, y;
        long long z;
        cin >> x >> y >> z;
        node[x].push_back({z, y});
        node[y].push_back({z, x});
    }

    prim(1);

    cout << answer-maxdist;


    return 0;
}