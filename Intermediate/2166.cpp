#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<pair<double, double>> v;

    for(int i=0; i<N; i++){
        double x, y;
        cin >> x >> y;

        v.push_back(make_pair(x, y));
    }

    double sx = v[0].first;
    double sy = v[0].second;

    double answer = 0;

    for(int i=1; i<N-1; i++){
        // 다각형 도형의 면적(넓이) 구하기: https://darkpgmr.tistory.com/86
        double area = (sx*v[i].second + v[i].first*v[i + 1].second + v[i + 1].first*sy) - (v[i].first*sy + v[i + 1].first*v[i].second + sx * v[i + 1].second);
        area /= 2;
        answer += area;
    }

    if(answer < 0){
        answer *= -1;
    }

    printf("%.1f", answer);


    return 0;
}