
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;




int dx[8] = {1,-1,0,0,1,1,-1,-1};
int dy[8] = {0,0,1,-1,1,-1,1,-1};

int arr[51][51];
int vis[51][51];

queue<pair<int,int>> q ; 

int w,h ;
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    while(1){
        int cnt = 0 ; 

        cin >> w >> h ;
        if(w == 0 && h == 0) break; 

    for(int i = 0 ; i < h ; i++) {
        for(int j = 0 ; j < w ; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0 ; i < h ; i++)
        fill(vis[i],vis[i]+w, 0);

     for(int i = 0 ; i < h ; i++) 
        for(int j = 0 ; j < w ; j++) {
            if(!vis[i][j] && arr[i][j]) {
                q.push({i,j});
                vis[i][j] = 1;

                while(!q.empty()) {
                    auto cur = q.front(); q.pop();

                    int x = cur.first; int y = cur.second ;

                    for (int k = 0; k < 8; k++) 
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx >=50 || nx <0 || ny >= 50 || ny <0) continue;
                        if(vis[nx][ny]) continue;
                        if(!arr[nx][ny]) continue;
                        q.push({nx,ny});
                        vis[nx][ny] = 1 ;

                    }
                    
                }
                cnt++;
            }
        }
    
        cout<<cnt << '\n';
    }
}

/*
[해결전략 참고]

[시작]

[배울 점]

[문제 이해]
- 바다로 둘러싸여 있음
- 지도 밖으로 나갈 수 없음 
- 1은 땅, 0은 바다

[입력]
- 너비 w 높이 h
[제약]
1<=w,h <= 50
[출력]


[풀이전략]
- BFS 

*/
