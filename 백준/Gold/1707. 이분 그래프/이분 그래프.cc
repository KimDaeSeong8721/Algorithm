
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int t ; 
int v,e; 
int color[20001] ; // -1 : 방문x , 0: 검정;짝수, 1: 흰색;홀수
const int BLACK = 0 ;
const int WHITE = 1 ;

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t ; 
    
    while(t--) {
     
        vector<int> adj[20001] ;
        queue<int> q ;
        int cnt = 0;
        int isBinaryGraph = true ;
        
        cin >> v >> e ;


        fill(color,color+v+1, -1);

        for(int i = 0 ; i < e ; i++) {
            int u, v ;
            cin >> u >> v ;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    

    for(int i = 1 ; i <= v ; i++) {
        if(color[i] != -1) continue;
        q.push(i);
        color[i] = BLACK; 
        while (!q.empty()) 
        {
            if(!isBinaryGraph) break;
            auto cur = q.front(); q.pop();
            for(auto nxt : adj[cur]) {
                if(color[nxt] != -1) {
                    if(color[nxt] == color[cur]) {isBinaryGraph = false ; break; }
                    else continue;
                } 
                color[nxt] = ((color[cur]+1)%2);
                q.push(nxt);
            }
        }
    }
    if(isBinaryGraph) cout << "YES"<<'\n';
    else cout<<"NO"<<'\n';
    } 
   
}

/*
[해결전략 참고]

[시작]
1번시도 :24.3.19.화.오후 9:42, -> 왜 6% 틀리지??? 

2번시도 : 3월 20일. 오후 5시 -> 왜 6% 틀리지? -> 비연결그래프 고려안해서?

[배울 점]
- 이분그래프에 대한 정의를 잘못 이해하고 있었어.

[문제 이해]
- 정점의 집합을 두개로 분할.
- 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할 -> 이분 그래프
- 이 그래프가 이분 그래프인지 아닌지 판별
- 정점은 1~V까지
[입력]
- 1줄 : 테스트 케이스 K개
- 각 1줄 : V, E
- 각 2줄부터는 E개에 걸쳐 간선 관계 u v 

[제약]
2 ≤ K ≤ 5
1 ≤ V ≤ 20,000
1 ≤ E ≤ 200,000
[출력]
- 이분그래프면 YES 아니면 NO.

[풀이전략]
- 연결이 두개의 그래프로 나뉘는가?
- BFS 구현하기 -> 방문여부 체크, 모든 노드 확인
- 모든 노드를 확인하면서 연결이 되면, 큐에 넣는다.큐에서 빠져나오면 cnt 체크
- 케이스이니까 초기화 주의하자.

*/
