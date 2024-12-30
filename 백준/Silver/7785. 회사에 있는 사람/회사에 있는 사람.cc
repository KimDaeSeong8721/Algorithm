#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;




int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
   int n ; 
   vector<string> v ;
   cin >> n ;
    for(int i = 0 ; i < n ; i++) {
        string a, b ;
        cin >> a >> b ;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(),v.end());
    int i = 0 ; 
    while (i < v.size())
    {
        if (v[i] == v[i+1]) {
            i += 2; 
        } else {
            cout << v[i] << '\n';
            i++;
        }
    }
    
 
}