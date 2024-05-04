#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n ; 

int monv[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31} ;
int totD[13] ; 

int st;
int en;
int result;

int v[366] ;



int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 

    for(int i = 2 ; i <= 12 ; i++){
        totD[i] = totD[i-1]+monv[i-1]; 
    }
    st = totD[3] + 1;
    en = totD[11] + 30;

    cin >> n ;
    for(int i = 0 ; i < n ; i ++){
        int stm,std, enm,end ; 
        cin >> stm >> std >> enm >> end ;
        if(v[totD[stm]+std] != 0) v[totD[stm]+std] = max(v[totD[stm]+std],totD[enm]+end);
        else { v[totD[stm]+std] = totD[enm]+end;}
    }


    int nxt = st ;
    int tmp = 0 ;
    for(int cnt = 1 ; cnt <= 365 ; cnt++){
        if(v[cnt] != 0 && v[cnt] < nxt) { ;continue;}
        tmp = max(tmp, v[cnt]);
        if(cnt == nxt) {
            nxt = tmp ; 
            result++;
        }
        if(nxt > en) break ;  // 11월 30일을 넘어가면 멈춤

        }
    if(nxt <= en) result = 0 ;
        
    cout << result ;
}