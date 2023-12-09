#include <iostream>
#include "Subway.h"
#include <string>

using namespace std;

void RouteMap::Insert(string name){    //역을 노선도에 넣는 함수
    if(first == 0){                             //first에 연결된 노드가 없으면
        first = new Station(name);              //first에 새로운 노드 연결
        last = first;                           //새로운 노드를 가리키게 함
    }
    else{
        last->link = new Station(name);         //마지막 노드 뒤에 연결
        last = last->link;                      //새로운 노드를 가리키게 함
    }
}

void RouteMap::Delete(string s){                //역을 노선에서 지우는 함수
    Station* current = first;                   //현재 위치를 저장하는 매개 포인터 변수
    Station* before = first;                    //이전 위치를 저장하는 매개 포인터 변수
    if(first == 0){                             //first에 연결된 노드가 없으면
        cout << "노선이 없습니다.(CLOSE 오류)" << endl;
        return;
    }
    else{
        while(current != 0){                    //포인터 변수가 마지막 연결 노드가 될 때 까지
            if(current->name == s){             //삭제할 역 이름과 같은 역이면
                if(current == first){           //삭제할 역이 first와 연결되어 있음면
                    first = first->link;        //frist를 삭제할 역 다음 역에 연결
                    current->link = 0;          //삭제할 역의 경로 0으로 초기화
                    return;
                }
                else{
                    before->link = current->link; //이전 역을 삭제할역 다음 역에 연결
                    current->link = 0;          //삭제할 역의 경로 0으로 초기화
                    return;
                }
            }
            else{
                before = current;               //before를 다음 노드로 이동
                current = current->link;        //current를 다음 노드로 이동
            }
        }
        cout << "삭제할 역이 존재하지 않습니다.(CLOSE 오류)" << endl;  //역이 존재하지 않을 때
    }
}

void RouteMap::RENAME(string old_name, string new_name){      //역의 이름을 바꾸는 함수
    Station* current = first;                   //포인터 변수 current
    if(first == 0){                             //first에 연결된 노드가 없으면
        cout << "노선이 없습니다.(RENAME 오류)" << endl;
        return;
    }
    else{
        while(current != 0){                    //포인터 변수가 마지막 연결 노드가 될 때 까지
            if(current->name == new_name){      //바꿀 이름과 같은 아름의 역이 존재하면
                cout << new_name << "역은 이미 존재하는 역입니다.(RENAME 오류)" << endl;
                return;
            }
            else{
                current = current->link;        //다음 노드로 이동
            }
        }
        current = first;
        while(current != 0){                    //포인터 변수가 마지막 연결 노드가 될 때 까지
            if(current->name == old_name){      //바꾸기 전 이름과 같은 역이면
                current->name = new_name;       //새로운 이름으로 변경
                return;
            }
            else{
                current = current->link;        //다음 노드로 이동
            }
        }
    }
    cout << old_name << "역이 존재하지 않습니다.(RENAME 오류)" << endl;    //바꿀 역이 존재하지 않을 때
}

void RouteMap::Make(string front, string make_back){    //인자가 2개일 때 역을 생성하는 함수
    Station* current = first;
    Station* temp = 0;                          //매개 포인터 변수
    if(first == 0){                             //first에 연결된 노드가 없으면
        cout << "노선이 없습니다.(MAKE 오류)" << endl;
        return;
    }
    else{
        while(current != 0){                    //포인터 변수가 마지막 연결 노드가 될 때 까지
            if(current->name == make_back){     //새로 만들 역의 이름과 같은 역이면
                cout << make_back << "역은 이미 존재하는 역입니다.(MAKE 오류)" << endl;
                return;
            }
            else{
                current = current->link;        //다음 노드로 이동
            }
        }
        current = first;
        while(current != 0){                    //포인터 변수가 마지막 연결 노드가 될 때 까지
            if(current->name == front){         //만들 역의 앞 역의 이름과 같은 역이면
                temp = current->link;           //매개 변수에 현재 역 경로 저장
                current->link = new Station(make_back); //현재 역 뒤에 새로운 역을 생성
                current = current->link;        //다음 노드로 이동
                current->link = temp;           //새로운 매개변수에 저장된 경로 저장
                return;
            }
            else{
                current = current->link;        //다음 노드로 이동
            }
        }
    }
    cout << front << "역이 존재하지 않습니다.(MAKE 오류)" << endl;
}

void RouteMap::Make(string front, string back, string make_between){    //인자가 3개일 때 역을 생성하는 함수
    Station* FrontS = first;                    //앞 역의 위치를 받는 포인터 변수
    Station* BackS = first;                     //뒷 역의 위치를 받는 포인터 변수
    if(first == 0){                             //first에 연결된 노드가 없으면
        cout << "노선이 없습니다.(MAKE 오류)" << endl;
        return;
    }
    else{
        while(FrontS != 0){                     //포인터 변수가 마지막 연결 노드가 될 때 까지
            if(FrontS->name == make_between){   //새로 만들 역의 이름과 같은 역이면
                cout << make_between << "역은 이미 존재하는 역입니다.(MAKE 오류)" << endl;
                return;
            }
            else{
                FrontS = FrontS->link;          //다음 노드로 이동
            }
        }
        FrontS = first;
        while(1){                                               //앞 역의 위치를 찾아감
            if(FrontS->name == front || FrontS->name == back){
                if(FrontS->name == front){                      //앞에 위치한 역이 먼저 입력될 때
                    while(BackS->name != back){                 //뒷 역의 위치를 찾아감
                        BackS = BackS->link;
                        if(BackS == 0){
                            cout << back << "역이 존재하지 않습니다.(MAKE 오류)" << endl;
                            return;
                        }
                    }
                    FrontS->link = new Station(make_between);   //앞 역에 새로운 역을 연결
                    FrontS = FrontS->link;                      //새로운 역을 가리킴
                    FrontS->link = BackS;                       //새로운 역에 뒷 역을 연결
                    return;
                }
                else{                                           //뒤에 위치한 역이 먼저 입력될 때
                    while(BackS->name != front){                //뒷 역의 위치를 찾아감
                        BackS = BackS->link;
                        if(BackS == 0){                         //입력받은 역이 없을 때
                            cout << front << "역이 존재하지 않습니다.(MAKE 오류)" << endl;
                            return;;
                        }
                    }
                    FrontS->link = new Station(make_between);   //앞 역에 새로운 역을 연결
                    FrontS = FrontS->link;                      //새로운 역을 가리킴
                    FrontS->link = BackS;                       //새로운 역에 뒷 역을 연결
                    return;
                }
                //break;
            }
            else{
                FrontS = FrontS->link;
                if(FrontS == 0){
                    cout << front << "역과 " << back << "역이 존재하지 않습니다.(MAKE 오류)" << endl;
                    break;
                }
            }
        }
    }
}

void RouteMap::PrintStation(){                  //노선도를 출력하는 함수
    int count = 0;
    Station* print = first;                     //포인터 변수 print
    if(first == 0){                             //first에 연결된 노드가 없으면
        cout << "노선이 없습니다." << endl;
    }
    else{
        while(print->link != 0){                //포인터 변수가 마지막 연결 노드가 될 때 까지
            cout << print->name << " - ";
            print = print->link;                //다음노드로 이동
            count++;
        }
        cout << print->name << endl;            //마지막 역 출력
    }
}
