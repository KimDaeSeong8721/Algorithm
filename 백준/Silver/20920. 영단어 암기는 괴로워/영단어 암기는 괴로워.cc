#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;


unordered_map<string,int> um ;
priority_queue<tuple<int,int,string>, vector<tuple<int,int,string>>, greater<tuple<int,int,string>>> pq ;
int main() { 
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, m ;
    cin >> n  >> m ; 

    while (n--)
    {
        string str ;
        cin >> str ; 
        if(str.length() >= m) {
            um[str]++;
        }
    }

    for(auto item : um ) {
        pq.push(make_tuple(-item.second, -item.first.length(), item.first));
    }

    while(!pq.empty()) {
        auto tuples = pq.top(); pq.pop();
        cout << get<2>(tuples) << '\n'; 
    }
    
    
}