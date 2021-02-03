#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

int main(){
    int N, K;

    std::cin >> N >> K;

    std::deque<int> dq;
    std::deque<int> check(N,0);

    // 벨트 생성
    for(int i=0; i<2*N; i++){
        int v;
        std::cin >> v;
        dq.push_back(v);
    }

    int iterate = 1;

    while(1){
        // 벨트 회전
        check[N-1] = 0;
        int last_check = check.at(N-1);
        check.pop_back();
        check.push_front(last_check);

        int last_element = dq.at(2*N - 1);
        dq.pop_back();
        dq.push_front(last_element);

        // 로봇 이동
        check[N-1] = 0;
        for(int i=N-2; i>=0; i--){
            if( (check[i] == 1) && (check[i+1] == 0) && (dq[i+1] > 0) ){
                check[i+1] = 1;
                check[i] = 0;
                dq[i+1] -= 1;
            }
        }

        // 로봇 탑승
        if((dq[0] > 0) && (check[0] == 0)){
            check[0] = 1;
            dq[0] -= 1;
        }

        // 내구도 검사
        if(std::count(dq.begin(), dq.end(), 0) >= K){
            break;
        }

        iterate += 1;
    }

    std::cout << iterate;
    
    return 0;
}