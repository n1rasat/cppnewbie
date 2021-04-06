#include <iostream>

int main(){

    int N;

    std::cin >> N;

    int arr[10001] = {0, };

    int count = 0;

    for(int i=0; i<N; i++){
        int x, y;

        std::cin >> x >> y;

        int xmax = x+10;
        int ymax = y+10;

        for(int j=x; j<xmax; j++){
            for(int k=y; k<ymax; k++){
                if(100*k+j > 10000){
                    continue;
                }

                if(arr[100*k+j] == 1){
                    continue;
                }
                arr[100*k+j] = 1;

                count += 1;
            }
        }
    }

    std::cout << count;

    return 0;
}