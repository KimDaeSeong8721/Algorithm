#include <iostream>
#include <algorithm>
using namespace std;



int n , m ;
long long gitar[11];
int gitar_cnt ;
int answer = 100 ; 
long long maxTot ; 

void backTracking(int cnt, long long tot) {
    if(cnt == n){
        if(maxTot <= tot) {
            maxTot = tot ;
             answer = min(answer, gitar_cnt);
        }
        return;
    }
        // 현재 기타 포함
        gitar_cnt += 1;
        backTracking(cnt+1, tot | gitar[cnt]);
        gitar_cnt -= 1 ;
        //현재 기타 포함x 
        backTracking(cnt+1, tot);
}
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m ;
    
    for(int i = 0 ; i < n ; i++){
        string g; string s;
        cin >> g >> s ; 
        long tot = 0;
        for(int j = 0 ; j < m ; j++){
            if(s[j] == 'Y') tot += (1LL << j); 
        }
        gitar[i] = tot ; 
    }
    backTracking(0, 0); 
    if(answer == 0) answer = -1;
    cout << answer ; 
}