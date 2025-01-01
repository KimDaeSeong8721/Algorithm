#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;


typedef long long ll ; 
ll n ; 
int p, q ; 
unordered_map<ll,ll> m ;

ll func(ll i) {
    if(i == 0) return 1 ;

    ll ip = floor(i / p) ;
    ll iq = floor(i / q) ; 

    if(m[ip] == 0) {
        m[ip] = func(ip);
    }

    if(m[iq] == 0) {
        m[iq] = func(iq);
    }
    return m[ip] + m[iq] ; 
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    m[0] = 1 ;
    cin >> n >> p >> q ;

    cout << func(n);
}
