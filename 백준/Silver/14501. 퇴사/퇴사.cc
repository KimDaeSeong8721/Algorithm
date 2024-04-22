#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int n ; 
int d[16];
int t[16];
int p[16];

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;
    
    for(int i = 0 ; i < n ; i++){
        int a; int b ;
        cin >> a >> b;
        t[i] = a ;
        p[i] = b ;
    }

    for(int i = n-1 ; i >= 0 ; i--) {
        if(i + t[i] <= n) {
            d[i] = max(d[i+t[i]]+p[i], d[i+1]);
        }
        else d[i] = d[i+1];
      
    }
    cout << *max_element(d,d+n);
}