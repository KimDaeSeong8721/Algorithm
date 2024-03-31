#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;


int n ,m ; // 사람의 수 , 파티의 수
int isTrue[51]; // 파티별 진실 여부

vector<int> personAdj[51];
vector<int> partyAdj[51];

int visp[51]; // 사람 방문 배열
queue<int> q1 ;

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> m ; 
    int t ;
    cin >> t ;
    for(int i = 0 ; i < t ; i ++) {
        int temp ;
        cin >> temp ;
        q1.push(temp);
        visp[temp] = 1 ;
    }

    for(int i = 1 ; i <= m ; i++) {
        int t ;
        cin >> t ;
        for(int k = 0 ; k < t ; k++) {
            int temp ;
            cin >> temp;
            partyAdj[i].push_back(temp);
            personAdj[temp].push_back(i);
        }
    }

    while (!q1.empty())
    {
        auto curPerson = q1.front() ; q1.pop();

        for(auto party : personAdj[curPerson]) {
            if(isTrue[party]) continue;
            isTrue[party] = 1;
            for(auto person: partyAdj[party]) {
                if(visp[person]) continue;
                visp[person] = 1 ;
                q1.push(person);
            }
        }

    }
    int tot = 0 ;
    for(int i= 1 ; i <= m ; i++) {
        if(!isTrue[i]) tot++;
    }
    cout << tot ; 
}

/*
[해결전략 참고]

[시작]
- 3월 31일 오후 9:17 10:17 틀림 -> 히든케이스가..
[배울 점]

[문제 이해]
- 되도록 거짓말함.
- 진실을 아는 사람이 파티에 오면 무조건 진실말함
- 
[입력]
- N,M
- 진실 아는 사람수 : a b c d 
- M개 줄: 각 파티에 오는 사람수 :a b c d
[제약]
- N,M은 50이하 자연수
- 진실 아는 사람의 수 0이상 50이하 정수
- 각 파티에 오는 사람의 수는 1이상 50이하의 정수.
- 어떤 사람이 어떤 파티에서 진실을 듣고, 다른 파티에 거짓말 들어서도 안됨.
- 모든 파티에 참가해야함.

[출력]
거짓말 들키지 않고 거짓말 할 수 있는 파티의 최대개수.

[풀이전략]
4명 1파티
진실 아는 사람 1번
0파티 : 1번 2번 3번 4번 -> 진실말해야함. 2,3,4번이 속한 파티도 무조건 진실말해야함.
진실을 아는 사람을 모아놓은 벡터를 기준으로 방문을 시작한다.
파티를 q에 넣는다.
q를 빼면서 파티 안의 사람들을 진실 벡터에 다시 넣는다.

1 0파티 2파티
2 3파티 4파티.
3 0파티 4파티
4
5

0파티 : 1,3
1파티
2파티 

*/
