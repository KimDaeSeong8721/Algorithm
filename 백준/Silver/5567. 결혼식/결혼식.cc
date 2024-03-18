
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


// 결혼식

int vis[501];
int ans ; 
int v,e ; 
vector<int> adj[501];
queue<pair<int,int>> q ;
// void dfs(int cur,int cnt) {
//     if(cnt == 2) {
//         return; }
//     vis[cur] = 1 ;
//     for(auto a : adj[cur]) {
//         if(vis[a] == 1) continue;
//         ans++; 
//         dfs(a,cnt+1);
//     }
// }



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
    q.push({0,1});
    vis[1] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        int cnt = cur.first;
        if(cnt == 2) break;

        for(auto a : adj[cur.second]){
            if(vis[a]) continue;
            vis[a] = 1;
            q.push({cnt+1, a});
            ans++ ;
        }
    }

    cout << ans; 
}

/*
[해결전략 참고]

[시작]
3.18.월. 오후 11:15 ~
[배울 점]

[문제 이해]
- 학교 동기 중 자신의 친구와 친구의 친구 초대.
- 상근이의 동기는 모두 N명
- 이 학생들의 학번은 1~ N 임
- 상근이는 1번

[입력]
- 1줄 : 상근이 동기수 n
- 2줄 : 리스트의 길이 m 
- m개 줄에는 연결관계 ai bi 
[제약]
- 2 ≤ n ≤ 500
- 1<= m < 10000
- 1<= ai < bi <= n 
- a b 친구 b a도 친구 -> 무향 그래프
- 자신의 친구와 친구의 친구만! 
[출력]
- 결혼식에 초대할 사람의 수

[풀이전략]
1. 인접리스트 - 무향 그래프

2. 이번에는 dfs 구현

*/
