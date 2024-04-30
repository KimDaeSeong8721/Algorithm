#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


vector<int> v1 ; 
vector<int> v2 ; 

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 

    string s ;
    cin >> s ;
    s.push_back('@');
    string tmp = "";
    bool flag = false ;
    for(auto c : s) {
        if(c-'0' < 0 || c-'0' > 9 ){
            if(!flag){
                v1.push_back(stoi(tmp));
            }
            else {
                v2.push_back(stoi(tmp));
            }
            tmp = "" ;
            if(c == '-') flag = true; 
        }
        else {
        tmp.push_back(c);
        }
    }
    int tot1 = 0 ;
    int tot2 = 0 ;
    for(auto e : v1){
        tot1 += e ;
    }

    for(auto e: v2) {
        tot2 += e ;
    }

    cout << tot1 - tot2 ; 
}