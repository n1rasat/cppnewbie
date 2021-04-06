#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<string, int> s1, pair<string, int> s2){
    return s1.first < s2.first;
}

int main(){
    int N = 0;
    int M = 0;

    string number[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    cin >> N >> M;

    vector<pair<string, int>> number_pair;

    for(int i=N; i<=M; i++){
        int ten = int(i/10);
        int one = i%10;

        string ten_str="";
        string one_str="";

        for(int j=0; j<10; j++){
            if(ten == j){
                if(j == 0){
                    continue;
                }
                ten_str = number[j];
            }
            
            if(one == j){
                one_str = number[j];
            }
        }
        // cout << ten_str+" "+one_str << "\n";
        if(i<10){
            number_pair.push_back(make_pair(one_str, i));
        }
        else{
            number_pair.push_back(make_pair(ten_str+" "+one_str, i));
        }
    }

    sort(number_pair.begin(), number_pair.end(), comp);

    for(int i=1; i<=number_pair.size(); i++){
        cout << number_pair[i-1].second << " ";
        if(i>=9 && i%10 == 0){
            cout << "\n";
        }
    }

    return 0;
}