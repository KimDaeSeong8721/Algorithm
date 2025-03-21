
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    int n ; 
    int result = 0 ;
    cin >> n ;
    priority_queue<int, vector<int>, greater<int>> pq ;

    while(n--) {
        int tmp ; 
        cin >> tmp ;
        pq.push(tmp) ;
    }

    while(pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        result += a+b;
        pq.push(a + b) ;
    } 
    cout << result ; 
    return 0 ; 
}