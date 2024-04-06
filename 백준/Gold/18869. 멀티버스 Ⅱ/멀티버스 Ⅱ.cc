#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 멀티버스 2

int m, n; // 우주의 개수, 행성 개수

int arr[102][10002];
vector<int> v[100]; // 각 우주의 행성을 담을 벡터
int cnt ; 


// 좌표 압축
void compress(int a[]) {
    vector<int> v(a, a+n);
    sort(v.begin(), v.end()); // 오름차순 정렬
    v.erase(unique(v.begin(), v.end()), v.end()); //unique는 연속적으로 존재하는 요소들을 삭제 해준다. but 배열의 사이즈는 그대로이기 때문에 뒷부분 제거 .
    for (int i = 0; i < n; i++)
        a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
}

// 비교
bool cmp(int a[], int b[]) {
    for(int i = 0; i < n ; i++)
        if(a[i] != b[i]) return false ;
    return true;
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> m >> n ;
    for(int i = 0 ; i < m ; i++) {
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j] ;
        }
        compress(arr[i]);
    }
    for (int i = 0; i < m - 1; i++)
        for (int j = i + 1; j < m; j++)
            cnt += cmp(arr[i],arr[j]);
    cout << cnt ; 

}

/*
[해결전략 참고]
바킹독 풀이 전략 참고.

[시작]
4.2 오후 4:35분 ~ 5시:48분 -> 못품 

[배울 점]
- 공간복잡도계산법 512메가바이트 -> 1.2억개 int
- 좌표압축 공부하기 
[문제 이해]
- M개의 우주, 각 우주에는 행성 N개
- 구성이 같은데 순서만 다른 우주의 쌍은 한번만 셈
- 행성의 크기가 주어진다.
- 우주 균등 조건
    모든 i,j에 대해 (i<=j)
    - Ai <Aj ->Bi < Bj
    -    =        =
    -     >       >

M이 100밖에 안되기 때문에 M^2 충분히 가능

[입력]

[제약]
- M<=100이하 , N<=10'000 , 1<=행성크기 <= 백만
- 구성이 같은데 순서만 다른 우주의 쌍은 한번만 셈

[출력]
- 균등한 우주쌍 개수 출력

[풀이전략]
균등조건을 조금만 더 깊게 생각해보면 정렬을 해도 비교결과는 same.


*/
