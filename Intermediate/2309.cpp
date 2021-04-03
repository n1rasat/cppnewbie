#include <iostream>
#include <algorithm>

using namespace std;

int map[9] = {0, };

int main(){

    int sum = 0;

    for(int i=0; i<9; i++){
        cin >> map[i];
        sum += map[i];
    }

    for(int i=0; i<9; i++){
        for(int j=i+1; j<9; j++){
            if((sum - map[i] - map[j]) == 100){
                map[i] = 999;
                map[j] = 999;
                i = 9;
                break;
            }
        }
    }
    
    sort(map, map+9);

    for(int i=0; i<7; i++){
        cout << map[i] << "\n";
    }

    return 0;
}