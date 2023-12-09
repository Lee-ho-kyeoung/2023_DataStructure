#include <iostream> 
using namespace std;

void add(int arr1[][10], int arr2[][10],int r1, int c1);    //함수 선언
void sub(int arr3[][10], int arr4[][10],int r2, int c2);

int main(void){
    int r1, r2, c1, c2; // A 행 r1, 열 c1 / B 행 r2, 열 c2
    int A[10][10], B[10][10]; // 행렬 A, B 선언

    cin >> r1 >> c1; // A의 행, 열 입력

    for(int i = 0; i < r1; i++){        // 행렬 A 입력
        for(int j = 0; j < c1; j++){
            cin >> A[i][j];
        }
    }

    cin >> r2 >> c2; // B의 행, 열 입력
    
    for(int i = 0; i < r2; i++){         // 행렬 B 입력
        for(int j = 0; j < c2; j++){
            cin >> B[i][j];
        }
    }

    if(r1 == r2 and c1 == c2){      //두 행렬의 크기가 같을 때
        add(A, B, r1, c1);          //두 행렬의 합 출력 함수
        sub(A, B, r2, c2);          //두 행렬의 차 출력 함수
    }
    else {      // 행렬 크기가 다를 때
        cout << "계산 오류" << endl;
    }
    return -1;   
}

void add(int arr1[][10], int arr2[][10],int r1, int c1){    //행렬의 합 출력 함수
    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            cout << arr1[i][j] + arr2[i][j] << " ";
        }
        cout << endl;
    }
}

void sub(int arr3[][10], int arr4[][10],int r2, int c2){    //행렬의 차 출력 함수
    for(int i = 0; i < r2; i++){
        for(int j = 0; j < c2; j++){
            cout << arr3[i][j] - arr4[i][j] << " ";
        }
        cout << endl;
    }
}