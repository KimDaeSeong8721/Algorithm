#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// 뱀

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int n , k , l;
int d  ; // 0- 동 1- 남 2- 서 3-북
int arr[101][101];
char dir[10001];
int prevx, prevy ; 
// int tailx, taily ; 
int result ; 
// int dirvis[101][101];
queue<pair<int,int>> q;

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> k;

    fill(dir,dir+10001,'-');

    for(int i = 0 ; i < k ; i++) {
        int x; int y ;
        cin >> x >> y ;
        arr[x-1][y-1] = 1 ;
    }
    cin >> l ;
    
    while (l--)
    {
      int x ; char c ;
      cin >> x >> c;
      dir[x] = c ;
    }

    arr[0][0] = 2 ;
    q.push({0,0});
      int cnt = 0 ;

      while(1){
      int curx = prevx + dx[d];
      int cury = prevy + dy[d];
      // dirvis[prevx][prevy] = d ;

       if(curx >= n || curx < 0 || cury >= n || cury < 0) break;// 벽 만났을 때
      if(arr[curx][cury] == 2)  break;   // 뱀의 몸 만났을 때


      if(arr[curx][cury] == 0) { // 사과가 존재하지 않으면 꼬리 삭제.
        arr[q.front().first][q.front().second] = 0 ;
        q.pop();
        // tailx += dx[dirvis[tailx][taily]];
        // taily += dy[dirvis[tailx][taily]]; // 주의 다시보기.
      }

      arr[curx][cury] = 2 ;
      q.push({curx,cury});

      prevx = curx;
      prevy = cury ;
      cnt++; 

      if(dir[cnt] == 'L')  d = (d+3) % 4 ;
      else if(dir[cnt] == 'D') d = (d+1) % 4; 

      }
    cout << cnt+1 ; 

}