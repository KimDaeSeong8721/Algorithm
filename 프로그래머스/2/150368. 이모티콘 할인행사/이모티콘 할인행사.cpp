#include <string>
#include <vector>
#include <iostream>
using namespace std;


vector<int> answer(2,-1);
int discount[4] = {10,20,30,40};
vector<int> emoticonDis ; 

void backtracking(int cnt,vector<vector<int>> users, vector<int> emoticons ){
    if(cnt == emoticons.size()){
    pair<int,int> result ;
    int joinCnt = 0 ; 
    int totalIncome = 0 ;
    for(auto user: users){
        int income = 0;
        for(int i = 0 ; i < emoticons.size() ; i++){
            if(user[0] <= emoticonDis[i]) income += ((100-emoticonDis[i]) *0.01 * emoticons[i]);
        }
       if(user[1] <= income) {joinCnt++;}
       else  { totalIncome += income; }
       
    }
    if(answer[0] < joinCnt) {
        answer[0] = joinCnt ;
        answer[1] = totalIncome ;
    }  else if(answer[0] == joinCnt) {
        if(answer[1] <= totalIncome) answer[1] = totalIncome ;
    }
    return; 
    }
    for(int i = 0 ; i < 4 ; i++) { // 이모티콘 할인율 
        emoticonDis.push_back(discount[i]);
        backtracking(cnt+1,users,emoticons);
        emoticonDis.pop_back();
    } 
}


vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    
    backtracking(0,users,emoticons);
    return answer;
}


/*
[문제이해]
- 1순위 이모티콘 플러스 서비스 가입자 최대한 늘리기
- 2순위 이모티콘 판매액을 최대한 늘리는 것.

- n명의 카카오톡 사용자에게 이모티콘 m개를 할인 판매
- 할인율은 10 20 30 40 중 하나.
- users : n명의 구매기준 
- emotions: 이모티콘 m개의 정가

[입력]
[출력]
- 행사목적 최대한 달성했을때 서비스 가입수와 이모티콘 매출액을 1차원 정수 배열에 담아 리턴.
[제약]
- 각 사용자는 자기 기준에 따라 이모티콘을 모두 구매함
- 각 사용자는 구매 비용의 합이 일정 가격이상되면 이모티콘 구매 모두 취소 후 서비스 가입
- 1<= users길이 = n <= 100
- 1<= 비율 <= 40, 100<=가격<= 백만. // 가격은 100의 배수
- 1<= emoticons의 길이 = m <= 7
- 100<=이모티콘 가격<= 백만. 100의 배수.

[문제풀이]
할인율은 4가지(10 20 30 40)
그럼 경우의수는 4^이모티콘의 길이 2^14  -> 충분, 완전탐색 고 > 백트래킹?
기존 answer ; 

int m = emoticons.size();
void backtracking(int cnt){
    if(cnt == m){
    pair<int,int> result ;
    int joinCnt =0 ; 
    int totalIncome = 0 ;
    for(auto user: users){
        int income = 0;
        for(int i = 0 ; i < m ; i++){
            if(user[0] <= emoticonDis[i]) income += emoticonDis[i] *0.01 * emoticons[i];
        }
       if(user[1] <= income) {joinCnt++;}
       else  { totalIncome = income }
       
    }
    if(answer[0] < joinCnt) {
        answer[0] = joinCnt ;
        answer[1] = totalIncome ;
    } 
    return; 
    }
    for(int i = 0 ; i < 4 ; i++) { // 이모티콘 할인율 
        emoticonDis.push_back(discount[i]);
        backtracking(cnt+1);
        emoticonosDis.pop();
    } 
}

*/