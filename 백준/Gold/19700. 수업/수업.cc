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
        auto it = group.lower_bound(v.second) ; // lower_bound는 인자값과 같거나 큰 값의 it 리턴
        if(it == group.end()) {
            // 1. 없거나 작은 경우.
            if(group.size() == 0) {
            // 없음
            group.insert(1);
            } else {
            // 작음
                int newValue = *prev(it) + 1;  
                 group.erase(prev(it));            
                 group.insert(newValue);  
            }
        } else {
            // 2. 크거나 같은 경우
            if(*prev(it) < v.second && it != group.begin()) {
            // 이전 값이 v.second보다 작은 경우
                int newValue = *prev(it) + 1;  
                 group.erase(prev(it));             
                 group.insert(newValue);  
            } else {
             group.insert(1);
            }
        }
    }
    cout << group.size() ;
}