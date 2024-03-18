
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int v, e ; 

vector<int> adj[101] ;
queue<int> q ;
int vis[101] ; 
int cnt = -1 ;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e ;
    
    while(e--) {
        int u, v ;
        cin >> u >> v ;
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    q.push(1);
    vis[1] = 1 ;
    
    while(!q.empty()){
        auto cur = q.front() ; q.pop();
        cnt++ ;
        for(auto a : adj[cur]){
            if(vis[a]) continue;
            vis[a] = 1 ;
            q.push(a);
        }

    }

    cout << cnt ;
}

/*
[해결전략 참고]

[시작]
3.18.월.오후 10:44 ~ 11:01 메모리초과? ~ 

[배울 점]

[문제 이해]
- 1번 컴퓨터가 바이러스에 걸리면 1번과 연결된 (직,간접)모든 컴퓨터 감염
- 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수
[입력]
- 1줄 : 노드 수
- 둘째줄에는 간선의 개수 주어짐.
- 셋째줄부터는 간선과 노드 연결관계

[제약]
 - 1<=컴퓨터의 수 <= 100
 - 1번부터 번호 매겨짐.
 
[출력]
- 1번 컴퓨터를 통해 웜 바이러스에 걸리는 컴퓨터의 수를 출력하시오


[풀이전략]
- 인접 리스트를 구현
 벡터 이용
- BFS 구현 기기

*/
