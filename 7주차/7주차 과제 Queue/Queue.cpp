#include <iostream>
#include "Queue.h"

using namespace std;

template <class T>
Queue<T>::Queue(int queueCapacity ):capacity(queueCapacity)
{
    if(capacity<1)throw"Queue capacity must be >0";
    queue = new T[capacity];
    front = rear = 0;
}

template <class T>
Queue<T>::~Queue() { }

template <class T>
inline bool  Queue<T>::IsEmpty() const
{
    return front == rear;
}

template <class T>
void Queue<T>::Push(const T& x)
{
    queue[rear++] = x;
}

template <class T>
void Queue<T>::Pop()
{
    if(IsEmpty() == 1){
        cout << "Queue is empty" << endl;
    }
    else{
        cout << queue[front] << " ";
        queue[front++] = 0;
    }
    if(IsEmpty() == 1){
        front = 0;
        rear = 0;
    }
}

template <class T>
void Queue<T>::Password(){
    T* newQueue = new T[capacity];
    int minus = 1;                      //암호를 만들 때 빼는 값
    int back = 0;                       //뺀 결괏값을 저장받는 변수

    while(queue[rear - 1] != 0){
        if(minus > 5){
            minus = 1;
        }
        
        back = queue[front] - minus;
        if(back < 0){
            back = 0;
        }
        copy(queue + 1, queue + capacity, newQueue);
        queue = newQueue;
        queue[rear - 1] = back;
        minus++;
    }
}
