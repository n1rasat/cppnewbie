#include <iostream>

using namespace std;

int arr [2188][2188] = {0, };

void star(int r, int c, int p){
    int bp = p/3;

    for(int i=r+bp; i<r+bp+bp; i++){
        for(int j=c+bp; j<c+bp+bp; j++){
            arr[i][j] = 1;
        }
    }

    if(p == 3){
        return;
    }

    star(r, c, bp);
    star(r+bp, c, bp);
    star(r+bp+bp, c, bp);
    
    star(r, c+bp, bp);
    star(r+bp+bp, c+bp, bp);
    
    star(r, c+bp+bp, bp);
    star(r+bp, c+bp+bp, bp);
    star(r+bp+bp, c+bp+bp, bp);
}

int main(){

    int N;

    cin >> N;

    star(0, 0, N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 0){
                printf("*");
            }
            else if(arr[i][j] == 1){
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}