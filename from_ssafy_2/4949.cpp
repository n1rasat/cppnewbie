#include <iostream>
#include <stack>
#include <string>

int main(){

    std::stack<char> stk;

    int i = 0;
    char ch;
    std::string cs;

    while(1){
        while(ch = getchar()){
            cs.append(1, ch);
            if(ch == '.')
                break;
        }

        // \n 문자 포함한 길이...
        if(cs.length() == 2 && cs[cs.length()-1] == '.')
            break;
        
        for(i=0; i<cs.length(); i++){
            if(cs[i] == '(' || cs[i] == '['){
                stk.push(cs[i]);
            }

            if(cs[i] == ')'){
                if(stk.size() != 0 && stk.top() == '('){
                    stk.pop();
                }
                else{
                    std::cout << "no" << std::endl;
                    break;
                }
            }

            if(cs[i] == ']'){
                if(stk.size() != 0 && stk.top() == '['){
                    stk.pop();
                }
                else{
                    std::cout << "no" << std::endl;
                    break;
                }
            }

        }
        if(i == cs.length()){
            if(stk.empty()){
                std::cout << "yes" << std::endl;
            }
            else{
                std::cout << "no" << std::endl;
            }
        }

        // initialize
        while(!stk.empty()) stk.pop();
        cs.clear();
        i = 0;
    }

    return 0;
}