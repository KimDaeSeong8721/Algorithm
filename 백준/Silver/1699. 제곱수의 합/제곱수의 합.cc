#include <iostream>
#include <algorithm>

using namespace std;


int dp[100'001];

const int INF = 0x7FFFFFFE;

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int n ; 
    cin >> n ;
    fill(dp+1,dp+n+1,INF);
    dp[1] = 1 ;
    dp[0] = 0 ; 
    for(int i = 2 ; i <= n ; i++) {
        for(int j = 1 ; j*j <= i ; j++) {
            dp[i] = min(dp[i-j*j]+1, dp[i]);
        }
    }
    cout<< dp[n];
}