#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char arr[5][5];
queue<tuple<int,int,int,int>> q;
int result ;

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1}; 

bool brute[25];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    fill(brute+7,brute+25,true); 

    for(int i = 0 ; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }
    
    do {
        queue<pair<int,int>> q ; 
        int tot_cnt = 0;
        int s_cnt = 0;     

        bool ispri[5][5] = {}, visited[5][5] = {};
        for(int i = 0 ; i < 25 ; i++) {
            if(!brute[i]) {
             int x = i / 5 ;
            int y = i % 5 ; 
                ispri[x][y] = true ;
                if(q.empty()) {
                 q.push({x,y});
                visited[x][y] = true ;
                }
            }
        }  

    while (!q.empty())
    {
        auto cur = q.front() ; q.pop();
        int curX = cur.first;
        int curY = cur.second; 

        if(arr[curX][curY] == 'S') s_cnt +=1;
        tot_cnt +=1 ;
        for(int k = 0 ; k < 4  ; k++) {
            int nx = curX + dx[k];
            int ny = curY + dy[k];
            if(nx >= 5 || nx < 0 || ny >= 5 || ny < 0 || visited[nx][ny] || !ispri[nx][ny]) continue;
            
            q.push({nx,ny});
            visited[nx][ny] = true;
        }
    }
    if(tot_cnt  == 7 && s_cnt >=4) result += 1;

    }while (next_permutation(brute,brute+25));
    cout << result; 

}