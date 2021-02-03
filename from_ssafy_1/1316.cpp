#include <iostream>
#include <string>
#include <vector>

int main(){
    int N;
    int counter = 0;

    std::vector<int> checker(26, 0);

    std::cin >> N;
    std::string input;

    for(int i=0; i<N; i++){
        std::cin >> input;

        if(input.length() == 1){
            counter += 1;
            continue;
        }

        for(int j=0; j<input.length(); j++){
            if(checker[input[j]-'a'] == 1){
                break;
            }  
            if(input[j+1] != input[j]){
                checker[input[j]-'a'] = 1;
                if(j+1 == input.length()){
                    counter += 1;
                }
            }
        }
        checker.assign(checker.size(), 0);
    }

    std::cout << counter << std::endl;
}