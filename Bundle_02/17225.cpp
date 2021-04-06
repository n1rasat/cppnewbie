#include <iostream>
#include <algorithm>
#include <vector>

int main(){

    int A, B, N;

    std::cin >> A >> B >> N;

    std::vector<std::pair<int, int>> Bv;
    std::vector<std::pair<int, int>> Rv;

    for(int i=0; i<N; i++){
        int x, z;
        char ch;

        std::cin >> x >> ch >> z;

        if(ch == 'B'){
            Bv.push_back(std::make_pair(x, z));

        }
        else if(ch == 'R'){
            Rv.push_back(std::make_pair(x, z));
        }
    }

    int count = 1;

    std::vector<int> Acount;
    std::vector<int> Bcount;

    while(1){
        //더이상 포장할게 없다는 뜻.
        if(Bv.empty() && Rv.empty()){
            break;
        }

        //선물이 없으면 다음 선물 갖고와야지
        if(!Bv.empty() && Bv[0].second == 0){
            if(Bv.size() == 1){
                Bv.clear();
                continue;
            }
            else{
                int temp1 = Bv[0].first;
                int temp2 = Bv[1].first;

                Bv.erase(Bv.begin());

                if(temp1 >= temp2){
                    Bv[0].first = temp1;
                } 
            }
        }

        if(!Rv.empty() && Rv[0].second == 0){
            if(Rv.size() == 1){
                Rv.clear();
                continue;
            }
            else{
                int temp1 = Rv[0].first;
                int temp2 = Rv[1].first;

                Rv.erase(Rv.begin());

                if(temp1 >= temp2){
                    Rv[0].first = temp1;
                }   
            }
        }

        //A가 일없으면 B가 일해야지
        if(Bv.empty()){
            Rv[0].first += B;
            Rv[0].second -= 1;

            Bcount.push_back(count);

            count += 1;
        }
        else if(Rv.empty()){
            Bv[0].first += A;
            Bv[0].second -= 1;

            Acount.push_back(count);

            count += 1;
        }
        else{
            // 더 빠른놈이 선물 가져감 
            if(Bv[0].first <= Rv[0].first){
                Bv[0].first += A;
                Bv[0].second -= 1;

                Acount.push_back(count);

                count += 1;
            }
            else if(Bv[0].first > Rv[0].first){
                Rv[0].first += B;
                Rv[0].second -= 1;

                Bcount.push_back(count);

                count += 1;
            }
        }
    }

    std::cout << Acount.size() << std::endl;

    for(int i=0; i<Acount.size(); i++){
        std::cout << Acount[i] << " ";
    }
    std::cout<< "\n" << Bcount.size() << std::endl;
    
    for(int i=0; i<Bcount.size(); i++){
        std::cout << Bcount[i] << " ";
    }

    return 0;

}