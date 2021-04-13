#include <iostream>

using namespace std;

int main(){
    int x, y, p, q;
    int xx, yy, pp, qq;

    for(int i=0; i<4; i++){
        cin >> x >> y >> p >> q >> xx >> yy >> pp >> qq;

        if((x == pp && y == qq) || (p == xx && q == yy) || (x == pp && q == yy) || (p == xx && y == qq)){
            cout << "c" << "\n";
        }
        else if(x > pp || y > qq || p < xx || q < yy){
            cout << "d" << "\n";

        }
        else if((x != pp && y == qq) || (x == pp && q != yy) || (p != xx && y == qq) || (p == xx && q != yy)){
            cout << "b" << "\n";
        }
        else{
            cout << "a" << "\n";
        }
    }

    return 0;

}