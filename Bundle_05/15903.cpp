#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

    int n, m;

    cin >> n >> m;

    priority_queue<long long> card;

    for(int i=0; i<n; i++){
        long long x;
        cin >> x;
        card.push(-x);
    }

    for(int i=0; i<m; i++){
        long long first = card.top();
        card.pop();
        long long second = card.top();
        card.pop();

        long long sum = first + second;

        card.push(sum);
        card.push(sum);
    }

    long long answer = 0;

    while(!card.empty()){
        answer -= card.top();
        card.pop();
    }

    cout << answer;

    return 0;
}