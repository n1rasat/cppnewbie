#include <iostream>
#include <queue>

int factorial(int n){
    return (n == 0) || (n == 1) ? 1 : n * factorial(n-1);
}

int main(){

    int N, M, K;

    std::cin >> N >> M >> K;

    int astack = N;
    int zstack = M;

    int startpos = 1;
    int endpos = factorial(astack+zstack) / (factorial(astack) * factorial(zstack));

    if(K > endpos){
        std::cout << -1;
        return 0;
    }

    std::queue<char> q;

    // startpos or endpos == K 가 될때까지
    while(1){
        if(astack == 0){
            break;
        }
        if(zstack == 0){
            break;
        }
        long long aselect = factorial(astack-1+zstack) / (factorial(astack-1) * factorial(zstack));
        long long zselect = factorial(astack+zstack-1) / (factorial(astack) * factorial(zstack-1));

        // a 선택하고 남은 경우의 수의 시작지점이 K보다 크다면 a 선택하는게 맞지
        if(startpos + aselect - 1 >= K){
            astack -= 1;
            q.push('a');
            // 그리고 endpos를 변경
            endpos = aselect;
        }
        // 그게 아니면 z를 선택해야함. 시작지점이 K보다 작거나 같기때문에
        else{
            zstack -= 1;
            q.push('z');
            // 그리고 startpos를 변경
            startpos = startpos + aselect;
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