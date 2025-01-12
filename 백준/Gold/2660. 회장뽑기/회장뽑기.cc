#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


vector<int> adj[51];
int score[51] ;


int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int n ; 
    cin >> n ;

    while (true)
    {
        int a,b ;       
        cin >> a >> b ;
        if(a == -1 && b == -1) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    fill(score+1,score+n+1,0);

    for(int i = 1 ; i <= n ; i++) {
        queue<int> q ;
        int dis[n+1] ; 
        fill(dis+1,dis+n+1, -1);
        q.push(i);
        dis[i] = 0;
        while (!q.empty())
        {
            auto cur = q.front(); q.pop();

            for(auto e: adj[cur]) {
                if(dis[e] >= 0) continue;
                dis[e] = dis[cur] + 1;
                q.push(e);
            }
        }
        score[i] = *max_element(dis+1,dis+n+1);
    }

     int min = *min_element(score+1,score+n+1);
      vector<int> result ;
     for(int i = 1 ; i <= n ; i++) {
        if(score[i] == min) result.push_back(i);
     }
    cout << min << ' '<< result.size() <<'\n';
    
    for(auto e : result) cout << e << ' ';
}