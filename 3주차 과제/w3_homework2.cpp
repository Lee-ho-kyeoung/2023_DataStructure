#include <iostream> 
using namespace std;

void sort(int *a, const int n); // 선택 정렬 함수
int BinarySearch(int *a, const int x, const int n); // 이원 탐색 함수

int main(void) {
    int A[10000];     // 수열 A 
    int N, X, res;    // A의 크기 N, X, 이원 탐색 함수 반환값 변수 res 

    cin >> N >> X;          // N, X 입력

    for(int i = 0; i < N; i++){         //수열 A값 입력
        cin >> A[i];
    }

    sort(A, N); // A 수열 선택정렬

    res = BinarySearch(A, X, N); // 이원 탐색 함수 반환값 저장

    if(A[N-1] <= X){                 // X값이 A수열 내 값보다 클 때
        cout << "Error" << endl;
    }
    else {
        for(int i = res + 1; i < N; i++){
            if(A[i] > X){
                cout << A[i] << " ";
            }
        }
        cout << endl;
    }
    return -1;
}

void sort(int *a, const int n) // 선택 정렬 함수
{
    for(int i = 0; i < n; i++){
        int j = i;
        for(int k = i + 1; k < n; k++){
            if(a[k] < a[j]) {
                j = k;
            }
        }
        swap(a[i], a[j]);
    }
}

int BinarySearch(int *a, const int x, const int n) // 이원 탐색 함수
{
	int left = 0; int right = n-1, check = -1;   //check 변수는 middle값 저장
    while (left <= right){ 
        int middle = (left + right) / 2;
        
        if (x < a[middle]){
            right = middle - 1;
        }
        else if (x > a[middle]){ 
            left = middle + 1;
            check = middle;
        }
        else {
            return middle;
        }
    }
    return check; // 발견되지 않음
}