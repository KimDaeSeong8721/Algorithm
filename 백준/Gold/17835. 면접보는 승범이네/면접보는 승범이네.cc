#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll ;
ll d[100001];

vector<pair<ll,int>> adj[100001] ;

priority_queue<pair<ll ,int>,
                vector<pair<ll,int>>,
                greater<pair<ll,int>>> pq;

const ll INF = 0x7f7f7f7f7f7f7f7f;

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 

int n, m , k ;
cin >> n >> m >> k ;

for(int i = 0 ; i < m ; i++) {
    int u, v, c;
    cin >> u >> v >> c ;
    adj[v].push_back({c,u});
}

fill(d+1,d+n+1,INF);

for(int j = 0 ; j < k ; j++) {
    int l ;
    cin >> l ;
    d[l] = 0 ;
    pq.push({0,l});
}


while (!pq.empty())
{
    auto cur = pq.top() ; pq.pop();
    if(d[cur.second] != cur.first) continue;
    for(auto nxt : adj[cur.second]) {
        if(d[nxt.second] <= d[cur.second] + nxt.first) continue;
        d[nxt.second] = d[cur.second] + nxt.first;
        pq.push({d[nxt.second],nxt.second});

    }
}

ll result_dis_idx =  max_element(d+1,d+n+1) - d; 
cout << result_dis_idx << '\n'<< d[result_dis_idx] ; 

}