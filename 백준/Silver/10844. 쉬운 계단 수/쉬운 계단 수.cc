#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll ; 
ll dp[101][10] ;

ll sumV ; 
int n ;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;
    for(int j = 1 ; j <= 9 ; j++) dp[1][j] = 1 ;
    for(int i = 2; i <= n ; i++) {
	    for(int j = 0 ; j <= 9 ; j++) {
	    if(j == 0) dp[i][j] = dp[i-1][j+1];
	    else if(j == 9) dp[i][j] = dp[i-1][j-1];
	    else dp[i][j] =  dp[i-1][j-1] + dp[i-1][j+1]; 
        dp[i][j] %= 1'000'000'000;
            }   
        }

    for(int j = 0 ; j <= 9 ; j++) sumV += dp[n][j] ;
    cout << sumV % 1'000'000'000 ;
}