#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;



int t[16];
int p[16];
int dp[16];

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int n ; 
    cin >> n ;
    for(int i = 1 ; i <= n  ;i++)
    {
        cin >> t[n-i+1] >> p[n-i+1];
    }

    for(int i =1 ; i <= n ; i++) {
        for(int j = 0 ; j < i ; j++) {
            dp[i] = max(dp[j],dp[i]);
         }
        if(i-t[i] < 0) continue;
        dp[i] = max(dp[i-t[i]] + p[i], dp[i]);


    }
    cout << *max_element(dp+1,dp+n+1);
}