
#include <iostream>
#include <algorithm>
using namespace std;


// 로또

int k ;
int s[13];
bool isused[13] ; 
int arr[6];

void func(int cnt, int prev) {
    if(cnt == 6) {
        for(int i = 0 ; i < 6 ; i++) cout << arr[i] << ' ';
        cout<<'\n';
    }

    for(int j = prev ; j < k ; j++) {
        // if(isused[j]) continue;
        // isused[j] = true ;
        arr[cnt] = s[j];
        func(cnt+1, j+1);
        // isused[j] = false ;
    }
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    
    while(1) {
        cin >> k ;
        if(k == 0) break;

        for(int i = 0 ; i < k ; i++) {
            cin >> s[i];
        }

        func(0,0);
        cout << '\n';
    }
}





/*
[해결전략 참고]

[시작]

[배울 점]
- 문제조건 빼먹음 -> 집합이니깐 조합이지 순열이 아니라.
- 25%에서 계속 틀리데 .
[문제 이해]
- 1~49 에서 6개 고름
- 전략은 49가지 중 k(k>6)개의 수를 골라 집합 s를 만든 후 그 수만 가지고 번호 선택
- 집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램 작성

[입력]
-각 줄은 테스트케이스 
- 입력 0 이 주어지면 테스트 종료

[제약]
- 6< k < 13 
- 첫 번째수는 K 이고, 이후 K개의 수는 집합 S에 포함되는 수 
- 집합 s는 오름차순으로 주어짐.

[출력]
- 수를 고르는 모든 방법 출력

[풀이전략]
- k, 집합 S를 저장
- 백트래킹


*/
