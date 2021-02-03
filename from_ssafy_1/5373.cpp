#include <iostream>
#include <vector>
#include <string>

int main(){
    
    std::vector<char> U;
    U.assign(9, 'w');

    std::vector<char> D;
    D.assign(9, 'y');

    std::vector<char> F;
    F.assign(9, 'r');

    std::vector<char> B;
    B.assign(9, 'o');

    std::vector<char> L;
    L.assign(9, 'g');

    std::vector<char> R;
    R.assign(9, 'b');

    int N;

    std::cin >> N;

    for(int i=0; i<N; i++){

        int M;

        std::cin >> M;

        U.assign(9, 'w');
        D.assign(9, 'y');
        F.assign(9, 'r');
        B.assign(9, 'o');
        L.assign(9, 'g');
        R.assign(9, 'b');

        for(int j=0; j<M; j++){
            std::string s;

            std::cin >> s;

            std::vector<char> temp_rotate;
            temp_rotate.reserve(3);
            std::vector<char> temp_face;
            temp_face.reserve(9);

            if(s[0] == 'U'){
                if(s[1] == '+'){
                    // 012345678 >> 630741852
                    // F 012, R 012, B 012, L 012
                    temp_rotate[0] = F[0];
                    temp_rotate[1] = F[1];
                    temp_rotate[2] = F[2];
                    F[0] = R[0];
                    F[1] = R[1];
                    F[2] = R[2];
                    R[0] = B[0];
                    R[1] = B[1];
                    R[2] = B[2];
                    B[0] = L[0];
                    B[1] = L[1];
                    B[2] = L[2];
                    L[0] = temp_rotate[0];
                    L[1] = temp_rotate[1];
                    L[2] = temp_rotate[2];

                    std::copy(U.begin(), U.end(), temp_face.begin());

                    U[0] = temp_face[6];
                    U[1] = temp_face[3];
                    U[2] = temp_face[0];
                    U[3] = temp_face[7];
                    U[4] = temp_face[4];
                    U[5] = temp_face[1];
                    U[6] = temp_face[8];
                    U[7] = temp_face[5];
                    U[8] = temp_face[2];
                }
                else if(s[1] == '-'){
                    // 012345678 >> 258147036
                    // F 012, R 012, B 012, L 012
                    temp_rotate[0] = F[0];
                    temp_rotate[1] = F[1];
                    temp_rotate[2] = F[2];
                    F[0] = L[0];
                    F[1] = L[1];
                    F[2] = L[2];
                    L[0] = B[0];
                    L[1] = B[1];
                    L[2] = B[2];
                    B[0] = R[0];
                    B[1] = R[1];
                    B[2] = R[2];
                    R[0] = temp_rotate[0];
                    R[1] = temp_rotate[1];
                    R[2] = temp_rotate[2];

                    std::copy(U.begin(), U.end(), temp_face.begin());

                    U[0] = temp_face[2];
                    U[1] = temp_face[5];
                    U[2] = temp_face[8];
                    U[3] = temp_face[1];
                    U[4] = temp_face[4];
                    U[5] = temp_face[7];
                    U[6] = temp_face[0];
                    U[7] = temp_face[3];
                    U[8] = temp_face[6];
                }
            }
            else if(s[0] == 'D'){
                if(s[1] == '+'){
                    // 012345678 >> 630741852
                    // F 678, R 678, B 678, L 678
                    temp_rotate[0] = F[6];
                    temp_rotate[1] = F[7];
                    temp_rotate[2] = F[8];
                    F[6] = L[6];
                    F[7] = L[7];
                    F[8] = L[8];
                    L[6] = B[6];
                    L[7] = B[7];
                    L[8] = B[8];
                    B[6] = R[6];
                    B[7] = R[7];
                    B[8] = R[8];
                    R[6] = temp_rotate[0];
                    R[7] = temp_rotate[1];
                    R[8] = temp_rotate[2];

                    std::copy(D.begin(), D.end(), temp_face.begin());

                    D[0] = temp_face[6];
                    D[1] = temp_face[3];
                    D[2] = temp_face[0];
                    D[3] = temp_face[7];
                    D[4] = temp_face[4];
                    D[5] = temp_face[1];
                    D[6] = temp_face[8];
                    D[7] = temp_face[5];
                    D[8] = temp_face[2];

                }
                else if(s[1] == '-'){
                    // 012345678 >> 258147036
                    // F 678, R 678, B 678, L 678
                    temp_rotate[0] = F[6];
                    temp_rotate[1] = F[7];
                    temp_rotate[2] = F[8];
                    F[6] = R[6];
                    F[7] = R[7];
                    F[8] = R[8];
                    R[6] = B[6];
                    R[7] = B[7];
                    R[8] = B[8];
                    B[6] = L[6];
                    B[7] = L[7];
                    B[8] = L[8];
                    L[6] = temp_rotate[0];
                    L[7] = temp_rotate[1];
                    L[8] = temp_rotate[2];

                    std::copy(D.begin(), D.end(), temp_face.begin());

                    D[0] = temp_face[2];
                    D[1] = temp_face[5];
                    D[2] = temp_face[8];
                    D[3] = temp_face[1];
                    D[4] = temp_face[4];
                    D[5] = temp_face[7];
                    D[6] = temp_face[0];
                    D[7] = temp_face[3];
                    D[8] = temp_face[6];

                }
            }
            else if(s[0] == 'F'){
                if(s[1] == '+'){
                    // 012345678 >> 630741852
                    // U 678, R 036, D 210, L 852
                    temp_rotate[0] = U[6];
                    temp_rotate[1] = U[7];
                    temp_rotate[2] = U[8];
                    U[6] = L[8];
                    U[7] = L[5];
                    U[8] = L[2];
                    L[8] = D[2];
                    L[5] = D[1];
                    L[2] = D[0];
                    D[2] = R[0];
                    D[1] = R[3];
                    D[0] = R[6];
                    R[0] = temp_rotate[0];
                    R[3] = temp_rotate[1];
                    R[6] = temp_rotate[2];

                    std::copy(F.begin(), F.end(), temp_face.begin());

                    F[0] = temp_face[6];
                    F[1] = temp_face[3];
                    F[2] = temp_face[0];
                    F[3] = temp_face[7];
                    F[4] = temp_face[4];
                    F[5] = temp_face[1];
                    F[6] = temp_face[8];
                    F[7] = temp_face[5];
                    F[8] = temp_face[2];
                }
                else if(s[1] == '-'){
                    // 012345678 >> 258147036
                    // U 678, R 036, D 210, L 852
                    temp_rotate[0] = U[6];
                    temp_rotate[1] = U[7];
                    temp_rotate[2] = U[8];
                    U[6] = R[0];
                    U[7] = R[3];
                    U[8] = R[6];
                    R[0] = D[2];
                    R[3] = D[1];
                    R[6] = D[0];
                    D[2] = L[8];
                    D[1] = L[5];
                    D[0] = L[2];
                    L[8] = temp_rotate[0];
                    L[5] = temp_rotate[1];
                    L[2] = temp_rotate[2];

                    std::copy(F.begin(), F.end(), temp_face.begin());

                    F[0] = temp_face[2];
                    F[1] = temp_face[5];
                    F[2] = temp_face[8];
                    F[3] = temp_face[1];
                    F[4] = temp_face[4];
                    F[5] = temp_face[7];
                    F[6] = temp_face[0];
                    F[7] = temp_face[3];
                    F[8] = temp_face[6];
                }
            }
            else if(s[0] == 'B'){
                if(s[1] == '+'){
                    // 012345678 >> 630741852
                    // U 210, L 036, D 678, R 852
                    temp_rotate[0] = U[2];
                    temp_rotate[1] = U[1];
                    temp_rotate[2] = U[0];
                    U[2] = R[8];
                    U[1] = R[5];
                    U[0] = R[2];
                    R[8] = D[6];
                    R[5] = D[7];
                    R[2] = D[8];
                    D[6] = L[0];
                    D[7] = L[3];
                    D[8] = L[6];
                    L[0] = temp_rotate[0];
                    L[3] = temp_rotate[1];
                    L[6] = temp_rotate[2];

                    std::copy(B.begin(), B.end(), temp_face.begin());

                    B[0] = temp_face[6];
                    B[1] = temp_face[3];
                    B[2] = temp_face[0];
                    B[3] = temp_face[7];
                    B[4] = temp_face[4];
                    B[5] = temp_face[1];
                    B[6] = temp_face[8];
                    B[7] = temp_face[5];
                    B[8] = temp_face[2];
                }
                else if(s[1] == '-'){
                    // 012345678 >> 258147036
                    // U 210, L 036, D 678, R 852
                    temp_rotate[0] = U[2];
                    temp_rotate[1] = U[1];
                    temp_rotate[2] = U[0];
                    U[2] = L[0];
                    U[1] = L[3];
                    U[0] = L[6];
                    L[0] = D[6];
                    L[3] = D[7];
                    L[6] = D[8];
                    D[6] = R[8];
                    D[7] = R[5];
                    D[8] = R[2];
                    R[8] = temp_rotate[0];
                    R[5] = temp_rotate[1];
                    R[2] = temp_rotate[2];

                    std::copy(B.begin(), B.end(), temp_face.begin());

                    B[0] = temp_face[2];
                    B[1] = temp_face[5];
                    B[2] = temp_face[8];
                    B[3] = temp_face[1];
                    B[4] = temp_face[4];
                    B[5] = temp_face[7];
                    B[6] = temp_face[0];
                    B[7] = temp_face[3];
                    B[8] = temp_face[6];
                }
            }
            else if(s[0] == 'L'){
                if(s[1] == '+'){
                    // 012345678 >> 630741852
                    // U 036, F 036, D 036, B 852
                    temp_rotate[0] = U[0];
                    temp_rotate[1] = U[3];
                    temp_rotate[2] = U[6];
                    U[0] = B[8];
                    U[3] = B[5];
                    U[6] = B[2];
                    B[8] = D[0];
                    B[5] = D[3];
                    B[2] = D[6];
                    D[0] = F[0];
                    D[3] = F[3];
                    D[6] = F[6];
                    F[0] = temp_rotate[0];
                    F[3] = temp_rotate[1];
                    F[6] = temp_rotate[2];

                    std::copy(L.begin(), L.end(), temp_face.begin());

                    L[0] = temp_face[6];
                    L[1] = temp_face[3];
                    L[2] = temp_face[0];
                    L[3] = temp_face[7];
                    L[4] = temp_face[4];
                    L[5] = temp_face[1];
                    L[6] = temp_face[8];
                    L[7] = temp_face[5];
                    L[8] = temp_face[2];
                }
                else if(s[1] == '-'){
                    // 012345678 >> 258147036
                    temp_rotate[0] = U[0];
                    temp_rotate[1] = U[3];
                    temp_rotate[2] = U[6];
                    U[0] = F[0];
                    U[3] = F[3];
                    U[6] = F[6];
                    F[0] = D[0];
                    F[3] = D[3];
                    F[6] = D[6];
                    D[0] = B[8];
                    D[3] = B[5];
                    D[6] = B[2];
                    B[8] = temp_rotate[0];
                    B[5] = temp_rotate[1];
                    B[2] = temp_rotate[2];

                    std::copy(L.begin(), L.end(), temp_face.begin());

                    L[0] = temp_face[2];
                    L[1] = temp_face[5];
                    L[2] = temp_face[8];
                    L[3] = temp_face[1];
                    L[4] = temp_face[4];
                    L[5] = temp_face[7];
                    L[6] = temp_face[0];
                    L[7] = temp_face[3];
                    L[8] = temp_face[6];
                }
            }
            else if(s[0] == 'R'){
                if(s[1] == '+'){
                    // 012345678 >> 630741852
                    // U 258, F 258, D 258, B 630
                    temp_rotate[0] = U[2];
                    temp_rotate[1] = U[5];
                    temp_rotate[2] = U[8];
                    U[2] = F[2];
                    U[5] = F[5];
                    U[8] = F[8];
                    F[2] = D[2];
                    F[5] = D[5];
                    F[8] = D[8];
                    D[2] = B[6];
                    D[5] = B[3];
                    D[8] = B[0];
                    B[6] = temp_rotate[0];
                    B[3] = temp_rotate[1];
                    B[0] = temp_rotate[2];

                    std::copy(R.begin(), R.end(), temp_face.begin());

                    R[0] = temp_face[6];
                    R[1] = temp_face[3];
                    R[2] = temp_face[0];
                    R[3] = temp_face[7];
                    R[4] = temp_face[4];
                    R[5] = temp_face[1];
                    R[6] = temp_face[8];
                    R[7] = temp_face[5];
                    R[8] = temp_face[2];

                }
                else if(s[1] == '-'){
                    // 012345678 >> 258147036
                    // U 258, F 258, D 258, B 630
                    temp_rotate[0] = U[2];
                    temp_rotate[1] = U[5];
                    temp_rotate[2] = U[8];
                    U[2] = B[6];
                    U[5] = B[3];
                    U[8] = B[0];
                    B[6] = D[2];
                    B[3] = D[5];
                    B[0] = D[8];
                    D[2] = F[2];
                    D[5] = F[5];
                    D[8] = F[8];
                    F[2] = temp_rotate[0];
                    F[5] = temp_rotate[1];
                    F[8] = temp_rotate[2];

                    std::copy(R.begin(), R.end(), temp_face.begin());

                    R[0] = temp_face[2];
                    R[1] = temp_face[5];
                    R[2] = temp_face[8];
                    R[3] = temp_face[1];
                    R[4] = temp_face[4];
                    R[5] = temp_face[7];
                    R[6] = temp_face[0];
                    R[7] = temp_face[3];
                    R[8] = temp_face[6];
                }
            }
        }
        for(int k=0; k<9; k++){
            std::cout << U[k];
            if(k == 2 || k == 5 || k == 8){
                std::cout << std::endl;
            }
        }
    }

    return 0;
}