#include <iostream>
#include <algorithm>
using namespace std;


// 겹치는 건 싫어.
// 다시 풀어보기 .
int n, k ; // 수열의 길이, 중복 최대 개수.

int arr[200'001]; // 수열
int vis[100'001]; // 중복여부 판별.
int result ;

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> k ;

    for(int i = 0 ; i < n ; i++) cin >> arr[i];

    int en = 0 ;
    for(int st = 0 ; st < n-1 ; st++){
       
        while(en < n) {
        if(vis[arr[en]] == k) break;
            vis[arr[en]]++ ;
            en++;
        }
        result = max(result,en - st);
        vis[arr[st]]--;
    }
    cout << result ; 
}