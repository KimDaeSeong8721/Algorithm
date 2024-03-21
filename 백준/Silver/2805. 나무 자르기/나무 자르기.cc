#include <iostream>
#include <algorithm>
using namespace std;




int n, m ;
int arr[1000001];

bool check(int mid) {
    long long sum = 0;
    for(int i = 0 ; i < n ; i++) {
        if(arr[i] > mid){
        sum += (arr[i] - mid);
        }
    }
    return sum >= m ;
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m ; 
    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    int lo = 0, hi = 1e9 ; 
    
    while(lo+1 <hi) {
        int mid = (lo + hi) / 2 ;
        if(check(mid)) lo = mid ;
        else hi = mid ;
    }
    cout <<lo ; 
}

/*
[해결전략 참고]

[시작]

[배울 점]

[문제 이해]
- 톱날은 땅기준 H미터 위로.
- H 위의 부분의 나무는 잘리고, 낮은 나무느 안잘림.
-> 20 15 10 17 -> 15 15 10 15;
-> 상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 거임. 총 7미터
-> 상근이는 필요한 만큼만 가져가려고 함.
-> 최소 M미터 나무를 가져가려면 절단기 높이의 최댓값은?

[입력]
1줄 : 나무의 수 N, 상근이 가져가려는 나무의 길이는 M임.
2줄 : 나무의 높이가 주어짐
[제약]
- 나무의 높이의 합 >= M 
- 0 <=나무의 높이는 < 1e9
- H>=0
- 1 ≤ N ≤ 1,000,000
- 1 ≤ M ≤ 2,000,000,000

[출력]
최소 M미터 나무를 가져가려면 절단기 높이의 최댓값 출력.

[풀이전략]
이분 탐색
파라매트릭 서치 (최적화 -> 결정문제)
0. 오름차순 정렬하기
1. check 함수 만들기.
    long long sum = 0 ;
    
    for문 -> 
    if  주어진 나무 > x 이면
    sum = +(주어진 나무 - x ) 단,.
    만약 sum >= m
2. lo, hi 설정
3. check(lo), check(hi) 확인. 둘은 달라야함.
    - check(lo) = T, check(hi) = F
4. 문제가 check(lo)값의 가장 큰값을 요구하면 답은 lo에,
    문제가 check(hi)값의 가장 작은 값을 요구하면 답은 hi에
    - 가장 큰 T를 구해야하기 떄문에 답은 lo에 있음.
5. lo, hi 재설정
    - lo +1 == hi 를 고려하여 lo = 0 ; hi = max+1 => hi = 1e9+1 ; 

*/
