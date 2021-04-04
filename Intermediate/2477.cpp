#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> v;

    int max = 0;
    int maxpos = 0;

    for(int i=0; i<6; i++){
        int t, x;
        cin >> t >> x;
        v.push_back(x);
    }

    for(int i=0; i<6; i++){
        int area = v[i] * v[(i+1)%6];
        if(area > max){
            max = area;
            maxpos = i;
        }
    }

    cout << v[maxpos] << " " << v[(maxpos+1)%6] << "\n";

    cout << v[(maxpos+3)%6] << " " << v[(maxpos+4)%6] << "\n";

    cout << N * ((v[maxpos]*v[(maxpos+1)%6]) - (v[(maxpos+3)%6]*v[(maxpos+4)%6]));


    return 0;
}