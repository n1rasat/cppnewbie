#include <iostream>
#include <vector>

int main(){
    int N;
    std::cin >> N;

    std::vector<int> inputs(N);
    std::vector<int> check(N);

    for(int i=0; i<N; i++){
        std::cin >> inputs[i];
    }

    int position = 0;
    int move = 0;
    int balloons = N-1;

    while(1){
        std::cout << position + 1 << " ";

        if(N == 1)
            break;

        check[position] = 1;
        move = inputs[position];

        // std::cout <<"move: " << move << std::endl;

        if (move > 0){
            while(move != 0){
                if(check[position] == 0){
                    move -= 1;
                    if (move == 0)
                        break;
                }
                if(position+1 > balloons)
                    position = 0;
                else
                    position += 1;
            }
        }
        else if(move < 0){
            while(move != 0){
                if(check[position] == 0){
                    move += 1;
                    if(move == 0)
                        break;
                }
                if(position-1 < 0)
                    position = balloons;
                else
                    position -= 1;
            }
        }

        N -= 1;
    }
    return 0;
}