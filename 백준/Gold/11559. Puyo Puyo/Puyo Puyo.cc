#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

char arr[12][6];
int vis[12][6]; // 0 : 방문 안함  1: 방문함
queue<pair<int,int>> q ;

int tot; 

void updateBlock() {
    // 중력 영향 
    for(int i = 11 ; i >= 0 ; i--)
        for(int j = 0 ; j < 6 ; j++)
            if(arr[i][j] != '.'){
                int x = i ; 
               while(x < 12) {
                if(arr[x+1][j] != '.') break;
                arr[x+1][j] = arr[x][j];
                arr[x][j] = '.';
                x++;
               }
            }      
    for(int i = 0 ; i < 12 ; i++)
        fill(vis[i],vis[i]+ 6, 0); 
}

bool findBlocks(int x,int y) {
    // BFS 이용
    int isused[12][6] ;
    for(int i = 0 ; i < 12 ; i++)
        fill(isused[i],isused[i]+ 6, 0);
    
    int cnt = 1 ;
    q.push({x,y});
    isused[x][y] = 1;

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        int x = cur.first ; int y = cur.second;

        for(int i = 0 ; i < 4 ; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(arr[x][y] == arr[nx][ny]){
                if(nx >= 12 || nx < 0 || ny >= 6 || ny < 0) continue;
                if(isused[nx][ny]) continue;
                isused[nx][ny] = 1;
                cnt++;
                q.push({nx,ny});
            }
        }
    }
    if(cnt >= 4){
        for(int i = 0 ; i < 12 ; i++)
            for(int j = 0 ; j < 6 ; j++)
                if(isused[i][j] == 1) {arr[i][j] = '.' ;}
    return true ;
    }
    return false; 
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    for(int i = 0 ; i < 12 ; i++)
        for(int j = 0 ; j < 6 ; j++)
            cin >> arr[i][j]; 

    while(true) {
        bool isExisted = false ;
    for(int i = 0 ; i < 12 ; i++)
        for(int j = 0 ; j < 6 ; j++)
            if(arr[i][j] != '.'){
                if(vis[i][j]) continue;
                vis[i][j] = 1 ; 
                if(findBlocks(i,j)) isExisted = true ;
            }
    if(isExisted) {
    updateBlock();
    tot++;
    } else { break ;}

    }
    cout << tot ; 
}

/*
[해결전략 참고]

[시작]
- 2024.3.25 3:09 pm ~ 
[배울 점]

[문제 이해]
-뿌요뿌요
- 아래에 바닥이나 다른 뿌요가 나올떄까지 떨어짐.
- 같은 색 뿌요가 4개이상 상하좌우로 연결되어 있으면, 연결된 같은 색 뿌요들이 한꺼번에 없어진다. 이때 1연쇄가 시작됨.
- 없어지고 나서 위에 다른 뿌요들이 있다면, 역시 중력의 영향을 받아 차례로 아래로 떨어짐.
- 아래로 떨어지고 나서 다시 같은 색의 뿌요들이 4개이상 모이게 되면 또 터짐
- 터지 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고 여러 그룹이 터지더라도 한번의 연쇄가 추가 된다.

- . : 빈공간, R G B P Y 
[입력]
- 12개 줄에 필드 정보 // 각 줄에는 6개의 문자
- 입력으로 주어지는 필드에 뿌요 아래에 빈칸인 경우는 없음.

[제약]
-여러 그룹 동시에 터져도 한번의 연쇄가 추가됨.
[출력]
- 현재 주어진 상황에서 몇연쇄가 되는지 출력한다. 하나도 터지지 않는다면 0 출력

[풀이전략]
BFS 이용할 것 

1. 여러 그룹이 터지는 것을 한번의 연쇄로 어떻게 구현?
- 특정 배열에 그룹터지는 것들 다 체크한 후 한번에 업데이트 하기.
*/
