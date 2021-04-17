#include <iostream>

using namespace std;

int map[100001] = {0, };

int main(){

    int N, K;
    cin >> N >> K;

    int answer = 0;
    int temp = 0;

    for(int i=0; i<N; i++){
        cin >> map[i];
    }

    for(int i=0; i<K; i++){
        temp += map[i];
    }
    answer = temp;

    for(int i=K; i<N; i++){   
        temp += map[i];
        temp -= map[i-K];
        if(temp > answer){
            answer = temp;
        }
    }

    cout << answer;

    return 0;

}