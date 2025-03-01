#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;

typedef long long ll ;

ll dp[5001];

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    string str ;
    cin >> str ;
    // dp[i] 는 i번째까지 나올 수 있는 해석 가짓수.

    // 첫자리수가 0 이면 암호해석 불가 예외 처리.
    // dp[0],dp[1] 초기화
    
    if (str[0] == '0') { cout << 0 ; return 0;} 
       
    dp[0] = 1; 
    dp[1] = 1; 

    // bottom-up 방식 
    for(int i = 2 ; i <= str.length() ; i++) {
        if(str[i-1] != '0') { dp[i] = dp[i-1] % 1000000 ; }
        if(str[i-2] == '1' || str[i-2] == '2' && str[i-1] <= '6') dp[i] = (dp[i] + dp[i-2]) % 1000000;
    }

    cout << dp[str.length()];
    return 0 ;
}