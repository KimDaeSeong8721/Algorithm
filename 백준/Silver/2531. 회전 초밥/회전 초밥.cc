#include <iostream>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;

// 회전 초밥 
// 실패
// 실패

int n,d,k,c; // 접시수, 초밥 가짓수, 연속해서 먹는 접시 수, 쿠폰 번호

int arr[30001];
int result = 0 ;
int vis[3001];
deque<int> dq ; 


int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> d >> k >> c ;
    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    
    //슬라이딩 윈도우

    int flag = 0 ;
    for(int i = 0 ; i < k-1 ; i++) {
      dq.push_back(arr[i]);
      if(vis[arr[i]] >= 1) flag++;
      vis[arr[i]]++;
    }


    for(int st = k-1 ; st < n+k ; st++) {

      int coupon = 1 ;

      dq.push_back(arr[st % n]);
      if(vis[arr[st % n]] >= 1) flag++;
      vis[arr[st % n]]++;

      if(vis[c] >= 1) coupon = 0;
      else if (vis[c] == 0) coupon = 1 ;
      
      result = max(result, k - flag + coupon);
      dq.pop_front();
      if(vis[arr[(st-k+1) % n]] > 1) flag--;
      vis[arr[(st-k+1) % n]]--;
      
    }
  cout << result ;
}
