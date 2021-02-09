/*
    ERROR CASE
    If stack has intermediate result value like 40 or 41 or 91 or 93, program returns inaccurate final result.
*/

#include <iostream>
#include <string>
#include <stack>

int main(){

    std::string s;

    std::cin >> s;

    std::stack<int> stk;

    int result = 0;
    int temp = 0;

    // stack에 ( 나 [ 가 들어가있는지 체크
    int smallstk = 0;
    int largestk = 0;

    // (: 40, ): 41, [: 91, ]: 93
    for(int i=0; i<s.length(); i++){
        if(s[i] == 40){
            stk.push(s[i]);
            smallstk += 1;
        }
        else if(s[i] == 91){
            stk.push(s[i]);
            largestk += 1;
        }
        else if(s[i] == 41){
            while(1){
                if(stk.empty()){
                    std::cout << 0;
                    return 0;
                }
                if(stk.top() == 91){
                    std::cout << 0;
                    return 0;
                }
                else if(stk.top() == 40){
                    stk.pop();
                    if(temp == 0)
                        temp = 1;
                    temp *= 2;
                    stk.push(temp);
                    smallstk -= 1;
                    break;
                }
                temp += stk.top();
                stk.pop();
            }

        }
        else if(s[i] == 93){
            while(1){
                if(stk.empty()){
                    std::cout << 0;
                    return 0;
                }
                if(stk.top() == 40){
                    std::cout << 0;
                    return 0;
                }
                else if(stk.top() == 91){
                    stk.pop();
                    if(temp == 0)
                        temp = 1;
                    temp *= 3;
                    stk.push(temp);
                    largestk -= 1;
                    break;
                }
                temp += stk.top();
                stk.pop();
            }
        }

        // ( 나 [ 없이 정수만 들어가있는 경우 하나의 괄호 세트가 끝났다는 뜻.
        if(smallstk == 0 && largestk == 0){
            while(!stk.empty()){
                result += stk.top();
                stk.pop();
            }
        }

        temp = 0;
    }

    // 끝나고도 괄호가 남아있는 경우
    if(smallstk != 0 || largestk != 0){
        std::cout << 0;
        return 0;
    }

    while(!stk.empty()){
        result += stk.top();
        stk.pop();
    }

    std::cout << result;

    return 0;
}