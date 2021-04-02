#include <iostream>

using namespace std;

int map[101] = {0, };

int main(){

    int N;

    cin >> N;

    for(int i=1; i<=N; i++){
        cin >> map[i];
    }

    int M;

    cin >> M;

    for(int i=0; i<M; i++){
        int s, x;

        cin >> s >> x;

        if(s == 1){
            // x의 배수만큼 스위치 변경
            for(int j=x; j<=N; j+=x){
                map[j] = 1 - map[j];
            }
        }
        else if(s == 2){
            // 좌우 대칭 확인
            int c = 0;
            map[x] = 1 - map[x];

            c += 1;
            while(x-c >= 1 && x+c <= N){
                if(map[x-c] != map[x+c])
                    break;

                map[x-c] = 1 - map[x-c];
                map[x+c] = 1 - map[x+c];
                c += 1;
            }
        }
    }

    for(int i=1; i<=N; i++){
        printf("%d ", map[i]);
        if(i%20 == 0){
            printf("\n");
        }

    }

    return 0;
}