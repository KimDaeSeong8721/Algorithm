#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> split(string &s, string sep) {
	vector<string> ret;
	int pos = 0 ;
	while(pos < s.size() ) {
		int nxt_pos = s.find(sep, pos); // pos번째 인덱스부터 sep가 시작하는 위치를 반환.
		if(nxt_pos == -1) nxt_pos = s.size();
		if(nxt_pos - pos > 0) ret.push_back(s.substr(pos, nxt_pos - pos));
		pos = nxt_pos + sep.size();
	}
	return ret ;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> m;
    vector<vector<string>> recordList ; 

    for(string &e : record) {
        auto temp = split(e," ");
        if(temp[0] != "Leave"){
            m[temp[1]] = temp[2];
        } 
        if(temp[0] != "Change") recordList.push_back(temp);
    }
    
    for(vector<string> &e : recordList) {
        string str = "" ;
        if(e[0] == "Enter") {
            str = m[e[1]] + "님이 들어왔습니다.";
        }
            else {
            str = m[e[1]] + "님이 나갔습니다.";
            }
        answer.push_back(str);
    }
    
    
    
    return answer;
}

/*
[문제 접근]
1. 들어왔슴다
2. 나갔슴다.

닉넴변경방법
1. 방 나간후 새로운 닉네임으로
2. 방안에서 변경 

닉네임이 변경되면 기존의 닉넴활동들 모두 새로운 닉네임으로 변경

최종 문자열 배열 출력.

[제약]
- 1이상 10만이하.

[풀이 전략]
1. 레코드에서 change 원소를 찾는다.
2. 이 원소들을 활용하여 닉네임을 바꿔준다.
3. 출력한다.
*/