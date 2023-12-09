#include <iostream>
#include "SparseMatrix.h"

using namespace std;

int main(void){
    int r = 0, c = 0;                   //r = 행, c = 열
    int terms = 0;
    cin >> r >> c;                      //행과 열 입력
    
    int** A = new int *[r];             //A[r][c], 행의 크기 선언
    int** T = new int *[c];             //A의 전치행렬 T[c][r], 행 크기 선언
    SparseMatrix sA;                    //A의 SparseMatrix
    SparseMatrix sT;                    //A의 SparseMatrix 의 전치행렬
    
    for(int i = 0; i < r; i++){
        A[i] = new int[c];              //각 행의 열의 크기 선언
        T[i] = new int[r];              //각 행의 열의 크기 선언, 전치행렬이므로 r이 열
    }
    
    for(int i = 0; i < r; i++){         //행렬 입력
        for(int j = 0; j < c; j++){
            cin >> A[i][j];
            T[j][i]= A[i][j];           //A의 전치행렬 T
            if(A[i][j] != 0) {
                terms++;
            }
        }
    }
    
    if((r * c) > terms * 3){            //SparseMatrix 방식이 효율적일 때
        cout << "2" <<endl;
        for(int i = 0; i < r; i ++){
            for(int j = 0; j < c; j++){
                if(A[i][j] != 0){
                    sA.NewTerm(i + 1, j + 1, A[i][j]);
                }
            }
        }
        sT = sA.Transpose();
        cout << sT;
    }
    
    else {                              //A[n][m] 방식이 효율적일 때 A 전치행렬인 T 출력
        cout << "1" << endl;
        for(int i = 0; i < c; i++){
            for(int j = 0; j < r; j++){
                cout << T[i][j] << " ";
            }
            cout << endl;
        }
    }
}
