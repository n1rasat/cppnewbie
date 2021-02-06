#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main(){

    int N;
    int K;

    scanf("%d %d", &N, &K);

    std::vector<std::vector<int>> vecarr;

    for(int i=0; i<21; i++){
        std::vector<int> tempvec;

        tempvec.reserve(300000);
        vecarr.push_back(tempvec);
    }
    
    std::string s;

    for(int i=1; i<=N; i++){
        std::string s;
        std::cin >> s;

        vecarr[s.length()].push_back(i);
    }

    std::vector<std::pair<int, int>> result_pair;

    for(int i=2; i<=20; i++){
        if(!vecarr[i].empty()){
            for(int j=0; j<vecarr[i].size(); j++){
                // 거기에 학생이 있으면
                // 0 ~ K차이까지 보고
                // 1 ~ K차이까지 보고
                // 근데 이게 중복이 되면 안됨. 그러니까 (int1, int2) pair를 만들어서 
                // 이 (pair)가 순서 상관없는 set이어야함.
                // 그냥 (int1, int2), (int2, int1) 둘 다 넣고 마지막에 /2 하면 될 듯?

                // std::cout << i << "! " << std::endl;
                for(int k=j+1; k<vecarr[i].size(); k++){
                    if(vecarr[i][k] - vecarr[i][j] > K){
                        break;
                    }
                    // std::cout << "[i][j]: " << vecarr[i][j] << " [i][k]: " << vecarr[i][k] << std::endl;
                    else if(vecarr[i][k] - vecarr[i][j] <= K){ 
                        // 찾아보고 없으면 넣기
                        if(std::find(result_pair.begin(), result_pair.end(), std::make_pair(vecarr[i][j], vecarr[i][k])) == result_pair.end()){
                            result_pair.push_back(std::make_pair(vecarr[i][j], vecarr[i][k]));
                            result_pair.push_back(std::make_pair(vecarr[i][k], vecarr[i][j]));
                        }
                    }
                }
            }
        }
    }

    std::cout << result_pair.size() / 2;

    return 0;
}