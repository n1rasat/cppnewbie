#include <iostream>
#include <string>

int arr[4002][4002];

int main(){
    std::string s1;
    std::string s2;

    std::cin >> s1 >> s2;

    // i번째에서 문자가 같다면
    // 이전 위치의 값에서 +1
    // 아니면 0

    int answer = 0;

    for(int i=1; i<=s1.length(); i++){
        for(int j=1; j<=s2.length(); j++){
            if(s1[i-1] == s2[j-1]){
                arr[i][j] = arr[i-1][j-1] + 1;
                if(arr[i][j] >= answer){
                    answer = arr[i][j];
                }            
            }
        }
    }

    std::cout << answer;

    return 0;
}