#include <iostream>
#include "Polynomial.h"                     //헤더파일
#include <cmath>                            //제곱 연산을 위해 사용

using namespace std;

Term::Term() {                              //Term 생성자(인자 x)
    coef = 0; exp = 0;
}

Term::Term(float c, int e){                 //Term 생성자
    coef = c;
    exp = e;
    }

Term::~Term(){}                             //Term 파괴자

Polynomial::Polynomial(){                   //Polynomial 생성자(인자 x)
    termArray = new Term[1];
    capacity = 1;
    terms = 0;
}

Polynomial::Polynomial( int c, int t){      //Polynomial 생성자
    termArray = new Term[c];
    capacity = c;
    terms = t;
}

Polynomial::~Polynomial(){}                 //Polynomial 파괴자

int Term::Getcoef(){
    return coef;
}

int Term::Getexp(){
    return exp;
}

void Polynomial::NewTerm(const float theCoeff,const int theExp){
    if (terms==capacity) {                                          //termArray의 크기를 두 배로 확장
        capacity *= 2;
        Term *temp = new Term[capacity];                            // 새로운 배열
        copy(termArray, termArray + terms, temp);
        delete[] termArray;                                         // 그전 메모리를 반환
        termArray = temp;
    }
    termArray[terms].coef = theCoeff;
    termArray[terms++].exp = theExp;
}

Polynomial Polynomial::Mult(Polynomial& Poly){       // 다항식 곱셈
    Polynomial C;
    Polynomial T;
    int cf, ep;
    
    for(int i = 0; i < terms; i++){                             //다항식 A와 B를 곱한 것들을
        for(int j = 0; j < Poly.terms; j++){                    //T(temp)에 저장
            cf = termArray[i].coef * Poly.termArray[j].coef;
            ep = termArray[i].exp + Poly.termArray[j].exp;
            T.NewTerm(cf, ep);
        }
    }
    
    for(int i = 0; i < T.terms; i++){                           //지수가 큰 순서대로 정렬
        for(int j = i; j < T.terms; j++){
            if(T.termArray[i].exp < T.termArray[j].exp){
                swap(T.termArray[i].coef, T.termArray[j].coef);
                swap(T.termArray[i].exp, T. termArray[j].exp);
            }
        }
    }

    for(int i = 0; i < T.terms; i++){                           //지수가 같으면 계수를 더하고
        for(int j = 0; j < T.terms; j++){                       //비교한 뒤 인덱스의 계수와 지수를
            if(i != j){                                         //각각 0으로 초기화
                if(T.termArray[i].exp == T.termArray[j].exp){
                    T.termArray[i].coef += T.termArray[j].coef;
                    T.termArray[j].coef = 0;
                    T.termArray[j].exp = 0;
                }
            }
        }
    }
    
    for(int i = 0; i < T.terms; i++){                           //지수가 0이 아닌 인덱스들로만
        if(T.termArray[i].exp != 0){                            //사용하여 C 생성
            C.NewTerm(T.termArray[i].coef, T.termArray[i].exp);
        }
    }
    return C;                                                   //C 반환
}

int Polynomial::Eval(int x) {
    int res = 0;
    for(int i = 0; i < terms; i++){
        res += termArray[i].coef * pow(x,termArray[i].exp);
    }
    return res;
}

Polynomial Polynomial::operator *(Polynomial& Poly) {
    return Mult(Poly);
}

ostream& operator <<(ostream& os, Polynomial& Poly) {
    for(int i = 0; i < Poly.terms; i++){
        if(Poly.termArray[i].Getcoef() == 1 && Poly.termArray[i].Getexp()  == 1){
            os << "x";
        }
        else if (Poly.termArray[i].Getcoef()  == 1 && Poly.termArray[i].Getexp() != 1){
            os << "x^" << Poly.termArray[i].Getexp();
        }
        else if (Poly.termArray[i].Getcoef()  != 1 && Poly.termArray[i].Getexp() == 1){
            os << Poly.termArray[i].Getcoef()  << "x";
        }
        else {
            os << Poly.termArray[i].Getcoef()  << "x^" << Poly.termArray[i].Getexp();
        }
        if(i + 1 != Poly.terms){
            os << " + ";
        }
    }
    os << endl;
    return os;
}
