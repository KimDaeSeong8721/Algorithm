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
    multiset<int> group ; 
    cin >> n ; 
    while(n--) {
        int h, k ;
        cin >> h >> k ;
        s.insert(make_pair(-h,k));
    }
    while (true)
    {   
        if(s.size() == 0) break;
        auto v = *s.begin();
        s.erase(v);
        auto it = group.lower_bound(-v.second+1) ; // lower_bound는 인자값과 같거나 큰 값의 it 리턴

        if(it == group.end()) {
            group.insert(-1);
        } else {
                int newV = *it - 1 ;
                 group.erase(it);            
                 group.insert(newV);  
        }
    }
    cout << group.size() ;
}