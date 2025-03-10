#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;




string s ;
string t ; 
bool result ;
void backtracking(string str) {
    if(result) return ;
    if(str.length() <= s.length() ) {
        if(str == s) result = true;
        return;
    }

    if(str.back() == 'A') {
        string tmp = str ; 
        tmp.pop_back();
        backtracking(tmp); 
    }
    string tmpStr = str ;
    reverse(tmpStr.begin(),tmpStr.end());
    if(tmpStr.back() == 'B') {
        tmpStr.pop_back();
        backtracking(tmpStr);
    }
    
}


int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> s >> t ; 
    backtracking(t);
    cout << result ; 
}
