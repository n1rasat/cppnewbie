#include <iostream>

using namespace std;

long long arr[30] = {0, };

void moogame(long long input){
    // moo 수열 찾기
    int i=0;

    for(i=0; i<30; i++){
        if(input < arr[i]){
            break;
        }
    }

    int temp = 0;

    // 중간에 o가 늘어난 부분까지 뺀게 0보다 클 때 하위 단계를 보면 된다.
    if(input - arr[i-1] - (i+3) > 0){
        temp = input-arr[i-1]-(i+3);
        moogame(temp);
    }
    else if(input - arr[i-1] - (i+3) < 0){
        temp = input-arr[i-1];
        if(temp == 1){
            cout << "m";
            return;
        }
        else{
            cout << "o";
            return;
        }
    }
    else{
        cout << "o";
        return;
    }

}

int main(){

    arr[0] = 3;

    for(int i=1; i<30; i++){
        arr[i] = arr[i-1]*2 + (i+3);
    }

    long long N;
    cin >> N;

    moogame(N);

    return 0;
}