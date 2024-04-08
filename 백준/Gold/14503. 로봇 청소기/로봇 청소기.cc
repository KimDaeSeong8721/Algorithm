#include <iostream>
#include <algorithm>
using namespace std;


int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int n, m ;
int arr[51][51]; // 방 상태
int tot ; 
int x,y,d ; 

bool isExisted() {
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= n-1 || nx <= 0 || ny >= m-1 || ny <= 0) continue;
        if(arr[nx][ny] == 0) return true; // 빈칸 존재하면 
    }
    return false;
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m ;

    cin >> x >> y >> d ;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> arr[i][j];
    
    while (true)
    {
        if(arr[x][y] == 0) arr[x][y] = -1;
        if(!isExisted()) { // 빈칸 없음

        int nx = x + dx[(d+2)%4];
        int ny = y + dy[(d+2)%4];
        if(arr[nx][ny] == 1) break;
        x = nx ; y = ny;

        } else { // 빈칸 있음
        d = (d+3)%4;
        int nx = x + dx[d];
        int ny = y + dy[d];

        if(arr[nx][ny] == 0) {
            x = nx; y =ny ;
        }
        }
     

    }
    




    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            if(arr[i][j] == -1) tot++;
    cout << tot ;
}

/*
[해결전략 참고]

[시작]
- 4월 8일 오후 5:06~ 5:45 ->  반시계회전 d값 업데이트를 안해줘서 무한루프겪음.

[배울 점]

[문제 이해]
-  방은 n x m 
- 각 칸은 벽 또는 빈칸
- 청소기가 바라보는 방향 존재 -> 동서남북 중 하나
- 빈 칸은 청소되지 않은 상태

로봇 청소기 동작방식
1. 현재 칸이 빈칸이면, 청소한다
2. 현재 칸 주변 4칸 중 빈칸이 없는 경우
 -> 후진하고 1번으로 돌아간다.
 -> 후진 불가하면 작동 멈춘다.
 3. 현재 칸 주변 청소되지 않은 빈 칸이 있는 경우
 -> 반시계 방향으로 90도 회전한다.
 -> 바라보는 방향 기준으로 앞쪽 칸이 빈칸이면 한칸 전진한다.
 -> 1번으로 돌아간다.

d -> 0 - North, 1 -> East, 2 -> South, 3-> West
칸 -> 0 - 빈칸 , 1 -> 벽
[입력]
- n, m
[제약]
- n,m은 3이상 50이하
- r,c ,d // x좌표, y좌표, 방향
- 방의 각 청소상태 주어짐
- 바깥둘레는 모두 벽임.
- 로봇 청소기 좌표는 무조건 빈칸임.

[출력]
- 청소하는 영역의 개수 출력

[풀이전략]
청소가 되었으면 -1로 변경하기.

반시계 방향으로 90도 회전한다.
0 -> 3
1 -> 0
2 -> 1
3 -> 2
 (d + 3) % 4
-> 
*/
