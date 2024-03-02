
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

char arr[101][101];
int vis[101][101];
int vis2[101][101];

int n ; 
int cnt1, cnt2; 
queue<pair<int, int>> q ;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ; 
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            cin >> arr[i][j];       // 행렬 입력

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            if(!vis[i][j]) {
                q.push({i,j});
                vis[i][j] = 1 ;
                int curColor = arr[i][j];
                while(!q.empty()) {
                    pair<int,int> curPos = q.front(); q.pop();
                    int curX = curPos.first;
                    int curY = curPos.second;

                    for(int k = 0 ; k < 4 ; k++) {
                        int nx = curX + dx[k];
                        int ny = curY + dy[k];
                        if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
                        if(vis[nx][ny]) continue ;
                        if(arr[nx][ny] == curColor) {
                            q.push({nx,ny});
                            vis[nx][ny] = 1 ;
                        }
                    }
                }
                cnt1++ ; 
            }
    
    cout << cnt1 ;
    for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < n ; j++)
                if(!vis2[i][j]) {
                    q.push({i,j});
                    vis2[i][j] = 1 ;
                    int curColor = arr[i][j];
                    while(!q.empty()) {
                        pair<int,int> curPos = q.front(); q.pop();
                        int curX = curPos.first;
                        int curY = curPos.second;

                        for(int k = 0 ; k < 4 ; k++) {
                            int nx = curX + dx[k];
                            int ny = curY + dy[k];
                            if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
                            if(vis2[nx][ny]) continue ;
                            if(curColor == 'B') {
                                if(arr[nx][ny] == 'B') {
                                     q.push({nx,ny});
                                      vis2[nx][ny] = 1 ;
                                }
                            } else {
                                if(arr[nx][ny] != 'B') {
                                      q.push({nx,ny});
                                        vis2[nx][ny] = 1 ;
                                }
                                }

                            }
                     
                        }
                    cnt2++ ; 
                    }
                
    cout << ' '<< cnt2 ;
}

/*
[해결전략 참고]

[시작]

[배울 점]

[문제 이해]
- RGB 구성
- 구역은 같은 색으로 이루어짐
- 같은 색상이 상하좌우로 인접하면 두 글자는 같은 구역?
- 색상의 차이를 거의 느끼지 못하는 경우도 같은 색상.?
- 적록색약은 빨강과 초록이 same
- 적록색약인 사람과 그렇지 않은 사람이 볼 때 구역의 수 구하기.

[입력]
- 첫째 줄은 N
- 둘째 줄부터 N개의 줄에는 그림 주어짐

[제약]
1 <= N <= 100
[출력]
- 적록색약 아닌 구역의수 적록색약 구역의 수 


[풀이전략]
- 다차원 배열의 순회이므로 BFS 이용

1. 다차원 배열 두번 순회하기
2. 처음에는 RGB 구분해서 순회
3. 두번째는 RG는 동일하게, B와 구분해서 순회


*/