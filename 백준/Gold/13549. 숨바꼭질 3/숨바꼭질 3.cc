#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;


int dis[100001] ;
int const INF = 2147483647 ;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, k ;
    cin >> n >> k;
    queue<int> q ; // 1: 위치

    fill(dis,dis+100001, INF);
    q.push(n);
    dis[n] = 0 ;
    while(!q.empty()) {
        auto cur = q.front() ; q.pop();
        int x = cur;
        if(x < 0 || x > 100000) continue;
        if(x == k) break;
        
        if(x-1 >= 0 && dis[x-1] > dis[x]+1) { q.push(x-1); dis[x-1] = dis[x]+1; }
        if(x+1 <= 100000 && dis[x+1] > dis[x]+1) {q.push(x+1);  dis[x+1] = dis[x]+1; }
        if(2*x <= 100000 && dis[2*x] > dis[x]) {q.push(2*x);  dis[2*x] = dis[x] ; }
    }

    cout << dis[k]; 
}