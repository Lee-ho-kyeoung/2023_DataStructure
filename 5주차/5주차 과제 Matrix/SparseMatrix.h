#ifndef SparseMatrix_h
#define SparseMatrix_h

using namespace std;

class SparseMatrix;                         //전방 선언

class MatrixTerm {
    public :
        MatrixTerm();                       //생성자(인자 x)
        MatrixTerm(int, int, int);          //생성자
        ~MatrixTerm();                      //파괴자
    
        int Getrow();                       //row 값 반환
        int Getcol();                       //col 값 반환
        int Getvalue();                     //value 값 반환
    
        friend SparseMatrix;
    private :
        int row;                            //행
        int col;                            //열
        int value;                          //값
};

class SparseMatrix {
    public :
        SparseMatrix();                     //생성자(인자 x)
        SparseMatrix(int, int, int);        //생성자
        ~SparseMatrix();                    //파괴자
        
        void NewTerm(int row, int col, int value);                  //배열 생성
        SparseMatrix Transpose();                                   //행렬 전치 함수
    
        friend ostream& operator <<(ostream& os, SparseMatrix& SM); //연산자 오버로딩
    
    private :
        int Cols;                           //열의 수
        int Terms;                          //0이 아닌 항의 총 수 , 배열의 크기
        int capacity;
    
        MatrixTerm *smArray;                //SparseMatrix 객체 내의 배열
};

#endif /* SparesMatrix_h */
