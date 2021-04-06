#include <iostream>
#include <stack>

int main(){

    int N;
    int P;

    std::cin >> N >> P;

    std::stack<int> string_arr[6];
   
    int sn;
    int pp;

    int finger = 0;

    for(int i=0; i<6; i++){
        string_arr[i].push(0);
    }

    for(int i=0; i<N; i++){
        std::cin >> sn >> pp;

        while(string_arr[sn-1].top() > pp){
            string_arr[sn-1].pop();
            finger += 1;
        }
        if(string_arr[sn-1].top() != pp){
            string_arr[sn-1].push(pp);
            finger += 1;
        }
    }

    std::cout << finger;

    return 0;

}