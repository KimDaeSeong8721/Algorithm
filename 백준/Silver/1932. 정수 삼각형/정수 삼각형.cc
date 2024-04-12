#include <iostream>
#include <algorithm>
using namespace std;

// 정수 삼각형.

int n  ; 
int arr[501][501]; 
int dp[501][501]; // dp[i][j] i층 j번째까지 합이 최대가 되는 경로에 있는 수의 합
int maxCnt ;



int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ; 
    for(int i =  0 ; i < n ; i++)
        for(int j = 0 ; j <= i ; j++)
            cin >> arr[i][j];
    
        dp[0][0] = arr[0][0] ;
     dp[1][0] = dp[0][0] + arr[1][0]  ; 
     dp[1][1] = dp[0][0] + arr[1][1] ;
    for(int i =  2 ; i < n ; i++)
        for(int j = 0 ; j <= i ; j++){
            if(i== j) {
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            }
            else if(j == 0){
                dp[i][0] = dp[i-1][0] + arr[i][0]; 
            }

            else {
                if(dp[i-1][j-1] > dp[i-1][j]) dp[i][j] = dp[i-1][j-1] + arr[i][j];
                else dp[i][j] = dp[i-1][j] + arr[i][j];
        }
        }

    for(int i = 0 ; i < n ; i++){
        if(maxCnt < dp[n-1][i]) maxCnt = dp[n-1][i];
    }

    cout << maxCnt;
}