#include <iostream>
#include <math.h>

int main(){

    while(1){

        long long G, T, A, D;
        long long X, Y;

        std::cin >> G >> T >> A >> D;
        if (G == -1)
            return 0;

        long long TournamentTeam = G*A + D;

        // std::cout << "TT: " << TournamentTeam << std::endl;

        int i = 63;

        while(pow(2,i) >= TournamentTeam){
            i--;
        } 

        // std::cout << pow(2,i+1) << std::endl;
        Y = pow(2, i+1) - TournamentTeam;

        X = (T*(T-1)/2)*G + pow(2,i+1)-1;

        std::cout << G << "*" << A << "/" << T << "+" << D << "=" << X << "+" << Y << std::endl;
        
    }

    return 0;
}