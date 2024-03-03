
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};

int arr[102][102][102];
int vis[102][102][102];
queue<tuple<int,int,int,int>> q ;
int m,n,h ;
int maxCnt ;
int cnt,emptyCount ; 
int totalSum;  

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    
  cin >> m >> n >> h ; 
  for(int i = 0 ; i < h ; i++)
    for(int j = 0 ; j < n ; j++)
      for(int k = 0 ; k < m ; k++)
          cin >> arr[i][j][k] ;
  
  for(int i = 0 ; i < h ; i++)
    for(int j = 0 ; j < n ; j++)
      for(int k = 0 ; k < m ; k++) {
        if(arr[i][j][k] == -1) emptyCount++;
        if(arr[i][j][k] == 1) {
         q.push(make_tuple(0,i,j,k));
          vis[i][j][k] = 1 ; 
        }
      }
  while (!q.empty())
  {
    tuple<int,int,int,int> cur = q.front() ; q.pop();
            int x = get<3>(cur);
            int y = get<2>(cur);
            int z = get<1> (cur);
            cnt = get<0>(cur);

            for(int t = 0 ; t < 6 ; t++) {
            int nx = x + dx[t];
            int ny = y + dy[t];
            int nz = z + dz[t];
            if(nx >= m || nx < 0 || ny >= n || ny < 0 || nz >= h || nz < 0) continue ;
            if(vis[nz][ny][nx]) continue;
            if(arr[nz][ny][nx] == 1 || arr[nz][ny][nx] == -1) continue;

              q.push(make_tuple(cnt+1,nz,ny,nx));
              vis[nz][ny][nx] = 1 ;
              arr[nz][ny][nx] = 1 ;   
            
            }
  }
        

  for(int i = 0 ; i < h ; i++)
    for(int j = 0 ; j < n ; j++)
      for(int k = 0 ; k < m ; k++)
          if(arr[i][j][k] == 1) 
            totalSum += arr[i][j][k] ;
  


  if(totalSum == m*n*h - emptyCount) {
    if(cnt == 0) cout << 0;
    else cout << cnt ;
  } else {
    cout << -1 ;
  }
}

/*
[배울 점]

[시작] 
- 1. 실패 -> 여러 익은 토마도가 동시에 진행되어야 하는데 첫번째 익은 토마토 먼저 진행하고 그거의 최대일 수로 계산하는 실수범함
- 2. 헤맴 -> for문 괄호 위치 잘못 ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ
[문제 이해]
- 잘익은 토마토와 그렇지 않은 토마토
- 하루지나면 안 익은 토마토가 인접한 잘 익은 토마토의 영향을 받음
- 인접 -> 여섯 방향
- 토마토들이 다 익는 데 최소 일 수.
- 익은 토마도 ->1 익지 않은 토마토 -> 0 , 빈칸 -> -1 

[입력]
- 첫 줄은 M- 가로, N - 세로 , H - 높이 
- N개의 줄은 가로 줄에 들어 있는 M개의 토마토 
- H번 반복

[제약]
- 저절로 익는 토마토는 없음.
- 2<= M,N,H <= 100 

[출력]
- 토마토 모두 익을 때까지 걸리는 최소 일 수
- 처음부터 모두 익어있으면 출력 0 
- 모두 익지 못하는 상황이면 -1 

[풀이전략]
실패
- 반복문을 돌면서 1을 찾는다.
- 1에 인접한 부분에 0을 찾는다. bfs를 돌면서 cnt를 센다
- 위를 반복하면서 cnt가 가장 큰 거를 따로 빼둔다.
- for문의 모든 합이 배열의 크기랑 같으면 모두 익은거 , 그렇지 않으면 덜 익은거 -> -1, 0이면 안 익은거 -> 0
다시
- for문을 돌면서 1을 다 큐에 넣어버린다. 넣을 때 날짜도 포함시켜버리기.
[해결전략 참고]

*/
