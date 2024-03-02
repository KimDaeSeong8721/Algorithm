

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

# define X first 
# define Y second

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int r,c ; 
char arr[1001][1001];
int fir[1001][1001];
int jih[1001][1001];
pair<int,int> tempPos ; 
pair<int, int> jPos; 
queue<pair<int, int> > q ;
int cnt = 1000000;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> r >> c ;       // r, c 입력
    for(int i = 0 ; i < r ; i++)
        for(int j = 0 ; j < c ; j++)
            cin >> arr[i][j];       // 행렬 입력

    for(int i = 0 ; i < r ; i++) {
        for(int j = 0 ; j < c ; j++)  {
            if(arr[i][j] == 'J') {    // 지훈 좌표 저장
                jPos = make_pair(i,j);
            }
            else if (arr[i][j] == 'F') {   // 불 발견시 큐에 삽입
                q.push(make_pair(i,j));

                while(!q.empty()) {
                  tempPos = q.front();
                  q.pop();
                  int x = tempPos.X ;
                  int y = tempPos.Y ;

                  for(int k = 0 ; k < 4 ; k++) {
                    int nx = x + dx[k] ;
                    int ny = y + dy[k] ;
                      if(nx >= r || nx < 0 || ny >= c || ny < 0 ) continue;
                      if(arr[nx][ny] == 'F' || arr[nx][ny] == '#') continue;
                      if(fir[nx][ny] == 0 || fir[nx][ny] > fir[x][y] + 1) {
                        fir[nx][ny] = fir[x][y] + 1 ;

                        q.push(make_pair(nx,ny));
                      } 
                  }
                }
            }
        }
    }

      q.push(jPos);
            while (!q.empty())
            {
               tempPos = q.front();
                  q.pop();
                  int x = tempPos.X ;
                  int y = tempPos.Y ;
                  if(x == r-1 || x == 0 || y == c-1 || y ==0) {
                          if(cnt > jih[x][y]) cnt = jih[x][y];
                        } 
                   for(int k = 0 ; k < 4 ; k++) {
                    int nx = x + dx[k] ;
                    int ny = y + dy[k] ;
                    if(nx >= r || nx < 0 || ny >= c || ny < 0 ) continue;
                    if(arr[nx][ny] == '.' && jih[nx][ny] == 0 && (fir[nx][ny] == 0 || fir[nx][ny] > jih[x][y] + 1 )) {
                        q.push(make_pair(nx,ny));
                        jih[nx][ny] = jih[x][y] + 1 ;
                        
                    }
                  

                   }
            }

        if(cnt != 1000000) {
          cout << cnt+1 ;
        }
        else {
          if( jPos.X == 0 || jPos.X == r-1 || jPos.Y ==0 || jPos.Y == c-1) cout << 1 ;
          else cout << "IMPOSSIBLE" ; 
        }
}

/*
[해결전략 참고]

[시작]
1. 실패 -> 지훈이를 옮기는 과정에서 cnt 문제 .

[배울 점]

[문제 이해]
- 지훈이의 위치와 불이 붙은 위치 주어짐.
- 지훈이는 불이 타기전에 탈출가능 여부, 그리고 얼마나 빨리 탈출할 수 있는지 결정
- 지훈, 불 둘 다 매분 한칸씩 수평 또는 수직 이동
- 불은 각 지점 네 방향으로 확산
- #: 벽 ,, .: 패스공간, J: 지훈이 초기 위치, F: 불 초기위치 

[입력]
- 1줄은 정수 R, C -> R은 행개수 C는 열 개수
- R줄동안 미로의 행이 주어진다.
[제약]
- 1<= R,C <= 1000
- j는 입력 하나만 주어짐
- 지훈이는 미로의 가장자리에 접한 공간에서 탈출가능
- 벽통과 x

[출력]
- 지훈이가 불이 도달하기 전에 미로를 탈출할 수 없는 경우 IMPOSSBIBLE 출력
- 탈출가능한 경우 가장 빠른 탈출시간 출력

[풀이전략]
1. 모든 칸의 불이 도착하는 시간을 구한다. -> BFS 활용
2. 지훈이가 칸을 방문하면서 시간을 체크할 때 불이 도착하는 시간보다 적을 때 통과
3. 지훈이의 위치가 가장자리이기고 그 위치가 지나갈 수 있는 공간이면 탈출 성공 그외 IMPOSSIBLE

*/
