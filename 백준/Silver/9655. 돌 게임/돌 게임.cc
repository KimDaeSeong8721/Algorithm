#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;


int dp[1001];

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int n ; 
    cin >> n ;
    
    dp[1] = -1;
    dp[3] = -1;
    dp[2] = 1;
    for(int i = 4 ; i <= n ; i++) {
            dp[i] = -dp[i-1];

    }
    if(dp[n] == -1) {
        cout << "SK";
    } else {
        cout << "CY";
    }
}