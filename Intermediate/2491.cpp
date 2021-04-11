#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;

    cin >> N;

    vector<int> v;
    for(int i=0; i<N; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    int answer = 1;

    int now = v[0];
    int temp = 1;

    // 증가 테스트
    for(int i=1; i<N; i++){
        if(v[i] >= now ){
            temp += 1;
            if(temp > answer){
                answer = temp;
            }
        }
        else if(v[i] < now){
            temp = 1;
        }

        now = v[i];
    }

    now = v[0];
    temp = 1;

    // 감소 테스트
    for(int i=1; i<N; i++){
        if(v[i] <= now){
            temp += 1;
            if(temp > answer){
                answer = temp;
            }
        }
        else if(v[i] > now){
            temp = 1;
        }

        now = v[i];
    }

    cout << answer;


    return 0;
}