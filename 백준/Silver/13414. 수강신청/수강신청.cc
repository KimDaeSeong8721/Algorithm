#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;


set<pair<int,string>> s ;
unordered_map<string,int> m ;

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
  int k, l ;
  cin >> k >> l ;

    for(int i = 0 ; i < l ; i++) {
        string str ; 
        cin >> str ;
        m[str] = i ;
    }

    for(auto e : m) {
        s.insert(make_pair(e.second,e.first));
    }

    for(auto e: s) {
        if (k == 0) break;
        cout << e.second << '\n';
        k--;
    }
}