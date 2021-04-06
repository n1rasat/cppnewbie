#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){

    int k;

    cin >> k;

    vector<char> v;

    getchar();
    for(int i=0; i<k; i++){
        char ch;
        ch = getchar();
        v.push_back(ch);
        getchar();
    }

    int numbersmax[11];
    int numbersmin[11];

    for(int i=0; i<=k; i++){
        numbersmin[i] = i;
        numbersmax[i] = 9-i;
    }

    do{
        int i=0; 
        for(i=0; i<=k; i++){
            if(v[i] == '<'){
                if(numbersmax[i] > numbersmax[i+1]){
                    break;
                }
            }
            else if(v[i] == '>'){
                if(numbersmax[i] < numbersmax[i+1]){
                    break;
                }
            }
        }

        if(i == k+1){
            for(int j=0; j<=k; j++){
                printf("%d", numbersmax[j]);
            }
            break;
        }


    }while(prev_permutation(numbersmax, numbersmax+(k+1)));

    printf("\n");

    do{
        int i=0; 
        for(i=0; i<=k; i++){
            if(v[i] == '<'){
                if(numbersmin[i] > numbersmin[i+1]){
                    break;
                }
            }
            else if(v[i] == '>'){
                if(numbersmin[i] < numbersmin[i+1]){
                    break;
                }
            }
        }

        if(i == k+1){
            for(int j=0; j<=k; j++){
                printf("%d", numbersmin[j]);
            }
            break;
        }

    }while(next_permutation(numbersmin, numbersmin+(k+1)));

    return 0;
}