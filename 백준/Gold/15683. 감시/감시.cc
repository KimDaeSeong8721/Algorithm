
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


 
vector<pair<int,pair<int,int>>> cctvs;
int n, m ;
int arr[9][9];
int result = 100000; 

vector<pair<int,int>> overlay ;
void rotate(int num) { // 배열을 돌리기.
    while(num--) {
        cctvs.clear();
    int rotatedArr[8][8];
    for(int j = 0 ; j < m ; j++){
        for(int i = 0 ; i < n ; i++){
            rotatedArr[j][n-1-i] = arr[i][j];
        }
    }
    for(int j = 0 ; j < m ; j++){
        for(int i = 0 ; i < n ; i++){
            arr[j][i] = rotatedArr[j][i];
            if(arr[j][i] > 0 && arr[j][i] < 6) {cctvs.push_back({arr[j][i],{j,i}});}
        }
    }
    int temp = n ;
    n = m ;
    m = temp ; 

    }
}

void right(int x, int y, bool mode) {
 for(int j = y+1 ; j < m ; j++) {
            if(arr[x][j] == 6) break; 
            if(arr[x][j] > 0) continue;
            if(mode) arr[x][j]--;
            else arr[x][j]++;
       }
}

void left(int x, int y, bool mode) {
for(int j = y-1 ; j >= 0 ; j--) {
            if(arr[x][j] == 6) break; 
            if(arr[x][j] > 0) continue;
            if(mode) arr[x][j]--;
            else arr[x][j]++;
        }
}

void top(int x, int y, bool mode) {
 for(int i = x -1 ; i >= 0 ; i--){
            if(arr[i][y] == 6) break;
            if(arr[i][y] > 0) continue;
            if(mode) arr[i][y]--;
            else arr[i][y]++;
        }
}

void bottom(int x, int y, bool mode) {
for(int i = x+1 ; i < n ; i++) {
            if(arr[i][y] == 6) break;
            if(arr[i][y] > 0) continue;
            if(mode) arr[i][y]--;
            else arr[i][y]++;
        }
}

void painting(int sort, int x ,int y,bool mode, int dir) {
    if(sort == 1){
        // 오
            if(dir == 0) { right(x,y,mode);}
        else if(dir == 1){ bottom(x,y,mode);}
        else if(dir == 2){ left(x,y,mode);}
        else if(dir == 3){ top(x,y,mode);}
      
    }
    else if(sort == 2){
            if(dir == 0 || dir == 2) {  
            right(x,y,mode);
            left(x,y,mode);
            }
        else if(dir == 1 || dir == 3){ 
            top(x,y,mode);
            bottom(x,y,mode);}
    }
    else if(sort == 3){
            if(dir == 0) { top(x,y,mode); right(x,y,mode); }
        else if(dir == 1){  right(x,y,mode); bottom(x,y,mode);}
        else if(dir == 2){  bottom(x,y,mode); left(x,y,mode);}
        else if(dir == 3){  left(x,y,mode); top(x,y,mode);}
    }
    else if(sort == 4){
            if(dir == 0) { left(x,y,mode); top(x,y,mode); right(x,y,mode); }
        else if(dir == 1){  top(x,y,mode); right(x,y,mode); bottom(x,y,mode);}
        else if(dir == 2){  right(x,y,mode); bottom(x,y,mode); left(x,y,mode);}
        else if(dir == 3){  bottom(x,y,mode); left(x,y,mode); top(x,y,mode);}
    }
    else if(sort == 5){
            right(x,y,mode);
            left(x,y,mode);
            top(x,y,mode);
            bottom(x,y,mode);
    }

}

void backtracking(int cnt) {
    if(cnt == cctvs.size()) {
        int num = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                if(arr[i][j] == 0) num++;
        result = min(result,num);
        return ;
    }

    auto cur  = cctvs[cnt] ;
    int sort = cur.first;
    int x = cur.second.first;
    int y = cur.second.second; 


    for(int i = 0 ; i < 4 ; i++) {
        painting(sort,x,y,true,i);
        backtracking(cnt+1);
        painting(sort,x,y, false,i);
        for(auto e : overlay) {
            arr[e.first][e.second] = -1 ;
        }
        overlay.clear();
    }
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m ;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> arr[i][j];
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(arr[i][j] > 0 && arr[i][j] < 6) {cctvs.push_back({arr[i][j],{i,j}});
            }

    backtracking(0);
    cout << result ; 
}

/*
[해결전략 참고]

[시작]

[배울 점]

[문제 이해]
- N x M 크기 직사각형
- 총 K개의 cctv
- cctv 종류
    (0번은 빈칸)
    1번 오 -> 회전 4번 가능
    2번 왼 오 -> 회전 2번
    3번 위 오 -> 회전 4번
    4번 왼 위 오 -> 회전 4번
    5번 왼 위 오 아 -> 회전 0번
    (6번은 벽)

- 벽 통과 못함.
- cctv가 감시할 수 없는 영역 -> 사각지대
- cctv는 회전 가능 -> 항상 90 도 방향으로, 감시하려는 방향은 가로 또는 세로 (대각선은 안됨)
- 감시가능영역은 #으로 함.
- cctv는 cctv 통과 가능
[입력]
- 세로 N, 가로 M
- 다음 N개의 줄에는 사무실 각 칸의 정보
[제약]
- 1 ≤ N, M ≤ 8
- cctv 최대 개수는 8이하 
[출력]
사각 지대의 최소 크기 구하기

[풀이전략]
- 완전탐색 : n,m 크기 별로 안큼.
1. cctv 어떻게 구현?
    - cctv 만나면 어떻게 통과?
    - 벽 만나면 통과 못함.
2. 회전 어떻게 구현? ->배열을 돌려버리자. -> 배열 어떻게 회전하기.
3. 4^8 = 65536 -> cctv별 돌리는거 모두 탐색해도 됨. -> 이거를 어떻게 함?
 - 백트래킹에 for문 -> 

아무리 생각해도 배열을 돌리는 건 아닌듯.

배열을 돌리지말고 화살표 방향 설정을 추가하자.



*/
