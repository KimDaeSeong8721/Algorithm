#include <iostream>
#include <algorithm>
using namespace std;


int n , m ;
int arr[10001];

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
  
    cin >> n >> m ;
    for(int i = 0 ; i< n ; i++) cin >> arr[i];
  int st = 0 ;
  int en = 1 ;
  int cnt = 0 ;
  int sum = arr[0] ; 
    while(1){
        if(sum == m) cnt++;
        if(sum <= m) sum += arr[en++];
        else if(sum > m) sum -= arr[st++];
        if(en == n+1) break; // 21번째줄에서 n-1번쨰(마지막번째)더하고 en은 n이 되어버림. 대신 arr[n]은 0으로 해두어야함.
    }
    cout << cnt ;
}

/*
[해결전략 참고]

[시작]
3월 22일 12:36 am
[배울 점]
- 끝부분 섬세히 구현할 것.
[문제 이해]
- n개의 수로 된 수열
- i번째부터 j번째수까지의 합이 M이 되는 경우의 수 구하장




[입력]
- 수열 개수 N,  최종 합인 M 주어짐.

[제약]
1 ≤ N ≤ 10,000
1 ≤ M ≤ 300,000,000
각 수는 3만이하의 자연수

[출력]
경우의 수 
[풀이전략]
- 투 포인터

*/
