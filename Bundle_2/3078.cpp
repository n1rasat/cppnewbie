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

    long long result = 0;

    for(int i=1; i<=N; i++){
        std::string s;
        std::cin >> s;

        int slen = s.length();

        // 입력될때마다 그 이름 길이 배열에 원소가 있는지 본다
        while(!vecarr[slen].empty()){
            int comparelen = vecarr[slen].front();

            // 어짜피 등수대로 들어오니까 
            if(i - comparelen <= K){
                result += vecarr[slen].size();
                break;
            }
            else{
                // K 보다 더 많이 차이나면 쳐냄
                vecarr[slen].erase(vecarr[slen].begin());
            }

        }

        vecarr[slen].push_back(i);
    }

    std::cout << result;

    // 다 넣어놓고 비교하니까 Timeout 발생.

    return 0;
}