#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;




int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
  int n ; 
  set<pair<int,int>> s ;
  unordered_map<int,int> um;
    cin >> n ;
  while(n--) {
    int p, l ;
    cin >> p >> l ; 
    s.insert(make_pair(l,p));
    um[p] = l ;
  }

  int m ; 
  cin >> m ;
  while (m--)
  {
    string str;
    cin >> str ;
    if(str == "add") {
      int p, l ;
      cin >> p >> l ;
      s.insert(make_pair(l,p));
      um[p] = l ;
    } else if(str == "recommend") {
      int x ;
      cin >> x;

      if(x == 1) {
        cout << (*prev(s.end())).second << '\n';
      } else {
        cout << (*s.begin()).second << '\n';
      }
    } else {
      int p ;
      cin >> p;
      s.erase(make_pair(um[p],p));
    }
  }
}