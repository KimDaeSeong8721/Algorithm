#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;



deque<int> deq[4]; // 톱니바퀴 모음
queue<int> q ; // 회전시킨 방법 모음: 번호, 이전번호, 회전방향
vector<pair<int,int>> v ;
int vis[4] ;
int k ; 

int n, d ;
void rotate(int num,int dir) {

    if(dir == 1){
        deq[num].push_front(deq[num].back()) ;
        deq[num].pop_back();
    }
    else if(dir == -1){
        deq[num].push_back(deq[num].front());
        deq[num].pop_front();
    }
}

void chain(int num, int dir){
 // 1번 -> 2번 -> 3번 -> 4번
 // 1번 <- 2번 -> 3번 -> 4번
  // 1번 <- 2번 <- 3번 -> 4번
   // 1번 <- 2번 <- 3번 <- 4번
    // BFS

    fill(vis,vis+4,0);
    vis[num] = dir;
    q.push(num);
    
    while (!q.empty())
    {   
       auto curNum = q.front(); q.pop();
        
         if(curNum-1 >=0) {
            if(vis[curNum-1] == 0 && (deq[curNum-1][2] != deq[curNum][6])) { 
            q.push(curNum-1);  
            vis[curNum-1] = -vis[curNum] ;
            }
            }
         if(curNum+1 < 4){
             if(vis[curNum+1] == 0 && (deq[curNum+1][6] != deq[curNum][2])) {

            q.push(curNum+1);
            vis[curNum+1] = -vis[curNum] ;
             }
            }
    }
    for(int i = 0 ; i < 4 ; i++) {
        if(vis[i] !=0) {
            rotate(i,vis[i]);
        }
    }

}

int getScore() {
    // 톱네 바퀴 점수의 합 구하기.
    int score = 0 ;
    for(int i = 0 ; i < 4 ;i++){
        if(deq[i][0]) score += (1<<i); // pow말고 더 간단하게 못할까
    }
    return score;
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 

    for(int i = 0 ; i < 4 ; i++) {
            string temp ;
            cin >> temp ; 
            for(int j = 0 ; j < 8 ; j++){
                deq[i].push_back(temp[j] -'0') ;}
    }
    cin >> k ; 

    while (k--)
    {  
        int n, d ;
        cin >> n >> d ;
        chain(n-1,d);

    }

    cout << getScore();

 
}

/*
[해결전략 참고]

[시작]
3.25. 7:39 pm ~ 10:48 pm ~ 11:25 pm  ->  인덱스 6인데 5로 해두고 9시방향 풀음 ..

[배울 점]
- deque 시간복잡도 파악하기 
[문제 이해]
- 총 8개 톱니 .. 톱니바퀴 4개 -> N or S극
- k번 회전
    - 시계 혹은 반시계
- 맞닿은 극에따라 옆에 있는 톱니바퀴를 회전시킬수도 혹은 그렇지 않을 수도.
    다른 극이면 -> A회전 시계방향 회전시 옆에있는 B 시계반대방향으로 회전.
    같은 극이면 회전하지 않음.
- N - 0 S - 1
[입력]
- 1줄 - 1번 톱니바퀴
- 2줄 - 2번
- 3줄 - 3번
- 4줄 - 4번.
- 12시방향 ~ 시계방향순으로 상태 주어짐.
- 5줄 : 회전 횟수 K
- 다음 K개 줄: 회전시킨방법이 순서대로 주어짐. <톱니바퀴번호 : 방향(시계 1 반시계 -1 )>
[제약]

[출력]
- 총 K번 회전시킨 이후 네 톱니바퀴의 점수 합 출력
[풀이전략]

1. 회전을 어떻게 할것인가?
1-1겹치는 부분
    1번 - 인덱스 2
    2번 - 인덱스 2, 6
    3번 - 인덱스 2, 6
    4번 - 인덱스 2, 6
1-2 회전할때마다 시계방향이면 앞으로 1칸식 밀리고 반시계면 1칸식 당겨짐.

톱니바퀴 연쇄반응을 어떻게 구현?
- 큐 구현
*/
