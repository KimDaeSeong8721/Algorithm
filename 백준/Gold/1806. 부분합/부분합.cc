#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n , s ;
int arr[100'001] ; 

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int res = 1'000'000'000; 
    cin >> n >> s ;

    for(int i = 0 ; i < n ; i++) cin >> arr[i]; 
    int tot = arr[0] ; 
    int en = 0 ; 
    for(int st = 0 ; st < n ; st++) {
        while(tot < s && en + 1 < n) { tot += arr[++en] ; }  
        
        if(tot < s) continue;
        res = min(res,en - st+1) ; 
        tot -= arr[st];
    }
    if(res == 1'000'000'000) res = 0 ; 
    cout << res ; 
 
}