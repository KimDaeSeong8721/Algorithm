#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

int n,m;

int arr[2001];
int dp[2001][2001]; // 홀수
int dpeven[2001][2001]; // 짝수
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;
    
    for(int i = 1 ; i <= n ; i++) cin >> arr[i];

    for(int i = 1 ; i <= n ; i++){
        dp[i][0] = 1;
        for(int j = 1 ; j < i ; j++) {
            if(arr[i-j] != arr[i+j]) continue;
            if(dp[i][j-1] == 0) continue;
            dp[i][j] = 1 ;  
        }
    }

    for(int i = 1 ; i <= n ; i++){
        if(arr[i] == arr[i+1]) {
            dpeven[i][0] = 1;
        }
        for(int j = 1 ; j < i ; j++) {
            if(i+j+1 > n) continue;
            if(arr[i-j] != arr[i+j+1]) continue;
            if(dpeven[i][j-1] == 0) continue;
            dpeven[i][j] = 1 ;  
        }
    }

    cin >> m ;
    
    for(int i = 0 ; i < m ; i++){
        int s,e ;
        cin >> s >> e ;
        if((e-s) % 2 == 0) {
            cout << dp[(e+s)/2][(e-s)/2]<<'\n';
        } else {
             cout << dpeven[(e+s)/2][(e-s)/2]<<'\n';
        }
    }
    
}