#include "iostream"
#include "LinkedList.h"

using namespace std;

template <class T>
void Chain<T>::insertNode(T data){      //노드를 리스트에 추가하는 함수(first에 연결)
    if(first == 0){                     //first에 연결된 노드가 없으면
        first = new ChainNode<T>(data); //first에 노드 연결
    }
    else{                               //first에 연결된 노드가 있으면
        ChainNode<T>* current = new ChainNode<T>(data); //매개 포인터 변수
        current->link = first;          //새로운 노드에 first에 연결된 노드 연결
        first = current;                //first에 새로운 노드 연결
    }
}

template <class T>
void Chain<T>::PrintList(){             //리스트를 출력하는 함수
    ChainNode<T>* print = first;        //매개 포인터 변수
    while(print != 0){                  //첫 노드부터 마지막 노드까지
        cout << print->data << " ";
        print = print->link;            //다음 노드로 이동
    }
    cout << endl;
}
