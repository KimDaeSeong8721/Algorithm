#include <iostream>
#include <algorithm>

//N과 M (2)
// 조합

using namespace std;

int arr[20];
int isused[20];
int n,m ;


void func2(int k, int prev) {
   if(k == m){ // m개를 모두 택했으면
    for(int i = 0; i < m; i++)
      cout << arr[i] << ' '; // arr에 기록해둔 수를 출력
    cout << '\n';
    return;
  }

    for(int i = prev + 1; i <= n; i++){ 
    if(isused[i]) continue;
      arr[k] = i;  
      isused[i] = 1; // i를 사용되었다고 표시
      func2(k+1, i); // 다음 수를 정하러 한 단계 더 들어감
      isused[i] = 0; // k번째 수를 i로 정한 모든 경우에 대해 다 확인했으니 i를 이제 사용되지않았다고 명시함.
    
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    func2(0,0);
}