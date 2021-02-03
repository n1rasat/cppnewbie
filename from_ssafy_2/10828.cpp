#include <iostream>
#include <vector>
#include <string>

void psh(int x, std::vector<int> &stk){
    stk.push_back(x);
}

void pp(std::vector<int> &stk){
    if(stk.size() > 0){
        std::cout << stk[stk.size()-1] << std::endl;
        stk.pop_back();
    }
    else{
        std::cout << -1 << std::endl;
    }
}

void emp(std::vector<int> &stk){
    if(stk.size() > 0){
        std::cout << 0 << std::endl;
    }
    else{
        std::cout << 1 << std::endl;
    }
}

void tp(std::vector<int> &stk){
    if(stk.size() > 0){
        std::cout << stk[stk.size()-1] << std::endl;
    }
    else{
        std::cout << -1 << std::endl;
    }
}

int main(){

    int N;
    
    std::vector<int> stack;

    std::string s;
    int t;

    std::cin >> N;

    for(int i=0; i<N; i++){
        std::cin >> s;

        if(s.find("push") != std::string::npos){
            std::cin >> t;
            psh(t, stack);
        }
        else if(s.find("pop") != std::string::npos){
            pp(stack);
        }
        else if(s.find("size") != std::string::npos){
            std::cout << stack.size() << std::endl;
        }
        else if(s.find("empty") != std::string::npos){
            emp(stack);
        }
        else if(s.find("top") != std::string::npos){
            tp(stack);
        }
    }




    return 0;
}