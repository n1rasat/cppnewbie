#include <iostream>
#include <vector>

int main(){

    int N;
    int K;

    std::cin >> N >> K;

    int recursive = N;

    std::vector<int> v;
    v.assign(N+1, 0);

    int printer = 0;

    int counter = 0;
    printf("<");
    while(recursive>0){
    
        printer += 1;

        if(printer > N){
            printer -= N;
        }

        // 이미 봤으면
        if(v[printer] == 1){
            continue;
        }
        else{
            counter += 1;

            if(counter == K && recursive == 1){
                v[printer] = 1;
                printf("%d", printer);
                counter = 0;
                recursive -= 1;
            }
            else if(counter == K){
                v[printer] = 1;
                printf("%d, ", printer);
                counter = 0;
                recursive -= 1;
            }
        }
    }
    printf(">");


    return 0;
}