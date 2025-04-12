#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;



int n ;
int m; 
vector<int> v ; 
bool check(int k) {
    long long  sum = 0 ;
    for(auto e : v) {
        if(k - e > 0){
            sum += e ;
        } else {
            sum += k ; 
        }
    }
    return sum <= m ; 
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n ; 
    while (n--)
    {
        int tmp ; 
        cin >> tmp ;
        v.push_back(tmp);
    }
    cin >> m ; 

    int lo = 1 ;
    int hi = *max_element(v.begin(), v.end());
    lo--;
    hi++;
    while (lo + 1 < hi)
    {
        int mid = (lo + hi) / 2  ; 
        if(check(mid)) {
            lo = mid ;
        } else {
            hi = mid;
        }
    }
    cout << lo ;
}