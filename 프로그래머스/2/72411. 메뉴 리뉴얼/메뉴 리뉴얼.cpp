#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;



vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string,int> m ; 
    for(auto cnt : course){
       for(auto order : orders){
        sort(order.begin(), order.end());
        int N = order.size();
        vector<int> a ;
        if(cnt > N) continue;
     for(int i = 0; i < N; ++i)  a.push_back(i < cnt ? 0 : 1);
    do{
    string s = "" ;
    for(int i = 0; i < N; ++i)
      if(a[i] == 0) {
          s += order[i];
      }
    m[s]++;
  }while(next_permutation(a.begin(), a.end()));
        
    }  
    int maxv = 0 ;
    vector<string> maxStr;
    for(auto e : m){
        if(e.second < 2) continue; 
        if(e.first.size() != cnt) continue;
        if(maxv < e.second){
            maxv = e.second;
            maxStr.clear();
            maxStr.push_back(e.first); 
        } else if(maxv == e.second){
            maxStr.push_back(e.first); 
        }
    }
    for(auto str : maxStr)  answer.push_back(str);

    }

    sort(answer.begin(),answer.end());
    return answer;
}

/*
문제접근
- 코스 요리는 최소 2가지이상 단품메뉴
- 가장 많이 함께 주문한 단품메뉴들을 코스 요리로 구성
- 최소 2명이상 주문된 단품메뉴만.
- 각 손님은 최소 메뉴 2개 이상 주문
- 만약 가장 많이 함께 주문된 메뉴 구성이 여러개면 모두 담기
-

풀이전략
- 각 orders의 원소마다 course의 원소만큼 뽑아서 map 넣는다.
- map에서 정답에 해당되는 것들 선별

-> 시간복잡도가 예상이 잘 안가고, 대략 계산하면 훨씬 초과..
-> 시간초과.

모지?? 어떻게 풀어야하지.


*/