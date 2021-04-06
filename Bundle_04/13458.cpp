#include <iostream>

int place[1000001];

int main(){

    int N;

    std::cin >> N;

    for(int i=0; i<N; i++){
        int Ai;
        std::cin >> Ai;

        place[i] = Ai;
    }
    
    int B, C;

    std::cin >> B >> C;

    // 사람이 좀 많이 필요할 수도 있음
    long long count = 0;

    // B가 무조건 들어가야되니까 일괄적으로 빼주고 시작
    for(int i=0; i<N; i++){
        place[i] -= B;
        count += 1;
    }

    for(int i=0; i<N; i++){
        // 사람이 남아있으면
        if(place[i] > 0){
            long long quotient = place[i] / C;
            long long remainder = place[i] % C;

            if(remainder == 0){
                count += quotient;
            }
            else{
                count = count + quotient + 1;
            }
        }
    }

    std::cout << count;

    return 0;
}