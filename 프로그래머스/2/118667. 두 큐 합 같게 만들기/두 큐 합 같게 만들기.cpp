#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <queue> 

using namespace std;

typedef long long ll ; 

ll q1_sum ;
ll q2_sum ; 
ll val ; 

deque<ll> q1;
deque<ll> q2 ; 

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    for(auto v : queue1) {
        q1_sum += v; 
        q1.push_back(v);
    }
    
    for(auto v : queue2) {
        q2_sum += v; 
        q2.push_back(v);
    }
    
    val = (q1_sum + q2_sum)/2 ; 
    

    while(1) {
        if(q1_sum == val) break;
        if(q1.empty() || q2.empty() ) {answer = -1 ; break ; }
        int s = max(q1.size(),q2.size());
        if(answer > s*2 ) {answer = -1 ; break ; }
        else if(q1_sum > val) {
            ll tmp = q1.front();
            q1_sum -= tmp ;
            q2_sum += tmp ; 
            q2.push_back(tmp); q1.pop_front();
            answer++;
        } else {
            ll tmp = q2.front();
            q1_sum += tmp ;
            q2_sum -= tmp ; 
            q1.push_back(tmp); q2.pop_front();
            answer++;
        }
    }

    return answer;
    
    
}

/*
길이가 같은 두 개의 큐가 주어짐.
 - 하나의 큐를 골라 원소 추출
 - 추출된 원소를 다른 큐에 집어 넣음
 -> 각 큐의 원소 합이 같도록 만들려고함. 이때 필요한 작업의 최소 횟수!
 -> 한번의 pop과 insert를 합쳐서 1회
 
 풀이전략
 - 모든 원소의 합을 더하고 이것의 절반이 각 큐의 총합이 되어야한다.
 - 만들 수 없으면 -1을 리턴한다.
 
 각 q의 길이는 30만이하
 각 q의 원소는 10^9이하 . -> 더하는 거는 long long으로 표현해야겠다.
 
 1. 모든 원소의 합을 구한다. 
 2. 2로 나눈다. ->  목표 값
 3. 한 큐1를 검사한다.
 목표값보다 크다
 큐1에서 덜어낸다.
 목표값보다 작다
 큐2에서 꺼내온다.
 목표값이랑 같다 -> 스탑
 목표값이 절때 될 수 없는 경우
 - q과 q2가 비는 경우
 - 더 있나?
 
 
*/
