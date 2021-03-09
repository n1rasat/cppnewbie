#include <iostream>
#include <math.h>

using namespace std;

int main(){

    int N, r, c;

    cin >> N >> r >> c;

    int anwswer = 0;

    while(1){
        if(N == 0){
            break;
        }

        int mapsize = pow(2, N);
        int poscheck = mapsize/2;
        int startpos = pow(2, 2*(N-1));


        // 사분면 체크
        if(r < poscheck && c < poscheck){
            // 1 
            // r, c 그대로
            anwswer += startpos*0;
            N -= 1;
        }
        else if(r < poscheck && c >= poscheck){
            // 2
            // c 감소
            anwswer += startpos*1;
            c -= poscheck;
            N -= 1;
        }
        else if(r >= poscheck && c < poscheck){
            // 3
            // r 감소
            anwswer += startpos*2;
            r -= poscheck;
            N -= 1;
        }
        else if(r >= poscheck && c >= poscheck){
            // 4
            // r, c 감소
            anwswer += startpos*3;
            r -= poscheck;
            c -= poscheck;
            N -= 1;
        }
    }
    
    printf("%d", anwswer);

    return 0;
}