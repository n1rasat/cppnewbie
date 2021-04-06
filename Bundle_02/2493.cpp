#include <iostream>
#include <stack>

int main(){

    int N;

    std::cin >> N;

    std::stack<std::pair<int, int>> stk;

    for(int i=0; i<N; i++){
        int tower;

        // std::cin >> tower;
        scanf("%d", &tower);

        while(1){
                if(!stk.empty() && tower > stk.top().first)
                    stk.pop();
                else
                    break;
        }
        if(stk.empty()){
            stk.push(std::make_pair(tower, i+1));
            printf("0 ");
            // std::cout << 0 << " ";
        }
        else{
            // 지금 들어온게 들어가있는거보다 더 크면
            // std::cout << stk.top().second << " ";
            printf("%d ", stk.top().second);
            stk.push(std::make_pair(tower, i+1));
        }
    }

    return 0;
}