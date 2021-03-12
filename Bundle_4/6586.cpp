#include <iostream>
#include <vector>

using namespace std;

int main(){

    while(1){
        int N;
        cin >> N;
        
        if(N == 0){
            break;
        }

        int arr[101][101] = {0, };
        
        int sumi[101] = {0, };
        int sumj[101] = {0, };

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                int x;
                cin >> x;
                arr[i][j] = x;
                if(x == 1){
                    sumi[i] += 1;
                    sumj[j] += 1;
                }   
            }
        }

        vector<int> posi;
        vector<int> posj;

        for(int i=1; i<=N; i++){
            if(sumi[i]%2 == 1){
                posi.push_back(i);
            }

            if(sumj[i]%2 == 1){
                posj.push_back(i);
            }
        }

        if(posi.size() == 1 && posi.size() == 1){
            cout << "Change bit (" << posi.front() << "," << posj.front() << ")\n";
        }
        else if(posi.empty() && posj.empty()){
            cout << "OK\n";
        }
        else{
            cout << "Corrupt\n";
        }
    }

    return 0;
}