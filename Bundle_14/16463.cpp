#include <iostream>

using namespace std;

// 일반
int Nmonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 윤년
int Lmonth[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int N;
int answer = 0;

int main(){
    unsigned long long day = 13;
    cin >> N;

    // 2019-01-01: 화요일, 01-04: 금요일

    for(int i=2019; i<=N; i++){
        if(i % 400 == 0){
            // 윤년
            for(int j=1; j<=12; j++){
                // 금요일인지 확인.
                if(day%7 == 4)
                    answer += 1;

                day += Lmonth[j];
            }
        }
        else if(i % 400 != 0 && i % 100 == 0){
            // 일반
            for(int j=1; j<=12; j++){
                // 금요일인지 확인.
                if(day%7 == 4)
                    answer += 1;

                day += Nmonth[j];
            }    
        }
        else if(i % 100 != 0 && i % 4 == 0){
            // 윤년
            for(int j=1; j<=12; j++){
                // 금요일인지 확인.
                if(day%7 == 4)
                    answer += 1;

                day += Lmonth[j];
            }
        }
        else{
            // 일반
            for(int j=1; j<=12; j++){
                // 금요일인지 확인.
                if(day%7 == 4)
                    answer += 1;

                day += Nmonth[j];
            } 
        }
    }

    cout << answer;

    return 0;
}