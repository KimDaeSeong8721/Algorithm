#include <iostream>
#include <algorithm>
using namespace std;


int n ;

long long dp[101][10];
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;
    
    dp[1][0] = 0 ;
    for(int j = 1 ; j < 10 ; j++) dp[1][j] = 1;


    for(int i = 2 ; i <= 100 ; i++)
        for(int j = 0 ; j < 10 ; j++){
            if(j == 0) dp[i][0] = dp[i-1][1] % 1'000'000'000 ;
            else if(j == 9) dp[i][9] = dp[i-1][8] % 1'000'000'000;
            else dp[i][j] = dp[i-1][j-1] % 1'000'000'000 + dp[i-1][j+1] % 1'000'000'000;
        }
        
    long long sum = 0 ;
    for(int j= 0 ; j < 10 ; j++) sum += dp[n][j] % 1'000'000'000; 
    cout << sum % 1'000'000'000 ; 
}