#include <iostream>
#include <string>

using namespace std;

int N, K;
int check[26] = {0, };
string parts[51];
int answer = 0;

void dfs(int cur, int cnt){
    if(cnt == K){
        int tempans = 0;
        for(int i=0; i<N; i++){
            int len = parts[i].length();
            int flag = 0;
            for(int j=0; j<len; j++){
                if(check[parts[i][j]-'a'] == 1)
                    continue;
                
                flag = 1;
                break;
            }
            if(flag == 0){
                tempans += 1;
            }
        }

        if(tempans > answer){
            answer = tempans;
        }

        return;
    }

    if(cur >= 26)
        return;

    if(check[cur] == 0){
        check[cur] = 1;
        dfs(cur+1, cnt+1);
        check[cur] = 0;
    }
    dfs(cur+1, cnt);
    return;
}

int main(){
    cin >> N >> K;

    // anta, tica
    // a n t i c.
    check['a'-'a'] = 1;
    check['n'-'a'] = 1;
    check['t'-'a'] = 1;
    check['i'-'a'] = 1;
    check['c'-'a'] = 1;

    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        string part = s.substr(4, s.length()-8);
        parts[i] = part;
    }

    if(K < 5){
        cout << 0;
        return 0;
    }

    K -= 5;

    dfs(0, 0);
    
    cout << answer;

    return 0;
}