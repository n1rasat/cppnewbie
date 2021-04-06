#include <iostream>

int arr[602][602];
int origin[302][302];

int main(){

    int H, W, X, Y;

    std::cin >> H >> W >> X >> Y;

    for(int i=1; i<=H+X; i++){
        for(int j=1; j<=W+Y; j++){
            int input;
            std::cin >> input;
            arr[i][j] = input;
        }
    }

    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            // 겹치는 부분
            if(i>=X && j>=Y){
                origin[i][j] = arr[i][j] - origin[i-X][j-Y];
            }
            //안 겹치는 부분
            else{
                origin[i][j] = arr[i][j];
            }
        }
    }
    
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            std::cout << origin[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}