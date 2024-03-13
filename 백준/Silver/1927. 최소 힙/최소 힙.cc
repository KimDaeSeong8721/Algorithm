

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


priority_queue<int, vector<int>, greater<int>> pq ;

int n , x ; 

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;

    for(int i = 0 ; i < n ; i++){
        cin >> x ; 
        if(x == 0) {
            if(pq.empty()) cout << 0 <<'\n' ;
            else {cout << pq.top() <<'\n'; pq.pop() ; }
        } else {
            pq.push(x);
        }
    }
}

/*
[해결전략 참고]

[시작]
- 3.14 목 오전 12:34 ~ 

[배울 점]

[문제 이해]
- 최소 힙 이용
- 배열에 자연수 x 넣기
- 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
- 처음은 빈 배열에서 시작

[입력]
- 1줄 : N
- 다음 N개 줄 : 연산 정보 주어짐.

[제약]
x가 자연수 -> 배열에 x 추가
x가 0 -> 배열에서 가장 작은 값 출력하고 그 값 배열에서 제거
0<=x < 2^31 
[출력]
- 입력에서 0이 주어진 횟수만큼 답출력
- 빈 배열인데 0이 주어지면 0 출력

[풀이전략]
- STL Priority 이용.

*/
