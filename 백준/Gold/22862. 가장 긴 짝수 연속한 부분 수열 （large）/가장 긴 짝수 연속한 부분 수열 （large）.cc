#include <iostream>
#include <algorithm>
using namespace std;


int n , k ; // 수열의 길이, 삭제 최대 가능 횟수

int arr[1'000'001];


int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> k ;
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    
  int maxLen = 0 ; 
int flag = 0 ;
int en = 0 ;
  for(int st = 0 ; st < n ; st++) {

    while(flag <= k && en < n){ // 중복가능횟수가 0이상, en이 n보다 작을 때
        if(arr[en] % 2 !=0) flag++; // 홀수면 제거하기
        en++; 
    }
    maxLen = max(maxLen, en - st - flag); 
    flag -= arr[st] % 2 ;
  }
 cout << maxLen ; 
}

/*
[해결전략 참고]

[시작]
4월 1일 오후 7시 53분 -> 8시 20분 -> 시간초과

[배울 점]

[문제 이해]
- 길이 N인 수열 S
- 1이상의 정수
최대 K번 원소 삭제한 수열에서 짝수로 이루어져 있는 연속한 부분 수열 중 가장 긴 길이 구해보자.

[입력]
- n,k
- 수열 주어짐.

[제약]
N은 100만이하
K는 10만이하
[출력]
- 수열 S에서 최대 k번 삭제한 수열에서 짝수로 이루어져 있는 연속한 부분의 수열 중 간 길이 출력

[풀이전략]
투포인터  -> 연속, 100만이하
st for문을 돌면서
홀수가 나오면 제거, 최대횟수까지 제거후에 en-st를 maxLen에 있는 거와 비교해서 크면 삽입.



*/
