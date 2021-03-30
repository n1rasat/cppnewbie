#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2){
    return s1 + s2 > s2 + s1;
}

int main(){

    int N, M;

    cin >> N >> M;

    vector<string> vs;
    vector<int>vi;

    // string이랑 int 둘 다 저장
    for(int i=0; i<N; i++){
        string s;
        cin >> s;
        int x = stoi(s);
        vs.push_back(s);
        vi.push_back(x);
    }

    int MN = M-N;

    // cout << "vs.rbegin: ";
    // sort(vs.rbegin(), vs.rend());
    // for(int i=0; i<vs.size(); i++){
    //     cout << vs[i] << " ";
    // }
    // cout << "\n";

    // cout << "vs.begin: ";
    // sort(vs.begin(), vs.end(), comp);
    // for(int i=0; i<vs.size(); i++){
    //     cout << vs[i] << " ";
    // }
    // cout << "\n";

    // cout << "vs.begin.comp: ";
    // sort(vs.begin(), vs.end(), comp);
    // for(int i=0; i<vs.size(); i++){
    //     cout << vs[i] << " ";
    // }
    // cout << "\n";

    // cout << "vi.begin: ";
    // sort(vi.rbegin(), vi.rend());
    // for(int i=0; i<vi.size(); i++){
    //     cout << vi[i] << " ";
    // }
    // cout << "\n";


    // int중에 제일 큰 것을 반복해야함
    sort(vi.rbegin(), vi.rend());
    // for(int i=0; i<MN; i++){
    //     cout << vi[0];
    // }

    string temp = to_string(vi[0]);

    // cout << temp << "\n";

    vector<string> vs2;

    for(int i=0; i<MN; i++){
        vs2.push_back(temp);
    }

    // sort(vs.begin(), vs.end(), comp);
    // 그리고 하나씩 다 써야되니까 넣고
    for(int i=0; i<vs.size(); i++){
        // cout << vs[i];
        vs2.push_back(vs[i]);
    }

    // 제일 큰 수가 나오게 정렬
    sort(vs2.begin(), vs2.end(), comp);
    for(int i=0; i<vs2.size(); i++){
        cout << vs2[i];
    }

    return 0;
}