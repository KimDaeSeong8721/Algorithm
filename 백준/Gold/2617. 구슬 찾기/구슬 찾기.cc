#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int m , n; 

vector<int> adj1[100];
vector<int> adj2[100];
int vis[100];
      queue<int> q ; 

int result ;

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m ; 
    while(m--) {
      int a, b ;
      cin >> a >> b ; 
      adj1[a].push_back(b);
      adj2[b].push_back(a);
    }

    for(int i = 1 ; i <=n ; i++){
      fill(vis,vis+100,0);
      q.push(i);
      vis[i] = 1 ;

      int cnt = 0 ;
      while (!q.empty())
      {
        auto cur = q.front() ; q.pop();
          for(auto nxt : adj1[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
            cnt++;
          }
      }
      if(cnt >= (n+1)/2) {result++; continue;}
      }
    
      
      for(int i = 1 ; i <=n ; i++){
      fill(vis,vis+100,0);
       q.push(i);
      vis[i] = 1 ;

      int cnt = 0 ;
      while (!q.empty())
      {
        auto cur = q.front() ; q.pop();
          for(auto nxt : adj2[cur]){
            if(vis[nxt]) continue;
            q.push(nxt);
            vis[nxt] = 1;
            cnt++;
          }
      }
      if(cnt >= (n+1)/2) {result++; continue;}
    }
    cout << result ; 
}
