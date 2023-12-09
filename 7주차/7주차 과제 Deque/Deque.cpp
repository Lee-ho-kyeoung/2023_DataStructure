#include <iostream>
#include "Deque.h"
#include <string>


using namespace std;

Deque::Deque(int dequeCapacity ):capacity(dequeCapacity){
    if(capacity<1)throw"deque capacity must be >0";
    deque = new Card[capacity];
    front = rear = 0;
}

Deque::~Deque(){}

inline bool Deque::IsEmpty() const{
    return front==rear;
}

void Deque::PushSort(Card card){
    int check = 0;

    Card T;                                                     //매개변수 T
    T = card;                                                   //T에 card 값 저장
    
    if(IsEmpty() == 1){                                         //데큐가 비어있을 때 데큐 첫 항에 입력 후 첫 항 출력
        rear = (rear + 1) % capacity;
        deque[rear] = T;
        cout << deque[rear].name << endl;
    }
    
    else{                                                       //데큐가 비어있지 않을 때
        Print();
        if(rear < front){
            for(int i = (front + 1) % capacity; i != rear + 1 ; i = (i+1) % capacity){
                if(T.point < deque[i].point){                       //입력받은 카드 값보다 크면
                    int x = i;                                      //찾은 자리
                    int distF;                                      //앞에서 부터 거리
                    int distB;                                      //뒤에서 부터 거리
                    if(x <= rear){
                        distF = x + (capacity - (front + 1));
                        distB = rear - x;
                    }
                    else {
                        distF = x - (front + 1);
                        distB = (capacity - x) + rear;
                    }
                    if(distF <= distB){                             //앞에서 부터 거리가 더 짧거나 같으면
                        if(distF == 0){                             //앞에서 부터 거리가 0이면 가장 작은 값이 첫 항임
                            deque[front] = T;                       //front 자리에 입력받은 카드 값 저장
                            front = (front + capacity - 1) % capacity;;  //front 한 칸 뒤로 움직임
                            Print();
                        }

                        else{                                       //거리가 0이 아니면 중간에 끼워야함
                            for(int i = 0; i < distF; i++){
                                FrontPop_BackPush();                //앞에서 빼고 뒤로 넣기
                                Print();
                            }
                            deque[(x + capacity - 1) % capacity] = T;                           //찾은 자리에 카드값 넣기
                            front = (front + capacity - 1) % capacity;; //front 한 칸 뒤로 움직임
                            Print();
                            for(int i = 0; i < distF; i++){
                                BackPop_FrontPush();                //뒤로 뺀 값을 다시 빼서 앞으로 넣어줌
                                Print();
                            }
                        }
                    }
                    else{                                           //뒤에서 부터 거리가 더 짧다면
                        for(int i = 0; i < distB + 1; i++){
                            BackPop_FrontPush();                    //뒤에서 빼고 앞으로 넣기
                            Print();
                        }
                        deque[x] = T;                               //찾은 자리에 카드값 넣기
                        rear++;                                     //rear 한 칸 앞으로 움직임
                        Print();
                        for(int i = 0; i < distB + 1; i++){
                            FrontPop_BackPush();                    //앞으로 뺀 값을 다시 빼서 뒤로 넣어줌
                            Print();
                        }
                    }
                    check++;                                        //입력받은 카드 값보다 큰 것이 있다면 +1
                    return;
                }
            }
        }
        else{
            //입력받은 카드 값보다 큰 값 중 가장 작은 값 을 찾음
            for(int i = (front + capacity + 1) % capacity; i < (rear + 1) % capacity; i++){
                if(T.point < deque[i].point){                       //입력받은 카드 값보다 크면
                    int x = i;                                      //찾은 자리
                    int distF = x - (front + 1) % capacity;         //앞에서 부터 거리
                    int distB = rear - x;                           //뒤에서 부터 거리
                    if(distF <= distB){                             //앞에서 부터 거리가 더 짧거나 같으면
                        if(distF == 0){                             //앞에서 부터 거리가 0이면 가장 작은 값이 첫 항임
                            deque[front] = T;                       //front 자리에 입력받은 카드 값 저장
                            front = (front + capacity - 1) % capacity;;  //front 한 칸 뒤로 움직임
                            Print();
                        }

                        else{                                       //거리가 0이 아니면 중간에 끼워야함
                            for(int i = 0; i < distF; i++){
                                FrontPop_BackPush();                //앞에서 빼고 뒤로 넣기
                                Print();
                            }
                            deque[x - 1] = T;                           //찾은 자리에 카드값 넣기
                            front = (front + capacity - 1) % capacity;; //front 한 칸 뒤로 움직임
                            Print();
                            for(int i = 0; i < distF; i++){
                                BackPop_FrontPush();                //뒤로 뺀 값을 다시 빼서 앞으로 넣어줌
                                Print();
                            }
                        }
                    }
                    else{                                           //뒤에서 부터 거리가 더 짧다면
                        for(int i = 0; i < distB + 1; i++){
                            BackPop_FrontPush();                    //뒤에서 빼고 앞으로 넣기
                            Print();
                        }
                        deque[x] = T;                               //찾은 자리에 카드값 넣기
                        rear++;                                     //rear 한 칸 앞으로 움직임
                        Print();
                        for(int i = 0; i < distB + 1; i++){
                            FrontPop_BackPush();                    //앞으로 뺀 값을 다시 빼서 뒤로 넣어줌
                            Print();
                        }
                    }
                    check++;                                        //입력받은 카드 값보다 큰 것이 있다면 +1
                    return;
                }
            }
        }

        if(check == 0){                                         //입력받은 카드 값보다 큰 것이 없다면
            rear = (rear + 1) % capacity;                       //rear 한 칸 앞으로 움직임
            deque[rear] = T;                                    //rear 자리에 입력받은 카드 값 넣음
            Print();
        }
    }
}

void Deque::FrontPop_BackPush(){
    rear = (rear + 1) % capacity;                               //rear 앞으로 한 칸 움직임
    deque[rear] = deque[(front + 1) % capacity];                //맨 뒷 항에 맨 앞 값 넣기
    front = (front + 1) % capacity;                             //front 앞으로 한 칸 움직임
}

void Deque::BackPop_FrontPush(){
    deque[front] = deque[rear];                                 //맨 앞 항에 맨 뒷 값 넣기
    front = (front + capacity - 1) % capacity;                  //front 뒤로 한 칸 움직임
    rear = (rear + capacity - 1) % capacity;                    //rear 뒤로 한 칸 움직임
}

void Deque::Print(){
    if(IsEmpty() == 1){                                         //데크가 비어있으면
        cout << "Deque is empty" << endl;
    }
    else{                                                       //데크가 비어있지 않으면
        if(front > rear && front != capacity - 1){              //front가 rear 보다 크고 마지막 항 인덱스값과 같지 않다면
            for(int i = (front + 1) % capacity; i < capacity; i++){
                cout << deque[i].name << " ";
            }
            for(int i = 0; i < rear + 1; i++){
                cout << deque[i].name << " ";
            }
        }
        else {                                                  //rear가 front 보다 크면
            for(int i = (front + 1) % capacity ; i < rear + 1; i++){
                cout << deque[i].name << " ";
            }
        }
        cout << endl;
    }
}

Card::Card(){}

Card::Card(string str){
    char c = str[0];
    
    switch (c) {
        case 'S':
            point = 100;
            break;
        case 'D':
            point = 200;
            break;
        case 'H':
            point = 300;
            break;
        case 'C':
            point = 400;
    }
    point += stoi(str.substr(1));                               //Card 의 종류와 숫자를 한 값으로 표현 ex) D11 = 211
    name = str;                                                 //입력받은 카드의 이름을 저장
}

Card::~Card(){}
