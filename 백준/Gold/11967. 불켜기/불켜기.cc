#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;


int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int n , m ; 
int arr[101][101];
int fir[101][101];  // -1 : 불꺼짐 , 0 : 불켜짐 , 1 : 불 켜진 곳 방문함.

vector<pair<int,int>> v[101][101]; // 0-indexed

queue<pair<int,int>> q ; 
int cnt ; 


bool findConnect(pair<int,int> cur){
       int x = cur.first;
        int y = cur.second;

     for(int k = 0 ; k < 4 ; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
                    if(fir[nx][ny] == 1) return 1 ;
            }
            return 0 ;
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    
    //입력
    cin >> n >> m ; 
    for(int i = 0 ; i < m ; i++)
            {   int x ; int  y ; int a ; int b ;
                cin >> x >> y >> a >> b ;
                v[x-1][y-1].push_back({a-1,b-1});
            }

    for(int i = 0 ; i < n ; i++) fill(fir[i],fir[i]+n,-1);
    
    fir[0][0] = 1 ; 
    // cnt++;
    q.push({0,0});

    while (!q.empty())
    {
        auto cur = q.front() ; q.pop();
        int x = cur.first;
        int y = cur.second;
        
            for(auto c : v[x][y]){
                if(fir[c.first][c.second] < 0) {
                    // cnt++;
                    fir[c.first][c.second] = 0 ;
                    if(findConnect(c)) {q.push({c.first,c.second});
                        fir[c.first][c.second] = 1 ;
                    
                    }
                    }
                 }

            for(int k = 0 ; k < 4 ; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx >= n || nx < 0 || ny >= n || ny < 0) continue;
                    if(abs(fir[nx][ny]) == 1) continue;
                    fir[nx][ny] = 1;
                    q.push({nx,ny});
            }
            
    }

    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            if(fir[i][j] >= 0) cnt++;
    

    cout <<cnt; 

}