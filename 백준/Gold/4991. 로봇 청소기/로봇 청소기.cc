#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int w, h ;

char arr[21][21];

pair<int,int> ipos;
pair<int,int> pos ;

int dis[21][21]; 
int minTot = 1e9;
int tot ;
int dpDis[401][401];

pair<int,int> bfs(pair<int,int> st,pair<int,int> en) {
    queue<pair<int,int>> q2 ;

   for(int i = 0 ; i < h ; i++)
        fill(dis[i], dis[i]+ w, -1);
    dis[st.first][st.second] = 0 ;
    q2.push({st.first,st.second});

    while(!q2.empty()){
            auto cur = q2.front(); q2.pop();
            int x = cur.first;
            int y = cur.second;

        for(int i = 0 ; i < 4 ; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= h || nx < 0 || ny >= w || ny < 0) continue;
            if(arr[nx][ny] == 'x') continue;
            if(dis[nx][ny] >= 0) continue;
            dis[nx][ny] = dis[x][y] + 1 ;
            if(nx == en.first && ny == en.second) {
                return {nx,ny};
            }
            q2.push({nx,ny});
        }

        }
    return {-1,-1};
    
}
int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    while(1) {
    minTot = 1e9;
    vector<pair<int,int>> v ;
    cin >> w >> h;
    if(w == 0 && h == 0) break;

    for(int i = 0 ; i < 401 ; i++) {
        fill(dpDis[i],dpDis[i]+401,0);
    }

    for(int i = 0 ; i < h ; i++){
        string s ;
        cin >> s ;
        for(int j = 0 ; j < w ; j++){
            arr[i][j] = s[j];
            if(s[j] == 'o') { ipos = make_pair(i,j); pos = ipos ;}
            if(s[j] == '*') v.push_back({i,j}); 
        }
    }

    do
    {   
        tot = 0 ; 
        pos = ipos ; 

        for(auto c : v) {

            if(dpDis[pos.first*w+pos.second][c.first*w+c.second] == 0){
                auto val = bfs(pos,c);
                if(val.first != -1) {tot += dis[val.first][val.second] ;
                dpDis[pos.first*w+pos.second][c.first*w+c.second] = dis[val.first][val.second] ; 
                dpDis[c.first*w+c.second][pos.first*w+pos.second] = dis[val.first][val.second] ; 
                }
                else { tot = 0 ; break; }
            } else { tot += dpDis[pos.first*w+pos.second][c.first*w+c.second];}

            pos = c ; 
        }     
    if(minTot > tot) minTot = tot ;
    } while (next_permutation(v.begin(),v.end()));
    
    
    if(minTot == 0) minTot = -1;
    cout<< minTot<<'\n' ;
}
}