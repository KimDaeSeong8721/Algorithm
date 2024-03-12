
#include <iostream>
#include <algorithm>
using namespace std;

#include <queue>

// 불

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int fir[1001][1001];
int dis[1001][1001];
char arr[1001][1001];
int t,w,h;



int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    
    cin >> t ; 

    while(t--){
      queue<pair<int,int>> q1 ;
      queue<pair<int,int>> q2 ;
      int result = 0; 
      cin >> w >> h ;
      for(int i = 0 ; i < h ; i++){
        fill(fir[i],fir[i]+w,-1);
        fill(dis[i],dis[i]+w,-1);
      }

      for(int i = 0 ; i < h ; i++){
        for(int j = 0 ; j < w ; j++){
          cin >> arr[i][j];
          if(arr[i][j] == '*') {q1.push({i,j});
            fir[i][j] = 0 ;
          }
          else if(arr[i][j] == '@') {q2.push({i,j});
            dis[i][j] = 0 ;
          }
        }
        }

      // 불 경로 구하기
      while (!q1.empty())
      {
        auto cur = q1.front(); q1.pop();
        int x = cur.first ; int y = cur.second;
        
        for(int k = 0 ; k < 4 ; k++){
          int nx = x + dx[k];
          int ny = y + dy[k];
          if(nx >= h || nx < 0 || ny >=w || ny < 0) continue;
          if(arr[nx][ny] == '#') continue;
          if(fir[nx][ny] >= 0) continue;

          fir[nx][ny] = fir[x][y] + 1 ; 
          q1.push({nx,ny});
        }
      }
      
    // 상근이 경로 구하기
    while (!q2.empty())
    {     
         auto cur = q2.front(); q2.pop();
         int x = cur.first ; int y = cur.second;
          if(x == h-1 || x == 0 || y == w-1 || y == 0) {
            result = dis[x][y]+1 ;
            break; 
          }
          for(int k = 0 ; k < 4 ; k++){
          int nx = x + dx[k];
          int ny = y + dy[k];
          if(nx >= h || nx < 0 || ny >=w || ny < 0) continue;
          if(dis[nx][ny] >= 0) continue;
          if(arr[nx][ny]== '.' && (fir[nx][ny] == -1 ||fir[nx][ny] > dis[x][y] + 1)){
              dis[nx][ny] = dis[x][y] + 1 ;
              q2.push({nx,ny});
          }
                }
    }

    if(!result) {
                cout << "IMPOSSIBLE"<<'\n' ;
    } else {
            cout << result<<'\n' ; 

    }

    }
}

/*
[해결전략 참고]
https://www.acmicpc.net/board/view/127674
[시작]
24.3.12.오후3시 49분 -> fir == -1 인 경우 -> 이 조건 빼먹어서 고생 5시 36분

[배울 점]
fir == -1 인 경우 -> 이 조건 빼먹어서 고생
[문제 이해]
- 매 초마다 불은 동서남북방향으로 인접합 빈공간으로 퍼져나감.
- 상근이 동서남북 이동가능. 1초걸림. 불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동 불가
- 상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸 이동가능
- . : 빈 공간 , # : 벽 , @ : 상근이의 시작 위치 , *: 불

[입력]
- 첫째줄은 테스트 케이스의 개수 
- 각 테케 첫줄은 w,h 주어짐.
- 다음 h개 줄에는 w개의 문자,빌딩의 지도가 주어진다.

[제약]
- 테케 최대 100개
- 각 지도에 @의 개수는 하나.
- 1<= w,h <= 1000 

[출력]
각 테스트 케이스마다 빌딩 탈출하는데 가장 빠른 시간을 출력
탈출불가는 IMPOSSIBLE

[풀이전략]
- 불의 위치들 파악, 상근이의 위치 파악.
- 불의 추적 히스토리 배열을 만든다. -> BFS
- 상근이의 이동경로를 BFS로 돌면서 불의 히스토리와 비교하면서 이동한다.
  - nx >= h || nx <0 || ny >= w || ny < 0 
  - '.'인 경우만
  - dis <0 인 경우만
  - fir > dis 경우만
  - fir == -1 인 경우 -> 이 조건 빼먹어서 고생
  - x == h-1 || x == 0 || y == w-1 || y == 0 -> 나오면 cout << 때리셈
- 그 외는 impossible.


*/
