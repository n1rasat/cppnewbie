#include <iostream>
#include <queue>

#define MAX 1000000000

int main(){

    long long N, M, K;

    std::cin >> N >> M >> K;

    // a, z가지고 만들 수 있는 문자열 개수를 배열에 저장
    long long select[101][101];

    for(long long i=0; i<=N; i++){
        for(long long j=0; j<=M; j++){
            if(i == 0){
                select[i][j] = 1;
            }
            else if(j == 0){
                select[i][j] = 1;
            }
            else{
                if(select[i][j-1]*(i+j) / j > MAX){
                    select[i][j] = MAX;
                }
                else{
                    select[i][j] = select[i][j-1]*(i+j) / j;
                }
            }
        }
    }

    if(K > select[N][M]){
        std::cout << -1;
        return 0;
    }

    std::queue<char> q;

    long long astack = N;
    long long zstack = M;

    while(1){
        if(astack == 0){
            break;
        }
        if(zstack == 0){
            break;
        }

        // a 선택하고 남은 경우의 수가 K보다 크다면 a 선택하는게 맞지
        if(select[astack-1][zstack] >= K){
            q.push('a');
            astack -= 1;
        }
        // 그게 아니면 z를 선택해야함. 경우의 수가 K보다 작거나 같기때문에
        else{
            q.push('z');
            K -= select[astack-1][zstack];
            zstack -= 1;
        }
    }

    while(astack > 0){
        q.push('a');
        astack -= 1;
    }

    while(zstack > 0){
        q.push('z');
        zstack -= 1;
    }

    while(!q.empty()){
        std::cout << q.front();
        q.pop();
    }

    return 0;
}