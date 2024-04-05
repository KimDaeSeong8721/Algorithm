
#include <iostream>
#include <algorithm>
using namespace std;

// 합이 0

int n ; // 학생의 수
int arr[10'001]; // 학생 코딩실력 저장 배열
long long num  ;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>> n ;

    for(int i = 0 ; i < n ; i++) cin>> arr[i];

    sort(arr,arr+n);
    
    for(int i = 0 ; i < n-1; i++)
      for(int j = i+1 ; j < n ; j++) {
        auto lower = 
        lower_bound(arr+j+1,arr+n,-arr[i]-arr[j]);

        auto upper =
        upper_bound(arr+j+1,arr+n,-arr[i]-arr[j]);

        num += (upper - lower) ; 
      }

    cout << num ; 
}

/*
[해결전략 참고]
바킹독 
[시작]
- 4.4.목. 5:29 -> 6:07분인데 감이 안잡힌다.-> 6:30 -> 감 안잡힘.
-> 아니 해설지 너무 풀이 너무 쉬워서 어이가 없음.

- 4.5 금 6:30 -> 6:44
[배울 점]
- 이분 탐색문제를 풀때 for문을 사용할 경우 이전에 방문한 곳을 다시 방문할 필요가 있는지 생각해보기.

[문제 이해]
3인팀만 가능
- 세 팀원의 코딩실력의 합이 0이 되는 팀이 목적
- 최대 만들 수 있는 수

[입력]
- N
- N명의 코딩실력 Ai

[제약]
- 1 ≤ N ≤ 10000
-10000 ≤ Ai ≤ 10000
중복 허용.
[출력]
- 그녀가 고를 수 있는 팀의 최대 수

[풀이전략]
1. 이중 for문 사용
2. lower_bound와 upper_bound를 사용하여 중복개수도 센다.


*/
