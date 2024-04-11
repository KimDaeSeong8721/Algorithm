#include <iostream>
#include <algorithm>
using namespace std;

int t ; 
int n ; 
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> t ;
    while (t--)
    {   
        pair<int,int> d[41];
        cin >> n ;
        d[0] = {1,0};
        d[1] = {0,1};
        for(int i = 2 ; i <= n ; i++){
            d[i] = {d[i-2].first + d[i-1].first, d[i-2].second + d[i-1].second };
        }
        cout << d[n].first << ' ' << d[n].second<<'\n' ; 
    }
    
 
}