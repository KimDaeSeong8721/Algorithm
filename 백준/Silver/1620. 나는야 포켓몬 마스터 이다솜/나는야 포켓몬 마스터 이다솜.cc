#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cctype>
using namespace std;


int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int n, m ;
    cin >> n >> m ;
    unordered_map<int,string> m1 ;
    unordered_map<string,int> m2 ;

    for(int i = 0 ; i < n ; i++){
        string name ;
        cin >> name ;
        m1[i+1] = name ;
        m2[name] = i+1 ;
    }
    for(int i = 0 ; i < m ; i++) {
        string quiz ;
        cin >> quiz; 

        if(isdigit(quiz[0])) {
            cout << m1[stoi(quiz)] << '\n';
        } else {
            cout << m2[quiz] << '\n';
        }
        
    }
 
}