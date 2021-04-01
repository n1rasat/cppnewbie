#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int map [10001][6] = {0, };

// ABCDEF
// 012345
// A-F; B-D; C-E
// 0-5; 1-3; 2-4

int main(){

    int N;

    cin >> N;

    for(int i=0; i<N; i++){
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;

        map[i][0] = a;
        map[i][1] = b;
        map[i][2] = c;
        map[i][3] = d;
        map[i][4] = e;
        map[i][5] = f;
    }

    int answer = 0;

    for(int i=0; i<6; i++){
        int temp [10001][6] = {0, };
        memcpy(temp, map, sizeof(map));

        // 1. i가 밑면이다.
        int lower = temp[0][i];
        temp[0][i] = 0;

        // 2. i와 짝인 애가 윗면이다.
        int upper = 0;

        if(i == 0){
            upper = temp[0][5];
            temp[0][5] = 0;
        }
        else if(i == 1){
            upper = temp[0][3];
            temp[0][3] = 0;
        }
        else if(i == 2){
            upper = temp[0][4];
            temp[0][4] = 0;
        }
        else if(i == 3){
            upper = temp[0][1];
            temp[0][1] = 0;
        }
        else if(i == 4){
            upper = temp[0][2];
            temp[0][2] = 0;
        }
        else if(i == 5){
            upper = temp[0][0];
            temp[0][0] = 0;
        }

        // 3. max를 answer에 ++ 한다
        int tempanswer = 0;
        int maxval = temp[0][0];

        for(int i=0; i<6; i++){
            maxval = max(maxval, temp[0][i]);
        }
        tempanswer += maxval;

        // 4. 다음으로 옮긴다.
        for(int j=1; j<N; j++){
            for(int k=0; k<6; k++){

                // 5. 2.와 숫자가 같은 애가 밑면이다
                if(temp[j][k] == upper){
                    lower = temp[j][k];
                    temp[j][k] = 0;

                    // 6. 5.와 짝이 윗면이다.
                    if(k == 0){
                        upper = temp[j][5];
                        temp[j][5] = 0;
                    }
                    else if(k == 1){
                        upper = temp[j][3];
                        temp[j][3] = 0;
                    }
                    else if(k == 2){
                        upper = temp[j][4];
                        temp[j][4] = 0;     
                    }
                    else if(k == 3){
                        upper = temp[j][1];
                        temp[j][1] = 0;
                    }
                    else if(k == 4){
                        upper = temp[j][2];
                        temp[j][2] = 0;  
                    }
                    else if(k == 5){
                        upper = temp[j][0];
                        temp[j][0] = 0;
                    }

                    // 7. max를 answer에 ++ 한다
                    maxval = temp[j][0];

                    for(int l=0; l<6; l++){
                        maxval = max(maxval, temp[j][l]);
                    }
                    tempanswer += maxval;

                    // 8. 4.부터 7.까지 반복
                    break;
                }
            }
        }

        // 최댓값 갱신
        if(tempanswer > answer){
            answer = tempanswer;
        }

    }

    cout << answer;


    return 0;
}