#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[21][21] = {0, };

int main(){

    int N;

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int x;
            cin >> x;  
            arr[i][j] = x;
        }
    }

    vector<int> filter;
    for(int i=0; i<N/2; i++){
        filter.push_back(1);
    }

    for(int i=N/2; i<N; i++){
        filter.push_back(0);
    }

    sort(filter.begin(), filter.end(), less<int>());

    int answer = 987654321;

    do{
        vector<int> start_team;
        vector<int> link_team;
        for(int i=0; i<filter.size(); i++){
            if(filter[i] == 1){
                start_team.push_back(i);
            }
            else{
                link_team.push_back(i);
            }
        }

        int start_sum = 0;
        int link_sum = 0;
        
        for(int i=0; i<N/2; i++){
            for(int j=i+1; j<N/2;j++){
                start_sum += arr[start_team[i]][start_team[j]] + arr[start_team[j]][start_team[i]];
                link_sum += arr[link_team[i]][link_team[j]] + arr[link_team[j]][link_team[i]];
            }
        }
        
        int temp = abs(start_sum-link_sum);

        if(answer > temp){
            answer = temp;
        }

    }while(next_permutation(filter.begin(), filter.end()));

    cout << answer;

    return 0;
}