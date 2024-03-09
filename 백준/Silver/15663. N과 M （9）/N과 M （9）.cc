
#include <iostream>
#include <algorithm>
using namespace std;

// N과 M (9)
// 중복된 수들을 주어주고 M개 수열 고르기

int arr[8];
int result[8];
int isused[8];

unordered_map<int,int> hashMap ;

int n,m ;

void func(int cnt) {
    if(cnt == m) {
        for(int i = 0; i< m ; i++) cout << result[i] << ' ';
        cout << '\n';
        return ;
    }

    int tmp = 0 ;
    for(int i = 0 ; i < n ; i++) {
        if(isused[i] || tmp == arr[i]) continue;
        isused[i]++ ;
        result[cnt] = arr[i] ;
        tmp = arr[i] ;
        func(cnt+1);
        isused[i]-- ;
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
- 바킹독 정답 참고
[시작]
- 실패 

[배울 점]
- 중복체크를 for문안에서 할 것인지, 재귀를 넘어갈때마다 하는지 판단해야함.

[문제 이해]
- N, M 자연수
- N개의 자연수 중 M개를 고른 수열
 -> 입력받은 수를 이용해서 순열 구하기.
[입력]
- N, M 주어짐
- N개의 수가 주어짐

[제약]
- 주어지는 자연수 <= 10,000
- 중복되는 수열을 여러번 출력하지 말 것 

[출력]
- 사전 순으로 증가하는 순서로 출력

[풀이전략]
- 해쉬맵 이용 -> 실패

*/
