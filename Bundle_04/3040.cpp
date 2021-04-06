#include <iostream>

int main(){

    int num[10];

    int sum = 0;
    for(int i=0; i<9; i++){
        int x;
        std::cin >> x;
        num[i] = x;
        sum += x;
    }

    int fake1, fake2;

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(i != j){
                if(sum - num[i] - num[j] == 100){
                    fake1 = i;
                    fake2 = j;
                    i = 9;
                    break;
                }
            }
        }
    }
    
    for(int i=0; i<9; i++){
        if(i == fake1 || i == fake2){
            continue;
        }
        std::cout << num[i] << "\n";
    }


    return 0;
}