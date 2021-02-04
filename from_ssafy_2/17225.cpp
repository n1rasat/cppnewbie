#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

int main(){

    int A, B, N;

    std::cin >> A >> B >> N;

    int Bstack = 0; 
    int Rstack = 0;

    std::map<int, int> Bmap;
    std::map<int, int> Rmap;

    for(int i=0; i<N; i++){
        int x, z;
        char ch;

        std::cin >> x >> ch >> z;

        if(ch == 'B'){
            Bmap[x] = z;

        }
        else if(ch == 'R'){
            Rmap[x] = z;
        }
    }

    // std::for_each(Bmap.begin(), Bmap.end(), [&](std::pair<int, int> itr) {
    //     std::cout << itr.first << " " << itr.second << std::endl;
    //     });

    //count: 없으면 0 있으면 1
    // std::cout << Bmap.count(2);
    
    // if(Bmap.count(1)){
    //     std::cout << "\n zonzai! " << Bmap[1];
    // }

    int Aiswork = 0;
    int Biswork = 0;

    std::vector<int> Acount;
    std::vector<int> Bcount;

    int count = 1;
    int clock = 1;
    while(1){
        // 시간이 1초씩 흐른다.
        if(Bmap.count(clock)){
            Bstack += Bmap[clock];
            Bmap.erase(clock);
        }
        else if(Rmap.count(clock)){
            Rstack += Rmap[clock];
            Rmap.erase(clock);
        }

        // std::cout << "stacks: " << Bstack << " " << Rstack << " time: " << clock << std::endl;

        // A가 일하는 중이면
        if(Aiswork >0){
            Aiswork -= 1;
        }
        // A가 놀고있고 물건 B가 1개이상이면
        
        if((Aiswork == 0) && (Bstack > 0)){
            Acount.push_back(count);
            count += 1;
            Aiswork = A;
            Bstack -= 1;
        }

        // B가 일하는 중이면
        if(Biswork > 0){
            Biswork -= 1;
        }
        // B가 놀고있고 물건 R이 1개 이상이면
        if((Biswork == 0) && (Rstack > 0)){
            Bcount.push_back(count);
            count += 1;
            Biswork = B;
            Rstack -= 1;
        }
        
        // std::cout << "stacks: " << Bstack << " " << Rstack << " time: " << clock << std::endl;

        // 일 없으면
        if(Bmap.empty() && Rmap.empty() && (Bstack == 0) && (Rstack == 0)){
            break;
        }

        clock += 1;
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