#include <iostream>
#include <algorithm>
using namespace std;



int dp[3][10000];


int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int t ; 
    cin >> t ; 
    int c[] = {1,2,3};
    while (t--)
    {
        int n ; 
        cin >> n ; 
        
        dp[0][0] = 1; 
        dp[1][0] = 1; 
        dp[2][0] = 1;
        for(int i = 0 ; i < 3 ; i++) {
            for(int j = 1 ; j <= n ; j++) {
                dp[i][j] = 0 ;
                if(i-1 >= 0) {
                    dp[i][j] += dp[i-1][j];
                }
                if(j-c[i] >= 0) {
                    dp[i][j] += dp[i][j-c[i]];
                }
            }
        }
        cout << dp[2][n] <<'\n';
    }
}