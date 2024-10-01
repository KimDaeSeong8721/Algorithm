#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

vector<int> p(303,-1);
int v ; 
vector<tuple<int,int,int>> edges;



int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u) ; v = find(v);
    if(u == v) return false;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u ;
    else p[u] = v ;
    return true; 
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> v ; 

    for(int i = 1 ; i <= v ; i++) {
        int cost; 
        cin >> cost ; 
        edges.push_back({cost, i, v+1});
    }

    for(int i = 1 ; i <= v ; i++)
        for(int j = 1 ; j <= v ; j++) {
            int cost ; 
            cin >> cost ; 
            if(i >= j) continue ;
            edges.push_back({cost,i,j});
        }

    sort(edges.begin(),edges.end());
    v++; 
    int cnt = 0; 
    int ans = 0 ; 

    for(int i = 0 ; i < edges.size() ; i++){
        int a,b, cost;
        tie(cost,a,b) = edges[i];
        if(!is_diff_group(a,b)) continue;
        ans += cost ;
        cnt++; 
        if(cnt == v-1) break;
    }
    cout << ans ; 
}