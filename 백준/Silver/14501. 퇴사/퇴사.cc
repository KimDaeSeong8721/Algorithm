#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int t[16];
int p[16];
int tempTot;
int maxTot;
int n;
void dfs(int cnt) {
  if (cnt == n) {
    maxTot = max(tempTot, maxTot);
    // tempTot = 0 ;
    return;
  }
  if (t[cnt] + cnt < n) {
    tempTot += p[cnt];
    dfs(cnt + t[cnt] + 1);
    tempTot -= p[cnt];
  } 
  dfs(cnt + 1);

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    int b;
    cin >> a >> b;
    t[i] = a - 1;
    p[i] = b;
  }

  for (int i = 0; i < n; i++) {
    dfs(i);
  }

  cout << maxTot;
}