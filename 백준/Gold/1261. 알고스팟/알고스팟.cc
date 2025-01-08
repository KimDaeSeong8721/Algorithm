
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int arr[101][101];
int d[101][101];
const int INF = 1e9+10;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

priority_queue<pair<int,pair<int,int>>,
                vector<pair<int,pair<int,int>>>,
                greater<pair<int,pair<int,int>>>> pq;


int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    int m, n ;
    cin >> m >> n ;
   for (int i = 0; i < n; i++) {
        string line;
        cin >> line; // 한 줄 입력
        for (int j = 0; j < m; j++) {
            arr[i][j] = line[j] - '0'; // 문자 '0'을 빼서 정수로 변환
        }
    }

for (int i = 0; i < n; i++) {
    fill(d[i], d[i] + m, INF); // 한 행(m개의 열) 초기화
}
d[0][0] = 0 ;

pq.push({0,{0,0}});
while(!pq.empty()) {
    auto cur = pq.top() ; pq.pop();
    if(d[cur.second.first][cur.second.second] != cur.first) continue;
    for(int k = 0 ; k < 4 ; k++) {
        int nx = cur.second.first + dx[k] ;
        int ny = cur.second.second + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
        if(d[nx][ny] <= d[cur.second.first][cur.second.second] + arr[nx][ny]) continue;
        d[nx][ny] = d[cur.second.first][cur.second.second] + arr[nx][ny];
        pq.push({d[nx][ny],{nx,ny}});
    }
}
    cout << d[n-1][m-1] ;
    }