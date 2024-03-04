
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int arr[51][51];
bool vis[51][51] ;
int m, n ,k , t;
queue<pair<int,int>> q ;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t ; // 테스트 개수

    while(t--) {
        int cnt = 0 ; 

        cin >> m >> n >> k ;
        
        for(int i = 0 ; i < k ; i++) {
            int x, y ;
            cin >> x >> y ;
            arr[x][y] = 1 ;
        }

        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                if(!vis[i][j] && arr[i][j] == 1) {
                    q.push({i,j});
                    vis[i][j] = true;

                    while(!q.empty()) {
                        auto cur = q.front() ; q.pop();

                        int x = cur.first;
                        int y = cur.second;

                        for(int l = 0 ; l < 4 ; l++) {
                            int nx = x + dx[l];
                            int ny = y + dy[l];
                            if(nx >= m || nx < 0 || ny >= n || ny <0) continue;
                            if(vis[nx][ny] == true || arr[nx][ny] == 0) continue;
                            q.push({nx,ny});
                            vis[nx][ny] = true ;
                            
                        }
                    }
                    cnt++;
                }
        cout<< cnt<< '\n' ;

        for(int l = 0 ; l < m ; l++) {
            fill(vis[l],vis[l]+ n, false);
            fill(arr[l],arr[l]+ n, 0);  
        }

    }
    
}

/*
[해결전략 참고]

[배울 점]

[문제 이해]
- 배추 흰지렁이는 인접한 다른 배추로 이동 -> 해충 보호
- 0은 배추가 심어져 있지 않은 땅, 1은 배추가 심어져 있는 땅

[시작]
- 왜 출력이 안되지? ㅜㅜ -> for문 증감연산자 문자를 잘못 씀 ㅋㅋㅋㅋㅋ ㅜ 
    -> 모야 왜 바로 틀리지??
[입력]
- 첫째줄 테스트 케이스 T
- 가로 M, 세로 N, 배추가 심어져 있는 위치의 개수 K
- 그다음 K줄에는 배추의 위치 X, Y

[제약]
- 1<= M <= 50 
- 1<= N <= 50 

- 0 ≤ X ≤ M-1
- 0 ≤ Y ≤ N-1

[출력]
- 최소의 배추흰지렁이 마리 수 

[풀이전략]
- DFS로 for문 돌면서 최소 방문 횟수구하면 됨.
*/
