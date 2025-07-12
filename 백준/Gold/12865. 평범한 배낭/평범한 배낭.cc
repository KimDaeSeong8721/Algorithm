    #include <iostream>
    #include <algorithm>
    #include <set>
    #include <unordered_map>
    using namespace std;



    int w[101];
    int v[101];
    int dp[101][100001];

    int main() {
    ios::sync_with_stdio(0);
        cin.tie(0); 
        int n, k ;
        cin >> n >> k ;
        for(int i = 0 ; i < n ; i++) {
            cin >> w[i] >> v[i];
        }

        // dp[i][j] : i번째 배낭까지 남은 j무게를 채울때 최대 가치값
        for(int j = 0 ; j <= k ; j++){
            if(j - w[0] >= 0 ) {
                dp[0][j] = v[0];
            }
        }

        for(int i = 1 ; i < n ; i++) {
            for(int j = 0 ; j <= k ; j++) {
                if (j-w[i] >= 0 )
                    dp[i][j] = max(dp[i-1][j-w[i]] + v[i], dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j] ;
            }
        }
        cout << dp[n-1][k] ;
    }
