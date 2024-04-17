#include <iostream>
#include <algorithm>
using namespace std;


int n,t ; 
long long  p[101];
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 

    p[1] = 1 ;
    p[2] = 1 ;
    p[3] = 1 ;
    p[4] = 2 ;
    p[5] = 2 ;

    for(int i = 6 ; i <= 100 ; i++) {
        p[i] = p[i-1] + p[i-5];
    }


    cin >> t ;

    while (t--)
    {
        cin >> n ;
        cout << p[n] <<'\n';
    }
    
 
}