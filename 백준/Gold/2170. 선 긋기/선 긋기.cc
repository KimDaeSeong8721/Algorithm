#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int n ; 
vector<pair<long long ,long long>> v ;
long long result ; 

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int st, en ;
        cin >> st >> en ; 
        v.push_back({st,en});
    }
    sort(v.begin(),v.end());

    long long prest = v[0].first;
    long long preen = v[0].second;

    for(int i = 1 ; i < n ; i++){
        long long curst = v[i].first;
        long long curen = v[i].second;

        if(preen <= curst) {
            result += preen - prest ;
            prest = curst ;
            preen = curen;

        } else {
            prest = min(prest, curst);
            preen = max(preen,curen);
        }
    }

    result += preen - prest ;

    cout << result ; 

}