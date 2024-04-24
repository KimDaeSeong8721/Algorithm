#include <iostream>
#include <algorithm>
using namespace std;


int n ;
int s[11] ;
int b[11] ; 

int answer = 1e9; 



int main() {
      ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        cin >> s[i] >> b[i] ;
    }

    for(int tmp = 1 ; tmp < (1 << n) ; tmp++){
        int totS = 1 ; int totB = 0;
        for(int j = 0 ; j < n ; j++){
            if((tmp & (1 << j)) == 0) continue;
            totS *= s[j];
            totB += b[j];
        }
        answer = min(answer,abs(totS - totB));
    }

    cout << answer ; 
}