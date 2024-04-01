#include <iostream>
#include <algorithm>
using namespace std;


// 겹치는 건 싫어.

int n, k ; // 수열의 길이, 중복 최대 개수.

int arr[200'001]; // 수열
int vis[100'001]; // 중복여부 판별.


int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> k ;

    for(int i = 0 ; i < n ; i++) cin >> arr[i];
    
    int st = 0 ;
    int en = st+1 ;
    int maxLen = 0 ;

    vis[arr[st]] = 1;
    while (1)
    {
        if(st >= en) break;
        if(en == n) break;

        vis[arr[en]]++;
        if(vis[arr[en]] > k ) {
            maxLen = max(maxLen,en - st) ;
            while(st != en) {
                vis[arr[st]]--;
                st++;
                if(vis[arr[en]] <= k) {break;}
            }
        } 
        en++;
        
    }
    
    cout << max(maxLen,en-st) ;
    
}

/*
[해결전략 참고]

[시작]
- 4시 38분에 시작

[배울 점]

[문제 이해]
- 같은 원소가 K개 이하 최장 연속 부분 수열 길이
- 10만이하의 양의 정수로 이루어진 길이 N 수열
연속 부분 수열
-> 원소를 하나이상 연속하여 선택한 부분 수열.

3 9 7 6 5 
[입력]
- N, k
- 수열 주어짐
[제약]
- N은 1이상 20만이하,
- K는 1이상 100이하
[출력]
- 같은 정수 K개 이하로 포함한 최장 연속 부분 수열의 길이 구하기.

[풀이전략]
슬라이딩 윈도우? -> 시간초과 예상했지만 정말 시간초과.

*/
