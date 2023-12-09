#include <iostream> 
#include "rectangle.h"

using namespace std;

/* 
구현된 프로그램을 참조하여 다음의 조건을 만족하는 프로그램을 구현하시오.
1. 사각형 객체를 저장할 Rectangle 객체 배열 5칸을 생성
2. x, y 좌표와 가로, 세로 길이를 입력 받아서 입력받은 값으로 사각형 객체 생성
3. 사각형 객체를 생성할 때 생성하는 순서에 따라 사각형에 번호를 입력(hint : 파라미터를 추가해야 함)
4. 생성한 사각형 객체 5개 중에서 가장 넓이가 큰 사각형을 찾아서 출력 -> "0번째 사각형이 가장 크고, 그 넓이는 0이다."
*/

/* 추가로 생각해볼 수 있는 문제
1. 서로 겹치지 않는 사각형을 생성하는 방법
2. 두 개의 사각형이 겹치는 부분의 넓이를 구하는 방법
2. 객체를 포인터로 생성하고, 파괴하는 방법
*/

main() {    
    Rectangle * s[5];
    int check = 0; // 큰 값 인덱스 저장
    int xLow = 0, yLow = 0, width = 0, height = 0, rNum = 0;

    for(int i = 0; i < 5; i++) {
        rNum = i + 1;
        cout << rNum << "번 사각형" << endl;
        cout << "좌표 x : ";
        cin >> xLow;
        cout << "좌표 y : ";
        cin >> yLow;
        cout << "가로 : ";
        cin >> width;
        cout << "세로 : ";
        cin >> height;
        s[i] = new Rectangle(xLow, yLow, width, height ,rNum);
    }

    for(int i = 0; i < 4; i++){
        if(s[i] < s[i + 1]){
            check = i + 1;
        }
        else {
            check = i;
        }
    }
    for(int i = 0; i < 5; i++){
        cout << "--- Rectangle Number " << i + 1 << "---" << endl;
        cout << * s[i];
        cout << endl;
    }

	cout << s[check]->GetNum() << "번 사각형이 제일 크고, 그 넓이는 " << s[check]->GetArea() << "이다" << endl;
}