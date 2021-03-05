#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int N;
int M;

int graph[51][51] = {0, };

std::vector<std::pair<int, int>> house;
std::vector<std::pair<int, int>> chicken;

int choose[14] = {0, };

int final_answer = 987654321;

void dfs(int start, int count){
    if(count == M){
        int answer = 0;

        for(int i=0; i<house.size(); i++){
            int min_distance = 987654321;
            // 각 집의 치킨거리의 최소값
            for(int j=0; j<chicken.size(); j++){
                if(choose[j] == 1){
                    int distance = std::abs(house[i].first - chicken[j].first) + std::abs(house[i].second - chicken[j].second);
                    if(min_distance > distance){
                        min_distance = distance;
                    }
                }
            }
            answer += min_distance;
        }

        // 치킨거리 합의 최소값
        if(final_answer > answer){
            final_answer = answer;
        }

        return;
    }

    // backtracking
    // chicken vector에서 combination M 개. i번째 치킨집 
    for(int i=start; i<chicken.size(); i++){
        choose[i] = 1;
        dfs(start+1, count+1);
        choose[i] = 0;
        // dfs(start+1, count+1);
    }
}

int main(){

    std::cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int x;
            scanf("%d", &x);
            graph[i][j] = x;   

            if(x == 1){
                house.push_back(std::make_pair(i, j));

            }
            else if(x == 2){
                chicken.push_back(std::make_pair(i, j));
            }
        }
    }

    // next_permutation을 사용한 combination 구하기.
    std::vector<int> filter;

    // nCm에서 m개만큼 1을 넣고 아닌것 만큼 0 넣기
    for(int i=0; i<M; i++){
        filter.push_back(1);
    }
    for(int i=0; i<chicken.size()-M; i++){
        filter.push_back(0);
    }
    std::sort(filter.begin(), filter.end());

    do{
        int answer = 0;
        for(int i=0; i<house.size(); i++){
            int min_distance = 987654321;

            for(int j=0; j<filter.size(); j++){
                if(filter[j] == 1){
                    int distance = std::abs(house[i].first - chicken[j].first) + std::abs(house[i].second - chicken[j].second);

                    if(min_distance > distance){
                        min_distance = distance;
                    }
                }
            }

            answer += min_distance;
        }

        if(final_answer > answer){
            final_answer = answer;
        }
    }while(std::next_permutation(filter.begin(), filter.end()));

    // dfs(0, 0);

    std::cout << final_answer;

    return 0;
}