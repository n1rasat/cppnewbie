#include <iostream>
#include <deque>

using namespace std;

int N, M;
int main(){
    cin >> N >> M;

    // 0: dodo, 1: susu
    deque<int> dq[2];
    deque<int> gr[2];

    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        // 앞에다가 집어넣는다. 
        dq[0].push_front(x);
        dq[1].push_front(y);
    }

    int game = M;
    int turn = 0;
    while(game--){
        if(game%2 != M%2){
            turn = 0;
        }
        else{
            turn = 1;
        }
        // 덱 맨 위에 있는 카드를 꺼낸다
        int front = dq[turn].front();
        gr[turn].push_front(front);
        dq[turn].pop_front();

        // 비었는지 확인
        if(dq[0].empty() || dq[1].empty())
            break;

        // 도도가 카드를 먹는다.
        if(front == 5){
            while(!gr[1].empty()){
                dq[0].push_back(gr[1].back());
                gr[1].pop_back();
            }
            while(!gr[0].empty()){
                dq[0].push_back(gr[0].back());
                gr[0].pop_back();
            }

            front = 0;
        }

        // 수가 카드를 먹는다.
        if((!gr[turn].empty() && front + gr[turn].front() == 5) || (!gr[1-turn].empty() && front + gr[1-turn].front() == 5)){
            while(!gr[0].empty()){
                dq[1].push_back(gr[0].back());
                gr[0].pop_back();
            }
            while(!gr[1].empty()){
                dq[1].push_back(gr[1].back());
                gr[1].pop_back();
            }

            front = 0;
        }
    }

    if(dq[0].size() > dq[1].size()){
        cout << "do";
    }
    else if(dq[0].size() < dq[1].size()){
        cout << "su";
    }
    else{
        cout << "dosu";
    }

    return 0;
}
