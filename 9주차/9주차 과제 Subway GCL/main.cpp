#include <iostream>
#include "Subway.h"
#include <string>

using namespace std;

int Error(bool spacebar ,double& num);

int main(){
    //--------------------------------------기본 경의 중앙선 연결리스트로 구현------------------------------------------------
    string GCL_Draft_Name[56] ={ "도라산", "임진강", "운천", "문산", "파주", "월롱", "금촌", "금릉", "운정", "야당", "탄현", "일산", "풍산", "백마", "곡산", "대곡", "능곡", "행신", "강매", "화전", "수색", "디지털미디어시티", "가좌", "홍대입구", "서강대", "공덕", "효창공원앞", "용산", "이촌", "서빙고", "한남", "옥수", "응봉", "왕십리", "청량리", "회기", "중랑", "상봉", "망우", "양원", "구리", "도농", "양정", "덕소", "도심", "팔당", "운길산", "양수", "신원", "국수", "아신", "오빈", "양평", "원덕", "용문", "지평"};
    
    RouteMap GCL;                               //경의중앙선 노선도 객체
    for(int i = 0; i < 56; i++){
        GCL.Insert(GCL_Draft_Name[i]);   //기본적으로 주어진 노선도 생성
    }
    //---------------------------------------------------------------------------------------------------------------
    while(1){
        bool spacebar = true;
        double N = 0;                           //반복 횟수
        string command;                         //명령어를 담을 문자열 | 명령어 : CLOSE, RENMAE, MAKE
        
        cin >> N;                               //반복 횟수 입력
        if(!cin){                               //정수 입력시 에러문 출력
            cout << "문자는 입력 불가능 합니다. 0 ~ 56 사이의 정수만 입력해주세요." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }
        else if(N - int(N) != 0){               //실수 입력시 에러문 출력
            cout << "실수는 입력 불가능 합니다. 0 ~ 56 사이의 정수만 입력해주세요." << endl;
            continue;
        }
        else if(N < 0 || 56 < N){               //0<=N<=56 조건에 관한 에러문 출력
            cout << "범위가 초과되었습니다. 0 ~ 56 사이의 정수만 입력해주세요." << endl;
            continue;
        }
        
        while(N != 0){                          //입력된 반복 횟수만큼 반복
            string s1, s2;                      //명령어 인자
            cin >> command;                     //명령어 입력
            
            if(command == "CLOSE"){             //명령어가 CLOSE이면
                if(Error(!spacebar, N) == 1){  //인자가 0개일 때
                    cout << "폐쇄할 역을 입력해야 합니다." << endl;
                    continue;
                }
                cin >> s1;                      //인자 입력
                if(Error(spacebar, N) == 1){   //인자가 2개 이상일 때
                    cout << "한 개의 역만 폐쇄할 수 있습니다." << endl;
                    continue;
                }
                GCL.Delete(s1);                 //역 제거
                N--;                            //반복 횟수 카운트
            }
            else if (command == "RENAME"){      //명령어가 RENAME이면
                if(Error(!spacebar, N) == 1){  //인자가 0개일 때
                    cout << "변경할 역을 입력해야 합니다." << endl;
                    continue;
                }
                cin >> s1;
                if(Error(!spacebar, N) == 1){  //인자가 1개일 때
                    cout << "변경할 역 이름을 입력해야 합니다." << endl;
                    continue;
                }
                cin >> s2;                //인자 입력
                if(Error(spacebar, N) == 1){   //인자가 3개 이상일 때
                    cout << "2개의 역까지만 입력 가능합니다." << endl;
                    continue;
                }
                GCL.RENAME(s1, s2);             //역 이름 수정
                N--;                            //반복 횟수 카운트
            }
            else if (command == "MAKE"){        //명령어가 MAKE이면
                char check;                     //인자의 개수가 2개인지 3개인지 판별할 때 사용
                if(Error(!spacebar, N) == 1){  //인자가 0개일 때
                    cout << "최소 1개의 역을 입력해야 합니다." << endl;
                    continue;
                }
                cin >> s1;
                if(Error(!spacebar, N) == 1){  //인자가 1개일 때
                    cout << "생성할 역의 이름을 입력해야 합니다." << endl;
                    continue;
                }
                cin >> s2;                      //인자 입력
                check = cin.get();
                if(check != '\n') {             //3번째 인자를 입력하면
                    string s3;
                    cin >> s3;
                    if(Error(spacebar, N) == 1){   //인자가 4개 이상일 때
                        cout << "3개의 역까지만 입력 가능합니다." << endl;
                        continue;
                    }
                    GCL.Make(s1, s2, s3);       //역 생성
                }
                else{
                    GCL.Make(s1, s2);           //역 생성
                }
                N--;                            //반복 횟수 카운트
            }
            else{                               //없는 명령어이면
                cout << "명령어가 잘못 되었습니다. CLOSE, RENAME, MAKE 중 입력해주세요." << endl;
            }
        }
        GCL.PrintStation();                     //노선도 출력
        return 0;
    }
}

int Error(bool spacebar, double& num){          //오류 판별 함수
    char check;                                 //스페이스바인지 엔터키인지 판별하는 변수
    check = cin.get();                          //변수에 입력
    if(check == '\n' && spacebar == 0){         //엔터키이면
        cin.clear();
        num--;
        return 1;
    }
    else if(check != '\n' && spacebar == 1){    //스페이스바이면
        cin.clear();
        cin.ignore(100, '\n');
        num--;
        return 1;
    }
    else{
        return 0;
    }
}
