#include <iostream>
#include <stack>

int arr[101][101] = {0, };

using namespace std;
int main(){

    int N;
    
    cin >> N;

    for(int i=0; i<N; i++){
        int x;
        int y;
        int d;
        int g;

        cin >> x >> y >> d >> g;

        arr[x][y] = 1;
        
        int next_x;
        int next_y;
        
        if(d == 0){
            next_x = x+1;
            next_y = y;
        }
        else if(d == 1){
            next_x = x;
            next_y = y-1;
        }
        else if(d == 2){
            next_x = x-1;
            next_y = y;
        }
        else if(d == 3){
            next_x = x;
            next_y = y+1;
        }

        if(next_x >= 0 && next_x <= 100 && next_y >= 0 && next_y <= 100){
            arr[next_x][next_y] = 1;
        }

        x = next_x;
        y = next_y;

        stack<int> dir;

        dir.push(d);

        for(int i=1; i<=g; i++){
            stack<int> temp = dir;
            // cout << i << "th generation\n";

            while(!temp.empty()){
                d = temp.top();
                int next_d = d+1;
                if(next_d == 4){
                    next_d = 0;
                }
                // cout << "next_d: " << next_d << "\n";
                temp.pop();

                if(next_d == 0){
                    next_x = x+1;
                    next_y = y;
                }
                else if(next_d == 1){
                    next_x = x;
                    next_y = y-1;
                }
                else if(next_d == 2){
                    next_x = x-1;
                    next_y = y;
                }
                else if(next_d == 3){
                    next_x = x;
                    next_y = y+1;
                }

                if(next_x >= 0 && next_x <= 100 && next_y >= 0 && next_y <= 100){
                    arr[next_x][next_y] = 1;
                }

                x = next_x;
                y = next_y;

                dir.push(next_d);
            }
        }
    }

    int answer = 0;

    for(int i=0; i<100; i++){
        for(int j=0; j<100; j++){
            if(arr[i][j] == 1 && arr[i+1][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j+1] == 1){
                answer += 1;
            }
        }
    }

    cout << answer;

    return 0;
}