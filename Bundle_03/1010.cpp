#include <iostream>

int main(){
    
    int N;

    std::cin >> N;

    long long comb[31][31] = {};

    // 1C0 = 1;
    comb[1][0] = 1;

    // 1C1 = 1;
    comb[1][1] = 1;

    // nCr = n-1Cr-1 + n-1Cr
    for(int i=2; i<=30; i++){
        // nC0 = 1;
        comb[i][0] = 1;
        for(int j=1; j<=30; j++){
            comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
        }
    }


    for(int i=0; i<N; i++){
        int n;
        int r;

        std::cin >> r >> n;

        std::cout << comb[n][r] << "\n";
    }

    return 0;
}