
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;



int score[50];
int n ; 
vector<int> adj[50];
void bfs(int cur) {
    int dis[50];
    queue<int> q ;

    fill(dis,dis+n +1 ,-1);
    q.push(cur);
    dis[cur]++ ;

    while (!q.empty())
    {
        auto cur = q.front(); q.pop();
        
        for(auto nxt: adj[cur]){
            // if(nxt == 5) cout << dis[nxt]<<"야" ; 
            if(dis[nxt] >= 0) continue;
            q.push(nxt);
            dis[nxt] = dis[cur] + 1; 
        }
    }
    score[cur] = *max_element(dis , dis+n+1);
}
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n ;

    while(1){
        int u, v ;
        cin >> u >> v ;
        if(u == -1 && v == -1) break;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1 ; i <= n ; i++){
        bfs(i);
    }

    int sc = *min_element(score+1, score+n+1);
    int num = 0 ;
    for(int i = 1 ; i <= n ; i++){
        if(sc == score[i]) num++;
    }
    cout << sc << ' '<< num;
    cout << '\n';

    for(int i = 1 ; i <= n ; i++)
        if(score[i] == sc) cout << i << ' ';

    
}

/*
[해결전략 참고]

[시작]

[배울 점]

[문제 이해]
- 회장 선출
- 모르는 사람도 있지만, 몇 사람 건너면 모두가 서로 알 . 수있음.
각 회원은 다른 회원들과 가까운 정도에 따라 점수를 받게 됨.

어느 회원이
- 1점  다른 모든 회원과 친구.
- 2점 : 다른 모든 회원이 친구이거나 친구의 친구임을 뜻함?
- 3점: 다른 모든 회원이 친구이거나, 친구의 친구이거나, 친구의 친구의 친구

회장은 회원들 중 점수가 가장 작은 사람이 된다.

회장의 점수와 회장이 될 수 있는 모든 사람 찾기

[입력]
1줄 : 회원의 수 n
2줄부터 : a b -> a와 b는 친구
마지막 줄은 -1 -1이 두개 들어 있음.

[제약]
- 몇 사람 건너면 모두가 서로 알 수 있음
어느 두 회원이 친구사이면서, 동시에 친구의 친구사이면 -> 친구사이로 본다. -> 최단거리를 의미함.

n < 50 ;

[출력]
1줄은 회장의 후보의 점수와 후보의 수
2줄부터는 회장 후보를  오름차순으로 모두 출력.

[풀이전략]
1. 인접리스트로 표현한다.
2. BFS로 구현한다.
    - 방문여부 체크 

*/
