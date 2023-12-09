#include <iostream>
#include "SparseMatrix.h"

using namespace std;

MatrixTerm::MatrixTerm(){                                   //생성자(인자x)
    row = 0;
    col = 0;
    value = 0;
}

MatrixTerm::MatrixTerm(int r, int c, int v){                //생성자
    row = r;
    col = c;
    value = c;
}
MatrixTerm::~MatrixTerm(){}                                 //파괴자

int MatrixTerm::Getrow(){                                   //row 값 반환
    return row;
}
int MatrixTerm::Getcol(){                                   //col 값 반환
    return col;
}
int MatrixTerm::Getvalue(){                                 //value 값 반환
    return value;
}

SparseMatrix::SparseMatrix(){                               //생성자(인자x)
    Cols = 0;
    Terms = 0;
    capacity = 1;
    smArray = new MatrixTerm[1];
}

SparseMatrix::SparseMatrix(int C, int T, int cap){          //생성자
    Cols = C;
    Terms = T;
    capacity = cap;
    smArray = new MatrixTerm[T];
}

SparseMatrix::~SparseMatrix(){}                             //파괴자

SparseMatrix SparseMatrix::Transpose(){                     //행렬 전치
    SparseMatrix b(Cols, Terms, capacity);
    Cols = Terms + 1;
    if(Terms > 0){
        int currentB = 0;
        for(int c = 0; c <= Cols; c++){
            for(int i = 0; i < Terms; i++){
                if(smArray[i].col == c){
                    b.smArray[currentB].row = c;
                    b.smArray[currentB].col = smArray[i].row;
                    b.smArray[currentB++].value = smArray[i].value;
                }
            }
        }
    }
    return b;
}

void SparseMatrix::NewTerm(const int row, const int col, const int value){
    if (Terms==capacity) {                                   //termArray의 크기를 두 배로 확장
        capacity *= 2;
        MatrixTerm *temp = new MatrixTerm[capacity];         // 새로운 배열
        copy(smArray, smArray + Terms, temp);
        //delete[] smArray;                                  // 그전 메모리를 반환
        smArray = temp;
    }
    smArray[Terms].row = row;
    smArray[Terms].col = col;
    smArray[Terms++].value = value;
}

ostream& operator <<(ostream& os, SparseMatrix& SM){         // << 연산자 오버로딩
    for(int i = 0; i < SM.Terms; i++){
        os << SM.smArray[i].Getrow() << " ";
        os << SM.smArray[i].Getcol() <<" ";
        os << SM.smArray[i].Getvalue() << endl;
    }
    return os;
}
