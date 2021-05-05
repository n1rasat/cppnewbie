#include <iostream>

using namespace std;

int N;
int arr[1001][21] = {0, };
int answer = 0;

void dfs(int cnt, int tempsum){
    if(cnt == N){
        if(arr[tempsum][cnt] == 0){
            arr[tempsum][cnt] = 1;
            answer += 1;
        }
            return;
    }

    if(arr[tempsum][cnt] == 1)
        return;
    
    arr[tempsum][cnt] = 1;

    dfs(cnt+1, tempsum+1);
    dfs(cnt+1, tempsum+5);
    dfs(cnt+1, tempsum+10);
    dfs(cnt+1, tempsum+50);
}

int main(){

    cin >> N;

    dfs(0, 0);

    cout << answer;

    return 0;
}