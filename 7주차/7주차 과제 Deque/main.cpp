#include <iostream>
#include "Deque.h"
#include <string>
#include <stdlib.h>
#include <time.h>

int main(){
    srand((int)time(NULL));    //seed값을 현재 시간으로 설정(매번 다른 난수)
    int n = 0;                 //임의의 변수 n
    
    string Cardname;           //card를 입력받을 string type 변수
    
    cin >> n;
    
    int RandK[n];
    int RandP[n];
    
    Deque deq(n + 2);

    for (int i = 0; i < n; ++i)
    {
        bool duplicated = true;
        while (duplicated) {
            duplicated = false;
            RandK[i] = rand() % 4 + 1;
            RandP[i] = rand() % 13 + 1;

            for (int j = 0; j < i; j++)
            {
                if (RandK[j] == RandK[i] && RandP[j] == RandP[i])   //중복 발견
                {
                    duplicated = true;                              // 다시 뽑기
                    break;
                }
            }
        }

        switch (RandK[i]) {
            case 1:
                Cardname = 'S';
                break;
            
            case 2:
                Cardname = 'D';
                break;

            case 3:
                Cardname = 'H';
                break;
            
            case 4:
                Cardname = 'C';
        }
        Cardname += to_string(RandP[i]);
        cout << "선택된 카드 " << i + 1 << " : " << Cardname << endl;
        Card card(Cardname);            //입력받은 card 생성
        deq.PushSort(card);             //card 값을 데큐에 넣고 정렬
    }
}
