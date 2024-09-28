#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int n ;
    ll minV, m ;
    vector<ll> v ;
    cin >> n >> m ;
    minV = 0x7fffffff; 
    for(int i = 0 ; i < n ; i++) {
        ll tmp;
        cin  >> tmp ; 
        v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    
    int en = 0;

    for(int st = 0 ; st < n ; st++) {
        while(en < n && v[en] - v[st] < m) en++;
        if(en == n) break;
        minV = min(minV, v[en] - v[st]) ;
    }
    cout << minV ; 
}