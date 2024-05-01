#include <iostream>
#include <algorithm>
using namespace std;

int t , n ;

int day[1'000'001];

int cnt ;
long long totprice ; 
long long result ;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> t ;

    while(t--){
        cin >> n ;
        fill(day,day+n, 0);
        result = 0 ;
        for(int i = 0 ; i < n ; i++){
            cin >> day[i];
        }
        int maxV = day[n-1];
        int cnt = 0 ;
        for(int i = n-2 ; i >= 0 ; i--){
            if(maxV < day[i]) { maxV = day[i] ; continue;}
            result += (maxV-day[i]);
        }

            cout << result<< '\n' ;
    }
 
}