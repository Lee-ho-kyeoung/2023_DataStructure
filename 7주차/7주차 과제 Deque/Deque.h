#ifndef Deque_H
#define Deque_H

using namespace std;

class Deque{
private:
    class Card* deque;              //Card type 배열 deque
    int rear;
    int front;
    int capacity;

public:
    Deque(int dequeCapacity = 10);  //생성자
    ~Deque();                       //파괴자
    
    inline bool IsEmpty() const;    //비교 연산자
    void PushSort(Card);            //입력받고 정렬하는 함수
    void Print();                   //출력 함수
    
    void FrontPop_BackPush();       //맨 앞에서 빼서 맨 뒤로 넣는 함수
    void BackPop_FrontPush();       //맨 뒤에서 빼서 맨 앞으로 넣는 함수
};

class Card{
    private:
        int point;                  //카드에 부여된 값 저장 변수
        string name;                //입력받은 카드의 이름
    
    public:
        Card(string);               //생성자
        Card();                     //생성자(인자 x)
        ~Card();                    //파괴자
        
        friend Deque;               //friend 선언
};
#endif
