#include <iostream>
#include "Polynomial.h"                     //헤더파일

using namespace std;

int main(void){
    char enterA = 'a', enterB = 'b';        //엔터 입력 판별 변수
    float coef = 1;                         
    int exp = 1;
    int x;
    
    Polynomial A;                           //A 배열 선언
    Polynomial B;                           //B 배열 선언
    Polynomial C;                           //C 배열 선언
    
    while(enterA != '\n'){                  //엔터가 입력되면 종료
        cin >> coef;
        cin >> exp;
        A.NewTerm(coef, exp);               //입력받은 계수, 지수를 A.termArray의 인덱스에 입력
        enterA = cin.get();                 //스페이스바 or 엔터키 판별 변수
    }
    
    while(enterB != '\n'){                  //엔터가 입력되면 종료
        cin >> coef;
        cin >> exp;
        B.NewTerm(coef, exp);               //입력받은 계수, 지수를 B.termArray의 인덱스에 입력
        enterB = cin.get();                 //스페이스바 or 엔터키 판별 변수
    }
    
    cout << "x = ";
    cin >> x;
    
    cout << "A : " << A;                              //출력 연산자 오버로딩하여 사용
    
    cout << "B : " << B;
    
    C = (A*B);                              //곱 연산자 오버로딩하여 사용
    
    cout << "C : " << C;
    
    cout << (A*B).Eval(x) << endl;          //다항식에 x값을 대입한 결괏값 출력
    
    if((A*B).Eval(x) < 50){                 //결괏값이 50미만이면 A 아니면 B 출력
        cout << "A" << endl;
    }
    else {
        cout << "B" << endl;
    }
    
    return 0;
}
