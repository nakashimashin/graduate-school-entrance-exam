#include <iostream>
using namespace std;
#define M 4
#define N 2
#define L 3
int main(void)
{
    int i, j, k;
    int A[M][L], B[L][N];
    cout << "A(4x3)?" << endl;
    for(i=0; i<M; i++)
        for(j=0; j<L; j++){
            cin >> A[i][j];
        }

    cout << "B(3x2)?" << endl;
    for(i=0; i<L; i++)
        for(j=0; j<N; j++){
            cin >> B[i][j];
        }

    /* （解答用紙に記入すること） */
    int C[M][N];

    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            C[i][j] = 0;
            for(k=0; k<L; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for(i=0; i<M; i++){
        for(j=0; j<N; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
