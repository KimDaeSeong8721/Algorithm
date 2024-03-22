#include <iostream>
#include <algorithm>

//N과 M (2)
// 조합

using namespace std;

int arr[20];
int n,m ;

void func2(int k, int prev) {
   if(k == m){ // m개를 모두 택했으면
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
    cout << '\n';
    return;
  }

    for(int i = prev + 1; i <= n; i++){ 
      arr[k] = i;  
      func2(k+1, i); // 다음 수를 정하러 한 단계 더 들어감
    
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func2(0,0);
}