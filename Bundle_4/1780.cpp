#include <iostream>

int paper[2188][2188];

int count_one = 0;
int count_zero = 0;
int count_minus = 0;

void check(int r, int c, int s){
    int first_element = paper[r][c];
    int flag = 0;

    int range = r+s;

    // 모두 같은 숫자인지 체크
    for(int i=r; i<r+s; i++){
        for(int j=c; j<c+s; j++){
            if(paper[i][j] == first_element){
                continue;
            }
            else{
                // 탈출 조건
                i = range;
                flag = 1;
                break;
            }
        }
    }
    
    // 모두 같지 않을때, 변의 길이가 3이라면
    // 각 숫자를 더해준다.
    if(flag == 1 && s == 3){
        for(int i=r; i<r+s; i++){
            for(int j=c; j<c+s; j++){
                if(paper[i][j] == 1){
                    count_one += 1;
                }
                else if(paper[i][j] == 0){
                    count_zero += 1;
                }
                else if(paper[i][j] == -1){
                    count_minus += 1;
                }
            }
        }

        return;
    }
    else if(flag == 1 && s != 3){
        // 모두 같지 않고, 변의 길이가 3 이상이면
        // 9개로 나눈다
        check(r, c, s/3);
        check(r, c+s/3, s/3);
        check(r, c+(s/3)*2, s/3);
        
        check(r+s/3, c, s/3);
        check(r+s/3, c+s/3, s/3);
        check(r+s/3, c+(s/3)*2, s/3);

        check(r+(s/3)*2, c, s/3);
        check(r+(s/3)*2, c+s/3, s/3);
        check(r+(s/3)*2, c+(s/3)*2, s/3);
    }
    else if(flag == 0){
        // 모두 같으면
        if(first_element == 1){
            count_one += 1;
        }
        else if(first_element == 0){
            count_zero += 1;
        }
        else if(first_element == -1){
            count_minus += 1;
        }

        return;
    }
}

int main(){

    int N;

    std::cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int x;
            std::cin >> x;
            paper[i][j] = x;
        }
    }

    // 종이를 본다
    check(0, 0, N);

    std::cout << count_minus << "\n";
    std::cout << count_zero << "\n";
    std::cout << count_one << "\n";

    return 0;
}
