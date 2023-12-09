#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"

using namespace std;

int main(){
    int N = 0, num = 0;
    int x = 0;
    
    cin >> N;                       //반복 횟수 = case 횟수
    
    Chain<int>* arr = new Chain<int>[N]; //객체 배열 동적할당
    
    for(int i = 0; i < N; i++){     //반복 횟수만큼 반복
        cin >> x;                   //입력할 숫자의 개수
        Chain<int> chain;           //Chain형 객체
        for(int j = 0; j < x; j++){ //숫자 개수 만큼 반복
            cin >> num;             //숫자 입력
            chain.insertNode(num);  //입력된 숫자를 리스트에 연결
        }
        arr[i] = chain;             //객체 배열 i번째 항에 객체 삽입
    }
    for(int i = 0; i < N; i++){     //반복 횟수만큼 반복
        cout << "case " << i + 1 << endl;
        arr[i].PrintList();         //i번째 항의 객체 출력
    }
}
