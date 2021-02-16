/*
    error 
    1
    5 5 5
    2 1
    3 1
    1 2
    1 3
    1 1
    answer: 2
    correct answer: 1
*/

#include <iostream>
#include <vector>
#include <utility>

int main(){

    // (int, int) pair를 저장함
    // 다음 입력이 저장된 pair와 (+-1, same) or (same, +-1)차이가 난다면 인접한 것.
    // 그러면 그 입력을 인접한 곳에 저장함.
    // 인접하지 않으면 다음 칸에 그 pair를 저장
    
    // 다음 (int, int)가 들어오면 저장된 모든것과 (+-1, 0) or (0, +-1)차이가 나는지 비교.

    // 일단 집어넣어놓고
    // 그 다음에 원소 하나씩 꺼내면서
    // worm을 기록해야될듯.
    
    int T;

    std::cin >> T;

    for(int count=0; count<T; count++){
        int M;
        int N;
        int K;

        std::cin >> M >> N >> K;

        int worm = 0;

        std::vector<std::pair<int, int>> v;
        std::vector<std::pair<int, int>> temp;


        for(int i=0; i<K; i++){
            int x;
            int y;

            std::cin >> x >> y;

            v.push_back(std::make_pair(x, y));
        }

        for(int i=0; i<v.size(); i++){

            int flag = 0;

            // temp부터 봐서 temp랑 붙어있으면 걔를 temp에 집어넣는다. 
            for(int j=0; j<temp.size(); j++){
                if( ((v[i].first == temp[j].first)&&(v[i].second == temp[j].second-1)) || ((v[i].first == temp[j].first)&&(v[i].second == temp[j].second+1)) || ((v[i].first == temp[j].first-1)&&(v[i].second == temp[j].second)) || ((v[i].first == temp[j].first+1)&&(v[i].second == temp[j].second))){                    
                    temp.push_back(v[i]);
                    v.erase(v.begin()+i);
                    flag = 1;
                    break;
                }
            }

            if(flag == 1){
                i -= 1;
                flag = 0;
                continue;
            }

            for(int j=0; j<v.size(); j++){
                // 인접해있으면 걔들 둘을 묶어서 봤던 벡터 temp에 집어넣는다. 
                if( ((v[i].first == v[j].first)&&(v[i].second == v[j].second-1)) || ((v[i].first == v[j].first)&&(v[i].second == v[j].second+1)) || ((v[i].first == v[j].first-1)&&(v[i].second == v[j].second)) || ((v[i].first == v[j].first+1)&&(v[i].second == v[j].second))){
                    temp.push_back(v[i]);
                    temp.push_back(v[j]);
                    v.erase(v.begin()+i);
                    v.erase(v.begin()+j-1);
                    flag = 1;
                    worm += 1;
                    break;
                }
            }

            if(flag == 1){
                i -= 1;
                flag = 0;
                continue;
            }

            temp.push_back(v[i]);
            v.erase(v.begin()+i);
            i -= 1;
            worm += 1;

            flag = 0;
        }
        
        std::cout << worm << std::endl;
    }
    
    return 0;
}