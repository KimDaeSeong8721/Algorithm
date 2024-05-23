#include <string>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
unordered_map<string,int> um ;
map<string,int> m ; 

vector<string> split(string& s, string sep) {
    int pos = 0 ;
    vector<string> v ;
    while(pos < s.size()){
        int nxt_pos = s.find(sep,pos) ;
        if( nxt_pos == -1) nxt_pos = s.size();
        if(nxt_pos - pos > 0) { // 같으면 사실 넣을 문자열이 없기 때문
            string tmp = s.substr(pos,nxt_pos-pos);
            v.push_back(tmp);
        }
        pos = nxt_pos+sep.size() ;   
    }
    return v ; 
}

int convert_min(string time){
    auto time_tmp = split(time, ":");
    return (stoi(time_tmp[0])*60 + stoi(time_tmp[1]));
}


vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    
for(string record: records){
    auto tmp = split(record, " ");
    
    int mins = convert_min(tmp[0]);
    
    if(tmp[2] == "IN") {
        um[tmp[1]] = mins;
    } else {
        m[tmp[1]] += convert_min(tmp[0])- um[tmp[1]] ;
        um[tmp[1]] = -1 ;
    }
}
    
    for(auto e : um){
        if(e.second !=-1){
            m[e.first] += convert_min("23:59") - e.second ; 
        }
    }
        //요금 계산
    for(auto e: m) {
        if(e.second <= fees[0]) {
            answer.push_back(fees[1]);
        }
        else {
            int tmpsum = fees[1];
            if((e.second - fees[0]) % fees[2] == 0) {
                tmpsum += (e.second - fees[0]) / fees[2] * fees[3];
                
            } else {
                tmpsum += ((e.second - fees[0]) / fees[2]+1) * fees[3];
            }
            answer.push_back(tmpsum);

        }
    }    
    return answer;
}

/*
[문제 접근]
차량 번호가 작은 자동차부터 청구할 주차 요금을 차례대로 정수배열에 담아 리턴하기.
시간 관련 문자열 처리도 필요
records는 시각을 기준으로 오름차순으로 정렬되어 주어짐.

[제약]
- 출차내역이 없으면 23:59에 출차된것으로 간주
- 기본 시간 이하라면 기본 요금 청구
- 기본 시간 초과하면 기본 요금 + 초과한 시간에 대한 단위 시간마다 단위 요금 청구.
  - 초과한 시간 % 단위 시간 !=0 이면 (초과한 시간 / 단위 시간) + 1 에 단위 요금을 곱한다.그렇지 않으면 (초과한 시간 / 단위 시간)에 단위 요금을 곱한다.
- 같은 시각에, 같은 차량번호의 내역이 2번 이상 나타내지 않음.


[풀이 전략]
해쉬맵을 이용하여 In이면 값을 저장하고 Out이면 0으로 초기화한다.
그냥 맵을 이용하여 누적 시간을 저장한다.
마지막에 이 맵을 이용하여 누적요금을 계산하다.
*/