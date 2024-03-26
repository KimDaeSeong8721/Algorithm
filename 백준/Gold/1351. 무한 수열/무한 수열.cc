#include <iostream>
#include <algorithm>
using namespace std;



typedef long long ll  ;

ll n, p, q ; 

unordered_map<ll, ll> m ;


ll dfs(ll i) {
  if(i == 0) return 1 ;
  if( i/p == i/q) {
    if(m.find(i/p) == m.end()) {m[i/p] = dfs(i/p);
    }
  } else {
  if(m.find(i/p) == m.end()) m[i/p] = dfs(i/p);
  if(m.find(i/q) == m.end()) m[i/q] = dfs(i/q);
  }

  m[i] =  m[i/p] + m[i/q];
  return m[i];
}
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
  
  m[0] = 1 ;
  cin >> n >> p >> q ;

  cout << dfs(n);
}

/*
[해결전략 참고]

[시작]
24.3.26 오후 8시 20분 ~ 8시 34분 -> 실패 - 0으로 나눠서. -> 메모리초과 (for문으로 다 저장해서)
[배울 점]

[문제 이해]
- A0 = 1
- Ai = A(i/p) + A(i/q) (i >= 1)

p = 2 q = 3 
i= 1 일 때
A1 = A0 + A0 
i =2 
A2 = A1 + A0 
i = 3
A3 = A1 + A 1 
i = 4
A4 = A2 + A 1

[입력]
- N P Q
[제약]
0 <= N <= 10^12
2 <-= P, Q <= 10^9 

[출력]
- An 출력
[풀이전략]
- 배열 생성 불가 -> 100억
- 해쉬맵

*/
