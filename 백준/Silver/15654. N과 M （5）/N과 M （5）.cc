
#include <iostream>
#include <algorithm>
using namespace std;


int arr[8];

int result[8];

int isused[8];
int n,m ;

void func(int cnt) {
    if(cnt == m) {
        for(int i = 0; i< m ; i++) cout << result[i] << ' ';
        cout << '\n';
        return ;
    }

    for(int i = 0 ; i < n ; i++) {
        if(isused[i]) continue;
        isused[i] = 1 ;
        result[cnt] = arr[i] ;
        func(cnt+1);
        isused[i] = 0 ;
    }
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    
    cin >> n >> m ;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i] ;
    }

    sort(arr, arr + n);

    func(0);
}



/*
[해결전략 참고]

[시작]

[배울 점]

[문제 이해]
- N, M 자연수
- N개의 자연수는 모두 다른 수
- N개의 자연수 중 M개를 고른 수열
 -> 입력받은 수를 이용해서 순열 구하기.
[입력]
- N, M 주어짐
- N개의 수가 주어짐

[제약]
- 주어지는 자연수 <= 10,000

[출력]
- 사전 순으로 증가하는 순서로 출력

[풀이전략]
- 배열에 입력받은 N개의 수를 저장한다.

*/
