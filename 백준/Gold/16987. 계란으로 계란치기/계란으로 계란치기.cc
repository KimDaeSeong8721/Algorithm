
#include <iostream>
#include <algorithm>
using namespace std;



int n ;
int s[9];
int w[9];
int max_count ; 

void func(int idx, int cnt ) {

    if(idx == n) {
        if(max_count < cnt) max_count = cnt ; 
        return ;
    }

    for(int i = 0 ; i < n ; i++) {
        if(s[idx] <=0 ){
            func(idx+1,cnt); 
        } else { 
            // if(idx == n-1) func(idx+1,cnt); 
            if(idx == i || s[i] <=0 ) continue;

              s[idx] -= w[i]; 
             s[i] -= w[idx] ;
             int tempCount = 0  ;

                 if(s[idx] <= 0) tempCount++; // 손에 들고 있는 계란이 깨졌으면
                 if(s[i] <= 0) tempCount++; //ㅁ 부딪혀진 계란이 깨졌으면
                func(idx+1, cnt+tempCount); 
                
                 s[idx] += w[i]; 
                 s[i] += w[idx] ;
        }
    }
    if(max_count < cnt) max_count = cnt ; 

    
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n;

    for(int i = 0 ; i < n ; i++) {
        cin >> s[i] >> w[i] ;
    }

    func(0,0);
    cout << max_count ;
}

/*
[해결전략 참고]

[시작]
24.03.12 -> 테스트케이스 다 잘되는데 왜 틀리지? -> 가장 최근에 든 계란을 손에든 계란으로 착각하고 basecondition 잘못함. -> i가 n-1일 때 if(cnt == n) 조건문을 체크를 못함.
[배울 점]

[문제 이해]
- 계란 내구도와 무게 있음.
- 두 계란을 부딪히면 각 계란의 내구도는 상대 계란의 무게만큼 깎임.
- 내구도가 0이하면 깨짐
- 퍼즐
    - 가장 왼쪽 계란을 든다.
    - 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다. -> 손에 든 계란 깨졌거나, 안 깨진 계란이 없으면 넘어감. 손에 든 계란을 원래 자리로.
    - 가장 최근에 든 계란의 한 칸 오른쪽 계란을 들고 2번 다시 진행. 단 가장 최근 든 계란이 가장 오른쪽에 위한 경우 종료
- 최대한 많은 계란을 깨는 것이 목표

[입력]
- 첫줄은 계란의 수 N
- 다음 N개의 줄에는 내구도 무게
- i+1줄은 왼쪽에서 i번째 위치한 계란
[제약]
1 ≤ N ≤ 8
1 ≤ Si ≤ 300
1 ≤ Wi ≤ 300
왼쪽부터 차례로 들어서 한번씩만 다른 계란을 쳐야함. 
[출력]
인범이가 깰 수 있는 계란의 최대 개수 출력


[풀이전략]
N이 작아서 백트래킹
계란을 최대한 많이 깨려면 ? 한번 칠 때마다 깨지면 좋지. -> 자신의 내구도보다 부딪히려는 계란의 무게가 크거나 같으면 됨.
자신의 내구도보다 부딪히려는 계란의 무게가 크거나 같은게 없다면? 자신의 무게가 부딪히려는 계란의 내구도보다 크거나 같은 거 찾기.
이것도 없으면? 자신의 내구도가 매우 높고, 자신의 무게 매우 작음 
-> 아니 그냥 다 해보면 되지 않을까? -> 다해서 최종 cnt가 큰 놈이 정답이겠지. 
-> 갑자기 다 해보자고 떠오른 이유는 힌트에 브루트포스가 적혀있었기 때문..

- base condition : 가장 최근 든 계란이 가장 오른쪽에 위치할 때 
- for문으로 모든 계란 방문 
- 재귀를 들어가면서 계란 내구도 수정
- 재귀 빠져나올때 계란 내구도 원상 복구
- 

*/
