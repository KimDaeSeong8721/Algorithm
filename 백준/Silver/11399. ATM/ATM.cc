#include <iostream>
#include <algorithm>
using namespace std;


int n ;
int p[1001]; // 1-indexed

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
  
    cin >> n ;
    for(int i = 1; i <= n ; i++)
        cin >> p[i];
    
    sort(p+1,p+n+1);
    int tot = 0 ;
    for(int i = n ; i > 0 ; i--){
        tot += p[n+1-i]*(i);
    }
    cout<< tot ; 
}