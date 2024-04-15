#include <iostream>
#include <algorithm>
using namespace std;


int arr[100'001] ;
int dp[100'001];
int n ; 
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;
    for(int i = 0 ; i < n ; i++) cin>> arr[i];
    
    dp[0] = arr[0];
    
    for(int i = 1 ; i < n ; i++){
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
    }

    cout << *max_element(dp ,dp + n);
 
}
