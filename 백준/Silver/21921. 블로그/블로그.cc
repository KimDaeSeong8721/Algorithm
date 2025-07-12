#include <iostream>
#include <algorithm>
#include <set>
#include <map>
using namespace std;



int arr[250'001];
int result ; 
map<int,int> m; 
int n, x ; 
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> x ; 
    
    for(int i = 0 ; i < n ; i++) {
        cin >> arr[i];
        if(i < x) result += arr[i];
    }
    m[result] += 1; 
    
    for(int i = 0 ; i <= n - x ; i++) {
        result -= arr[i];
        result += arr[i+x];
        m[result] += 1 ; 
    }
    int key = m.rbegin()->first ;
    int val = m.rbegin()->second ;
    
    if(key == 0) {
    cout << "SAD" ;
    } else {
    cout << key << '\n' << val; 
    }
}