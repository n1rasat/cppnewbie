#include <iostream>
#include <queue>

int main(){
    // std::cin.tie(0);
    // std::cin.sync_with_stdio(0);

    int N;
    
    std::queue<int> q;

    // std::string s;
    char s[6];

    // std::cin >> N;
    scanf("%d", &N);

    for(int i=0; i<N; i++){
        // std::cin >> s;
        scanf("%s", s);

        if(s[1] == 'u'){
            int t;
            // std::cin >> t;
            scanf("%d", &t);
            q.push(t);
        }
        else if(s[0] == 'p'){
            if(q.empty()){
                // std::cout << -1 << "\n";
                printf("-1\n"); 
            }
            else{
                printf("%d\n", q.front());
                // std::cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(s[0] == 's'){
            printf("%d\n", q.size());
            // std::cout << q.size() << "\n";
        }
        else if(s[0] == 'e'){
            if(q.empty()){
                // std::cout << 1 << "\n";
                printf("1\n");
            }
            else{
                // std::cout << 0 << "\n";
                printf("0\n");
            }
        }
        else if(s[0] == 'f'){
            if(q.empty()){
                // std::cout << -1 << "\n";
                printf("-1\n");
            }
            else{
                // std::cout << q.front() << "\n";
                printf("%d\n", q.front());
            }
        }
        else if(s[0] == 'b'){
            if(q.empty()){
                // std::cout << -1 << "\n";
                printf("-1\n");
            }
            else{
                // std::cout << q.back() << "\n";
                printf("%d\n", q.back());
            }
        }
    }

    return 0;
}