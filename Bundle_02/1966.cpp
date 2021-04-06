#include <iostream>
#include <queue>

int main(){

    int N;

    scanf("%d", &N);

    for(int i=0; i<N; i++){
        int D, W;
        int pos;
        int count = 1;

        scanf("%d %d", &D, &W);

        pos = W;

        std::queue<int> docq;
        std::priority_queue<int> pq;

        for(int j=0; j<D; j++){
            int p;
            scanf("%d", &p);
            docq.push(p);
            pq.push(p);
        }

        //set의 0번째 값이랑 지금 0번째가 같으면 나가고 아니면 맨뒤로가
        //set으로하면 안되고 heap으로 해서 하나씩 빼야겠다 그냥.

        while(1){
            // 큐 첫번째랑 pq탑이 같을때
            // std::cout << "pos: " << pos << std::endl;
            if(docq.front() == pq.top()){
                if(pos == 0){
                    printf("%d\n", count);
                    break;
                }
                else{
                    // 프린터에서 뽑힌다
                    docq.pop();
                    pq.pop();
                    pos -= 1;

                    count += 1;
                }
            }
            // pq탑이랑 같은게 아니면 더 작다는 뜻이니까 
            else{
                int temp = docq.front();
                docq.pop();
                docq.push(temp);
                if(pos == 0){
                    pos = docq.size() - 1;
                }
                else{
                    pos -= 1;
                }
                
            }
        }
    }

    return 0;
}