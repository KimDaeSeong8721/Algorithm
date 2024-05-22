#include <string>
#include <vector>
#include <iostream>
using namespace std;

int num ; 
vector<int> tmp ; 
vector<vector<int>> col ;
void dfs(int cnt,int val) {
    if(cnt == 11) {
    col.push_back(tmp);
        return;}
    
    for(int i = 0 ; i <= val ; i++){
        if(val >= i) {
            tmp.push_back(i);
            dfs(cnt+1, val - i);
            tmp.pop_back();
        }
    }
    
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    int dif = 0 ; 
    num = n ;  
    dfs(0,n);
    
    for(auto v : col) {
        int score1 = 0 ;
        int score2 = 0; 
           for(int i = 0 ; i < 11 ; i++){
        if(info[i] < v[i]) {
            score2 += 10-i;
        } else { 
            if(info[i] == 0 && v[i] == 0) continue;
                score1 += 10-i;
        }
    } 
        if(score1 < score2) {
             if(dif < score2 - score1) {
                 dif = score2 - score1 ;
                 answer = v;
             } else if(dif == score2 -score1) {
                 for(int i = 10 ; i>= 0; i--){
                     if(answer[i] < v[i]) {
                         answer = v ; 
                         break;
                     } else if(answer[i] > v[i]) break; 
                 }
             }
        }
    }
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}

/*
문제 접근
다양한 선수들이 우승하는 거 원함.

규칙
1. 어피치 n번 후 라이언이 n번
2. k점에 대해 더 많은 횟수를 맞힌 사람이 k점을 가져간다.
3. 만약 같다면 어피치가 k점을 가져간다.
4. k점을 모두 0발맞추면 가져가지 않는다.
5. 최종점수가 더 높은 선수가 우승자. 같으면 어피치가 우승자

라이언은 어피치와 가장 큰 점수차이로 이기기 위해 n발의 화살을 어떤 과녁 점수에 맞혀야 하는지 구하기
라이언이 우승할 수 없는 경우(비기거나 지는 경우) [-1] 리턴

만약 가장 큰 점수 차이로 우승할 방법이 여러가지면 가장 낮은 점수를 더 많이 맞힌 경우를 리턴.
정확성 테스트 10초.

-> 그리디 알고리즘 느낌이 난다.
-> 아니면 완전탐색 -> 10 => 

첫번째 방법
1. 완전탐색


10 = 1+1+1+1+1+1+1+1+1+1
10 = 



*/