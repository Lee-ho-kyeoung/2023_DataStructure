#ifndef Polynomial_h
#define Polynomial_h

using namespace std;

class Polynomial; // 다항식 객체

class Term {      // 배열 객체
    public:
        Term();                 //인자가 없는 생성자
        Term(float c, int e);   //인자가 있는 생성자
        ~Term();                //파괴자
    
        int Getcoef();  // << 연산자 오버로딩시 사용
        int Getexp();   // << 연산자 오버로딩시 사용
    
        friend Polynomial;
    
    private:
        float coef; // 계수
        int exp;    // 지수
};

class Polynomial {
    public:
        Polynomial();           //인자가 없는 생성자
        Polynomial(int, int);   //인자가 있는 생성자
        ~Polynomial();          //파괴자
    
        void NewTerm(float coef, int exp);                          // 배열 입력
        Polynomial Mult(Polynomial& Poly);                          // *this 와 Poly의 곱을 반환
        int Eval(int x);                                            // *this 에 x값을 대입한 결괏값 반환
        
        Polynomial operator *(Polynomial& Poly);                    //곱셈 연산자 오버로딩
        friend ostream& operator <<(ostream& os, Polynomial& Poly); //출력 연산자 오버로딩
    
    private:
        Term *termArray;    // 0이 아닌 항의 배열
        int capacity;       // termArray 크기
        int terms;          // 0이 아닌 항의 수
};

#endif /* Polynomial_hpp */
