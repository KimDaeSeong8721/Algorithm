
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq ;

int n ; 
int arr[1501][1501];
int result ; 
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++){
            cin >> arr[i][j];
            pq.push(arr[i][j]);
            if(pq.size() > n) {
                pq.pop();
            } 
        }
    cout << pq.top(); 

}

/*
[해결전략 참고]
https://www.acmicpc.net/board/view/39829
[시작]
- 3.14 목 오전 1:20  ~ 전혀 감이 안오는데?..

[배울 점]
- 이걸보고 힙을 사용해야겠다는 생각이 어디에서 들어?

[문제 이해]
- NxN 행렬
- 모든 수는 자신의 한 칸 위에 있는 수보다 큼
- N번째 큰 수를 찾기

[입력]
- 1줄 : N
- 다음 N 줄 : N개의 수 
[제약]
- 표에 채워진 수는 모두 다름
- 1<= N <= 1500
- 1초
- -10억 <= 표에적힌수 <=10억

[출력]
- N번째 큰수 출력

[풀이전략]
배열에 다 받고 
최대힙에 넣는다 -> n^2*logn
최대힙에서 n번 삭제 -> n log n


*/
