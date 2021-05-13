#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int L, C;

vector<string> v;

void dfs(int mcnt, int jcnt, int pos, string ts){
    if(pos == v.size()){
        if((mcnt + jcnt) == L ){
            if(mcnt < 1)
                return;

            if(jcnt < 2)
                return;

            cout << ts << "\n";
            return;
        }
        return;
    }
    string temp = v[pos];

    if(temp == "a" || temp == "e" || temp == "i" || temp == "o" || temp == "u"){
        dfs(mcnt+1, jcnt, pos+1, ts+temp);
    }
    else{
        dfs(mcnt, jcnt+1, pos+1, ts+temp);
    }
    dfs(mcnt, jcnt, pos+1, ts);
    
    return;
}

int main(){

    cin >> L >> C;

    for(int i=0; i<C; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    sort(v.begin(), v.end());

    dfs(0, 0, 0, "");

    return 0;
}