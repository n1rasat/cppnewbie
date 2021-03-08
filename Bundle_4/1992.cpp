#include <iostream>

using namespace std;

int arr[65][65] = {0, };

void quadtree(int x, int y, int r){
    int firstvalue = arr[x][y];

    int flag = 0;

    for(int i=x; i<x+r; i++){
        for(int j=y; j<y+r; j++){
            if(arr[i][j] == firstvalue){
                continue;
            }
            else{
                i = x+r;
                flag = 1;
                break;
            }
        }
    }

    if(flag == 1 && r == 2){
        printf("(");
        for(int i=x; i<x+r; i++){
            for(int j=y; j<y+r; j++){
                printf("%d", arr[i][j]);
            }
        }
        printf(")");
        return;
    }
    else if(flag == 1 && r != 2){
        // 다른게 있고 길이가 2가 아니면 4개로 쪼갠다
        printf("(");
        quadtree(x, y, r/2);
        quadtree(x, y+r/2, r/2);
        quadtree(x+r/2, y, r/2);
        quadtree(x+r/2, y+r/2, r/2);
        printf(")");
    }
    else if(flag == 0){
        printf("%d", firstvalue);
        return ;
    }
}

int main(){

    int N;

    cin >> N;

    getchar();
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char ch;
            ch = getchar();
            arr[i][j] = ch -'0';
        }
        getchar();
    }

    quadtree(0, 0, N);

    return 0;
}