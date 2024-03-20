#include <iostream>
#include <algorithm>
using namespace std;


int n ; // 상근이가 가지고 있는 숫자의 개수
int arr[500001]; // 상근이가 가지고 있는 숫자카드 목록
int m ; // 주어진 숫자의 개수
int arr2[500001];


bool binarySearch(int n ,int ans) {
  int st = 0 ; int en = n-1 ;
     while(st<=en){
    int mid = (st + en + 1) / 2 ;
    if(ans > arr[mid]) st = mid+1 ;
    else if(ans < arr[mid]) en = mid-1;
    else return true;
  }
  return false; 
}


int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
  
  cin >> n ;
  for(int i = 0 ; i < n ; i++)
    cin >> arr[i];
  sort(arr,arr+n);

  cin >> m ; 
  for(int i = 0 ; i < m ; i++)
    cin >> arr2[i];
  
  for(int i = 0 ; i < m ; i++){
    int ans = arr2[i];
    // cout << binarySearch(n, ans) << ' ';
    cout << binary_search(arr,arr+n,ans) << ' ';
  }
}

/*
[해결전략 참고]

[시작]
- 3월 20일 수 오후 9:15 ~ 9: 45  틀림 어떤게 문제지? 10:19 ~ 10:26 (성공)

[배울 점]
- mid = (st+ en) / 2 와 mid = (st+ en+1) / 2 차이는?
- 틀렸을 때 어떻게 대처해야할까? 문제의 조건들을 잘 읽어보기 -> 출력부분 제대로 읽어보기. arr2 정렬 필요없음.
[문제 이해]
- N개의 카드를 가지고 있음.
- 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고
있는지 아닌지를 구하는 프로그램 작성.

[입력]
- 첫줄은 숫자카드의 개수 N
- 숫자 카드에 적혀있는 정수가 주어짐.
- 셋쩨줄은 M
- 넷째줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야할 M개의 정수가 주어짐.

[제약]
- 1 ≤ N ≤ 500,000
- -10,000,000 <= 숫자에 적혀있는 수 <= 10,000,000
- 같은 수 적혀 있지 않음.
- 1<= M <= 500,000
- - 10,000,000<= M개의 각 정수 <=  10,000,000

[출력]
M개의 수에 대해 상근이가 가지고 있으면 1, 아니면 0
[풀이전략]
- N이 상당히 크다. N^2만 되도 25억연산처리횟수
- 이분탐색이나 다른 기술들을 사용해야겠다.
- 50만log(50만) 1000만log50 -> 약 5천만~6천만 가능
이분탐색 이용하기
1. st, en 포인터 준비. st =0 en = n-1
2. bool binarySearch() {
while(st<=en){
  long long mid = (st + en ) / 2 ;
  if(m > mid) st = mid+1 ;
  else if(m < mid) en = mid-1;
  else return true;
}
return false; 
}
3. 이분 탐색을 M 번 반복함.
4. 배열은 정렬시켜야 함.





*/
