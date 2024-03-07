
#include <iostream>
#include <algorithm>
using namespace std;


int arr[8];

int n, m ;


void backTracking(int cnt, int prev) {
    
    if(cnt == m) {
        for(int i = 0 ; i < m ; i++) cout << arr[i] << ' ';
        cout << '\n' ;
        return ;
    }
    for(int i = prev ; i <= n ; i++) {
        arr[cnt] = i ;
        backTracking(cnt+1, i);
    }
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    
    cin >> n >> m; 
    backTracking(0,1);

    
}


/*
[해결전략 참고]
https://jouureee.tistory.com/127 
[시작]

[배울 점]

[문제 이해]
- 1부터 N까지 자연수 M개를 고른 수열
- 같은 수 여러번 가능
- 고른 수열은 비내리참순 -> A1 <= A2 <= ... <Ak-1 <= Ak  길이 K
- 요약하면 중복 순열 + 비내림차순 -> 중복 조합.

[입력]
- N과 M

[제약]
- 1<= M <= N <= 8

[출력]
- 만족하는 수열들 출력하기 
- 사전 순으로 증가하는 수열 출력하기

[풀이전략]
- N과 M (1)에서 사용된 거를 따로 저장하지 않고 백트래킹
*/
