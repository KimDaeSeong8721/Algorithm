
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int dx[8] = {2,-2,-2,2,1,-1,-1,1};
int dy[8] = {1,1,-1,-1,2,-2,2,-2};


int arr[301][301];
int dis[301][301];

queue<pair<int, int>> q ;

int t;
int l;
int initialX, initialY;
int destX, destY ; 

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 

    cin >> t ;

    for(int i = 0; i < t ; i++) {

        cin >> l ;
        cin >> initialX >> initialY ;
        cin >> destX >> destY ;

        q = queue<pair<int, int>>() ;

        q.push(make_pair(initialX,initialY));

        while(!q.empty()) {
            pair<int,int> cur = q.front() ; q.pop();
             int x = cur.first ;
             int y = cur.second; 
             
                     if(x == destX && y == destY) {
                        cout << dis[x][y]<< '\n' ;
                           for(int k = 0 ; k < l ; k++){
                        fill(dis[k], dis[k] + l, 0);
        }
                        break;
                    }
             for(int j = 0 ; j < 8 ; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if(nx >= l || nx < 0 || ny >= l || ny < 0) continue; ;
        

                if(dis[nx][ny] == 0 || dis[nx][ny] > dis[x][y] + 1) {
                    dis[nx][ny] = dis[x][y] + 1;
                    q.push(make_pair(nx,ny));
                }
             }
            
        }

      

    }



}

/*
[해결전략 참고]

[시작]

[배울 점]
- 테스트 케이스 여러 개 할때 거리다차원배열과 큐를 초기화시켜줘야 함 -> 초기화문제
[문제 이해]
- 나이트가 한번에 이동할 수 있는 칸은 8개
- 체스판의 각칸은 a*b 로 나타낼 수 있음.
- 나이트가 이동하려는 칸 주어짐
- 몇번 만에 도착? 

[입력]
- 1줄 : 테스트 케이스
- 각 테스트 케이스는 3줄로 이루어짐
    - 1줄은 체스판의 한 변 길이
    - 2줄은 나이트가 현재 있는 칸
    - 3줄은 나이트가 이동하려는 칸

[제약]
- 4<= 한변의 길이 <= 300

[출력]
- 각 테스트 케이스마다의 최소이동횟수 출력

[풀이전략]


*/
