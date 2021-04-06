#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    int T;

    std::cin >> T;

    for(int i=0; i<T; i++){
        int N;
        
        std::cin >> N;

        std::vector<std::pair<int, int>> v;

        for(int j=0; j<N; j++){
            int x, y;

            std::cin >> x >> y;

            v.push_back(std::make_pair(x, y));
        }

        std::sort(v.begin(), v.end(), std::less<>());

        int count = 1;

        int cut = v[0].second; 

        for(int j=1; j<N; j++){
            if(v[j].second < cut){
                // std::cout << "vec: " << v[j].first << " " << v[j].second << "\n";
                cut = v[j].second;
                count += 1;
            }
        }

        std::cout << count << "\n";

    }

    return 0;
}