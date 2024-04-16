#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


//Gaaaaaaaaaarden


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n, m ;
int g, r; 
int arr[51][51]; // R - 3 G-4 W-1

int tot ; 

int col[3];
vector<pair<int,int>> v; 
queue<tuple<int,int,int>> q ;  // x, y, time

void bactracking(int cnt) {
    if(cnt == v.size()) {
        int flowerCnt = 0 ;
        //여기서 이제 시작     
        // bfs    
        int vis[51][51];
        int t[51][51];
           for(int i = 0 ; i < n ; i++){
                fill(vis[i],vis[i]+ m , 0);
                fill(t[i],t[i]+ m , 0);
           }

        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++){
                if(arr[i][j] == 0) vis[i][j] = 1 ; 
            }

        for(auto c : v) {
            if(arr[c.first][c.second] == 3 || arr[c.first][c.second] == 4){ 
                vis[c.first][c.second] = arr[c.first][c.second] ;
            q.push({c.first, c.second,0});
            }

        }

            while (!q.empty())
            {
                auto cur = q.front(); q.pop();
                int x,y,tm ;
                tie(x,y,tm) = cur;
                
                if(vis[x][y] == 7) continue;
                for(int i = 0 ; i < 4 ; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx >= n || nx < 0 || ny >= m || ny < 0) continue; // 경계 조건
                    if(vis[nx][ny] == 1 ) continue; // 호수 

                    if(vis[nx][ny] == 0){
                         vis[nx][ny] = vis[x][y];
                            q.push({nx,ny,tm+1}) ;
                            t[nx][ny] = tm+1;
                    } 
                    else if(vis[nx][ny] == 4){
                        if(vis[x][y] == 3 && t[nx][ny] == tm+1){
                            flowerCnt++;
                            vis[nx][ny] = 7 ;

                        }
                    } else if(vis[nx][ny] == 3){
                        if(vis[x][y] ==4 && t[nx][ny] == tm+1){
                            flowerCnt++;
                            vis[nx][ny] = 7 ;

                        }
                    }
                    
                }
            }

            tot = max(tot,flowerCnt) ;
        
    

        // vis 초기화 ;
     
        return;
        }


    for(int i = 0 ; i < 3 ; i++) {
        if(col[i] == 0) continue;
        col[i]--;
        if(i == 0) arr[v[cnt].first][v[cnt].second] = 4; // green
        else if(i == 1) arr[v[cnt].first][v[cnt].second] = 3 ; // red
        else  arr[v[cnt].first][v[cnt].second] = 2 ; // 빈공간.
        bactracking(cnt+1);
        col[i]++;
        arr[v[cnt].first][v[cnt].second] = 2 ; 
        
    }
}
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m >> g >> r ;

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 2) v.push_back({i,j});
        }
    col[0] = g;
    col[1] = r;
    col[2] = v.size() - g - r ;
    bactracking(0);
    cout << tot ;
}