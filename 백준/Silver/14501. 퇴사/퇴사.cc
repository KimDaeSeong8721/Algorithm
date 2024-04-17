#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 100000000;
int t[20];
int p[20];
int d[20];
int n;
int go(int day) {
    if (day == n+1) {
        return 0;
    }
    if (day > n+1) {
        return -inf;
    }
    if (d[day] != -1) {
        return d[day];
    }
    int t1 = go(day+1); // x
    int t2 = p[day] + go(day+t[day]); // o
    d[day] = max(t1,t2);
    return d[day];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
        d[i] = -1;
    }
    cout << go(1) << '\n';
    return 0;
}