#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


int n,m ; 

long long arr[100'001];

unordered_map<long long,int> ma;

int answer ;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m ;

    for(int i = 0 ; i < m ; i++){
        int order ;
        cin >> order ;

        if(order == 1) {
            int idx,x ;
            cin >> idx >> x ;
            if(arr[idx] & (1LL << (x-1))) continue; 
            arr[idx] += (1LL<<(x-1));
        }
        else if(order == 2){
            int idx,x ;
            cin >> idx >> x ;
            if((arr[idx] & (1LL << (x-1))) == 0) continue; 
            arr[idx] -= (1LL<<(x-1));
        }
        else if(order == 3){
            int idx;
            cin >> idx ; 
            arr[idx] = (arr[idx] << 1) ;
            arr[idx] = (arr[idx] & ((1LL << 20)-1)); 
        }
        else if(order == 4) {
            int idx;
            cin >> idx ;
            arr[idx] = (arr[idx] >> 1) ;
        }
    }

    for(int j = 1 ; j <= n ; j++){
            if(ma[arr[j]]) continue;
            ma[arr[j]] = 1 ;
            answer++;
        }
    cout << answer;

}