#include <string>
#include <vector>
#include <iostream>

using namespace std;


bool isGoodBracket(string s) {
    int val = 0 ;
    for(auto c: s){
        if(c == '(') val++;
        else if(c ==')') val--;
        if (val < 0) return false ;
    }
    return true ;
}

string func(string s){
    if(s == "") return ""; // 빈문자열이면 빈문자열 반환
    string u = "";
    string v = "";
    //문자열 분리.
    // ( -> +1 ,, ) -> -1 ;
    int val = 0 ; 
    for(int i = 0 ; i < s.length();i++){
        if(s[i] == '(') val++;
        else if(s[i] ==')') val--;
        if(val == 0) {
            u = s.substr(0,i+1); 
            v = s.substr(i+1,s.length()-u.length());
            break;
        }
    }
    if(isGoodBracket(u)) { // u가 올바른 문자열이면
        auto r = func(v);
        return u+r ; 
    }
    else { // u가 올바른 문자열이 아니라면
        string tmpstr = "(";
        tmpstr += func(v);
        tmpstr += ")";

        u = u.substr(1,u.length()-2);
        for(auto &c :u) {
            if(c == '(') c = ')';
            else if(c == ')') c = '(';
        }
        
        tmpstr += u ;
        return tmpstr ;
    }
}
string solution(string p) {
    
    return func(p);
}

/*
[문제접근]
균형잡힌 괄호 문자열 -> (의 개수와 )의 개수가 같음
올바른 괄호 문자열 -> 위에 더하여 (와)의 짝도 모두 맞음.

균형잡힌 것을 올바른 것으로 변환하는 과정
- 빈문자열은 반환
1. 문자열 w를 균형잡힌 문자열 u, v로 분리 -> u는 분리할 수 없는 균형잡힌 문자열, v는 빈문자열도 가능
2-1문자열 u가 올바른 문자열이면 v를 위의 과정 반복.

2-2 문자열 u가 올바른 문자열이 아니면
a. 빈 문자열에 (를 붙인다.
b. v를 1단계부터 재귀 수행한 결과 문자열 붙임.
c )를 붙인다.
d. u의 첫번째 문자와 마지막 문자 제거, 나머지 문자열의 괄호 방향을 뒤집어서 뒤에 붙인다.
f. 반환.

[풀이전략]
0-1. 균형잡힌 문자열 판별함수
0-2. 올바른 문자열 판별함수.

1. if p가 올바른 문자열 -> 출력
2. else 이면 아래의 과정
- 문자열을 분리한다.u는 분리할 수 없는 균형잡힌 문자열
- if u가 올바른 문자열이면 v를 위의 과정 반복
- else 이면 아래의 과정 
   - 
*/