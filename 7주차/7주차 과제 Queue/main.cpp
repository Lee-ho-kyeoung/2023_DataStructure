#include <iostream>
#include "Queue.h"
#include "Queue.cpp"

using namespace std;

int main()
{
    Queue<int> q = Queue<int>(8);            //큐 크기 지정하여 선언
    
    int n = 0, count = 0;                    //큐에 들어갈 암호를 입력 받을 매개변수
    
    while(1){
        count++;
        for(int i = 0; i < 8; i++)           //큐에 암호 입력
        {
            cin >> n;
            q.Push(n);
        }
        
        q.Password();
        
        cout << "#" << count << " ";
        
        for(int i = 0; i < 8; i++)
        {
            q.Pop();
        }
        cout << endl;
    }
}
