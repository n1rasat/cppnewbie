#include <iostream>
#include <algorithm>

struct rcs{
    int r;
    int c;
    int s;
};

int main(){
    int N, M, K;

    scanf("%d %d %d", &N, &M, &K);

    int arr[50][50];
    int temparr[50][50];
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int x;
            scanf("%d", &x);
            arr[i][j] = x;
        }
    }

    int permu[6];
    
    // 길이 K짜리 permutation arr 생성
    for(int i=0; i<K; i++){
        permu[i] = i;
    }

    rcs rcsarr[6];

    for(int i=0; i<K; i++){
        int r, c, s;

        scanf("%d %d %d", &r , &c, &s);
        rcsarr[i].r = r-1;
        rcsarr[i].c = c-1;
        rcsarr[i].s = s;
    }

    int answer = 50000000;

    do{
        // temp에 arr 때려박기
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                temparr[i][j] = arr[i][j];
            }
        }

        // temparr을 돌려
        for(int i=0; i<K; i++){
            int r, c, s;
            r = rcsarr[permu[i]].r;
            c = rcsarr[permu[i]].c;
            s = rcsarr[permu[i]].s;

            while(s>0){
                int temp = temparr[r-s][c-s];

                // 움직이는 범위: 2*s >> +=s
                // 좌
                for(int i=r-s; i<r+s; i++){
                    temparr[i][c-s] = temparr[i+1][c-s];
                }

                // 하
                for(int i=c-s; i<c+s; i++){
                    temparr[r+s][i] = temparr[r+s][i+1];
                }

                // 우
                for(int i=r+s; i>r-s; i--){
                    temparr[i][c+s] = temparr[i-1][c+s];
                }

                // 상
                for(int i=c+s; i>c-s+1; i--){
                    temparr[r-s][i] = temparr[r-s][i-1];
                }

                temparr[r-s][c-s+1] = temp;
                s -= 1;
            }
        }

        int sum = 0;
        // 다 돌고나서 최소값 계산
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                sum += temparr[i][j];
            }
            // 여기서 최소값이 그 permutation의 최소값.
            if(answer > sum)
                answer = sum;
            sum = 0;
        }

    }while(std::next_permutation(permu, permu+K));

    printf("%d", answer);

    return 0;
}