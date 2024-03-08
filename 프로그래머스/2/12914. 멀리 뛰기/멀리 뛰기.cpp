#include <string>
#include <vector>

using namespace std;

long long a[2001];
long long solution(int n) {
    long long answer = 0;
    long long s1  = 0 ; 
    long long s2 = 0 ; 
    a[1] = 1 ;
    a[2] = 2;
    
    if(n == 1) return 1 ;
    else if (n == 2) return 2 ;
    else {
        for(int i = 3 ; i <= n ; i++) {
        a[i] = (a[i-2]  + a[i-1]) % 1234567 ;
        }
    return a[n] ;
        }
}




