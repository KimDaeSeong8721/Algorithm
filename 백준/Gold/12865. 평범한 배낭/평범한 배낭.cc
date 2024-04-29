#include <iostream>
#include <algorithm>
using namespace std;


int n,k ;
int dp[101][100'001]; // dp[i][j] : 최대 k무게까지 i번째까지 배낭에 넣을 수 있는 물건 가치의 최대합
int w[101];
int v[101];
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> k ;

    for(int i = 1 ; i <= n ; i++){
        cin >> w[i] >> v[i];
    }

    for(int j = 1 ; j <= k ; j++){
        if(j- w[1] >= 0){
        dp[1][j] = v[1];
        } 
    }
    for(int i = 2 ; i <= n ; i++){
        for(int j = 1 ; j <= k ; j++) {
            if(j-w[i] >= 0){
                // 배낭에 물건 담음
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]] + v[i]) ;
            } else {
                // 배낭에 물건을 담지 않음.
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][k]; 
}