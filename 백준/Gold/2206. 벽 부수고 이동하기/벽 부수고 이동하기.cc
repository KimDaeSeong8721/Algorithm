
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n, m;
char arr[1001][1001];
int dis[1001][1001][2];

queue<tuple<int,int,int>> q ;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> n >> m ;
    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> arr[i][j];
    q.push({0,0,0});
    dis[0][0][0] = 1; 
    while (!q.empty())
    {  
        auto cur = q.front() ; q.pop();
        int x, y; bool isCrashed ; 
        tie(x,y,isCrashed) = cur ;


        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i] ;
            int ny = y + dy[i] ;
            if(nx >= n || nx < 0 || ny >= m || ny < 0 ) continue;
            if(arr[nx][ny] == '0') {
                if(isCrashed) {
                    //벽 부수고 옴
                    if(dis[nx][ny][1] >= 1) continue;
                      q.push(make_tuple(nx,ny,1));
                        dis[nx][ny][1] = dis[x][y][1] + 1;

                } else {
                    // 벽 안부수고 옴
                    if(dis[nx][ny][0] >= 1) continue;
                      q.push(make_tuple(nx,ny,0));
                        dis[nx][ny][0] = dis[x][y][0] + 1;
                }      
               
            } else {
                if(isCrashed) continue;
                q.push(make_tuple(nx,ny,1));
                dis[nx][ny][1] = dis[x][y][0] + 1 ;
            }
        }
        
    }
  

    if(dis[n-1][m-1][0] + dis[n-1][m-1][1] == 0 ) cout << -1 ;
    else if(min(dis[n-1][m-1][0],dis[n-1][m-1][1]) != 0) cout << min(dis[n-1][m-1][0],dis[n-1][m-1][1]);
    else cout << max(dis[n-1][m-1][0],dis[n-1][m-1][1]);
    
}

/*
[해결전략 참고]
https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x09/solutions/2206.cpp
[시작]
- 3.13.수.오후 3:52 ~ 6: 12 못품

[배울 점]

[문제 이해]
- NxM행렬
- 0은 이동가능 곳, 1은 벽 
- (1,1)에서 출발하여 (N,M)으로 최단 경로로 이동
- 벽 1번 부술 수 있는 기회 드림
[입력]
- 첫 줄은 N, M이 주어진다.

[제약]
- 1<= N, M <= 1000 이 주어진다.
- N개의 줄에 M개의 숫자로 맵이 주어짐.
- 1,1 과 N,M은 항상 0이라 가정
- 시작 칸과 끝나는 칸도 경로에 포함시킨다.
[출력]
- 첫째 줄에 최단거리 출력
- 불가능하면 -1 

[풀이전략]
최단 경로 -> BFS 탐색
벽 부수는 경우도 고려 -> 백트래킹?
벽을 한번 부쉈다는 것을 어떻게 코드로 표현하지?
q에 벽돌 부순 여부도 넣어버리자.
 1. (1,1) -> (0,0) // (N,M) -> (N-1,M-1)로 간주
 2. q를 넣을 때 x,y,벽돌부순여부 이렇게 넣기.
 3.
 - 맵 경계 체크
 - dis가 1이상이면 방문했다는 의미이므로 통과
 - arr가 0이면 q에 넣고 dis 저장, arr가 1이면 벽부순여부 확인-> 존재 통과불가 // 아니면 통과 가능
 4. dis[n-1][m-1]이 0이 아니면 값 출력 0이면 -1 출력

 틀림 -> 1을 통과하고난 뒤의 0과 0들을 통과하고 난 다음 동일한 0에 도달했을 때 둘을 모두 저장? 둘중하나 버려?
 음 dis[n-1][m-1]이 0이라면 늦어도 통과해버리기 어떄

 해결전략 참고
 - dis를 3차원 배열로 두자.
*/
