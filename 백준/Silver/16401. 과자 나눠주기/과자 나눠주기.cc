#include <iostream>
#include <algorithm>

using namespace std;
int m,n ;

int arr[1000000];

bool check(int x){
    // 정답은 큰 true;
    int sum = 0 ;
    for(int i = 0; i < n ; i++){
         sum += (arr[i] / x) ; 
    }
    return sum  >= m ; 
    

    // if(m > n){
    //     // 주어진 막대과자가 조카보다 적음.

    //     return false;
    // }
    // else { // m <= n ;
    //  // 주어진 막대과자가 조카보다 많거나 같음.
    // //check(lo) = true, check(hi) = false
    // // 정답은 가장 큰 true여야 함. 따라서 lo에 정답.
    // return (n-x >= m);
    // }
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> m >> n ;
    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    sort(arr,arr+n);
    
    int lo = 0;
    int hi = 1e9;

    while(lo+1 <hi) {
        int mid = (lo+hi)/2 ;
        if(check(mid)) lo = mid ;
        else  hi = mid ;
    }
    cout << lo ; 
}

/*
[해결전략 참고]

[시작]
3.21. 1:24 pm ~ 
[배울 점]
- 조카들에게 막대과자 하나씩
- 조카들이 먹는도안 떼 안씀 -> 최대한 긴 과자 주려고 함
- 조카에게 같은 길이의 막대 과자를 나누어줘야함
- M명의 조카, N개의 과자가 있을 때
조카 1명에게 줄 수 있는 막대 과자의 최대 길이는?
[문제 이해]

[입력]
1줄 : 조카수 M, 과자수 N 
2줄 : 과자 N개의 길이 L1, L2 ,L3 ... 

[제약]
- 나눌수있지만 합치기 불가능. 길이는 양수.
 M,N은 백만이하
 L은 10억이하.
[출력]
- 조카 1명에게 줄 수 있는 막대 과자 최대의 길이 출력
- 줄수없다면 0 출력

[풀이전략]
파라메트릭 서치 이용 -> 최적화문제를 결정문제로,
M,N 범위가 너무크다 -> 이분탐색?

1. 과자의 길이 오름차순 정렬하기
2. 기존의 과자 길이를 현재 선택한 과자길이로 나눈 몫을 더한다.
3. 더한 값을 조카의 수와 비교


*/
