#include <iostream>
#include <cstdio>
#include <memory.h>

#define MAXSIZE 51

int map[MAXSIZE][MAXSIZE];
int N;
int M;
int K;

void dfs(int x, int y){
    if( x<0 || x>=N || y<0 || y>=M || map[x][y] == 0)
        return;

    map[x][y] = 0;
    dfs(x+1, y);
    dfs(x-1, y);
    dfs(x, y-1);
    dfs(x, y+1);
}

int main(){

    int T;

    std::cin >> T;    

    for(int i=0; i<T; i++){

        memset(map, 0, sizeof(map));
        
        std::cin >> N >> M >> K;

        for(int j=0; j<K; j++){
            int x;
            int y;

            std::cin >> x >> y;

            map[x][y] = 1;
        }

        int count = 0;

        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(map[j][k] == 1){
                    dfs(j, k);
                    count += 1;
                }
            }
        }

        std::cout << count << std::endl;
    }


    return 0;
}