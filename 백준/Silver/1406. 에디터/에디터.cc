
#include <algorithm>
#include <iostream>
#include <list> 
#include <sstream>
#include <string>
#include <string>


using namespace std;

list<char> s;
list<char>::iterator t ;
string str;
int m, l; 
int cursor;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> str >> m;
            cin.ignore();

    l = str.length();
    for (int i = 0; i < l; i++)
    {
        s.push_back(str[i]);
    }
    t = s.end();

    for (int i = 0; i < m; i++)
    {
        string cmdStr ;
        getline(cin, cmdStr);
        if (cmdStr == "L") {
            if(t == s.begin()) continue;
            t--;
        } else if (cmdStr == "D")
        {
            if(t == s.end()) continue ;
            t++;
        } else if(cmdStr == "B") {
            if(t == s.begin()) continue;

            if(t == s.end()) {
               s.pop_back();
            } 
            else {
            t = s.erase(--t);
            }
        } else {
            s.insert(t,cmdStr[2]);
        }
    }
    for(t = s.begin();t != s.end();t++){ 
        printf("%c",*t); //원소 접근은 *it을 이용
    }  
    
}

/*
[해결전략 참고]

[배울 점]
- cin은 입력버퍼에 개행문자를 남겨두기 때문에 cin.ignore를 사용하여 버퍼를 비워준다음에 getline 사용
- list STL의 개념 부족 ->  end()는 맨 마지막의 다음 원소를 가리키는? iterator를 반환. vector는 마지막원소 가리킴
- erase()는 삭제된 이터레이터의 오른쪽 이터레이터를 반환
[문제 이해]
- 커서는 문장의 맨앞, 문장의 맨뒤, 문장 중간 임의의 곳에 위치
- 문자열 길이가 L이면, 커서 위치가능 곳은 L+1가지 경우 존재
L -> 커서 왼쪽으로
D -> 커서 오른쪽으로
B -> 커서 왼쪽에 있는 문자 삭제
P $ -> $문자를 커서 왼쪽에 추가

[입력]
- 첫째 줄은 문자열 
- 둘째 줄은 명령어 개수 M
- 셋째 줄부터 M개의 줄에 걸쳐 명령어

[제약]
- 문자열은 길이가 N이고 영어 소문자만, 10만이하
- 명령어의 개수 M은 1이상 50만이하
- 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치
- 0.3초
[출력]
- 명령어 수행후 최종 문자열 출력


[풀이전략]
실패 -> 문자열 입력받기 어려움 + iterator와 cursor 따로 관리 불편
1. 커서의 위치 변수 저장 -> L+1로 초기화
2. M번 반복하면서 커서변수 및 문자열 변경
3. 명령어 입력받을 때마다 바로바로 반영 
- 만약 L이고 커서변수가 0이 아니면, 커서변수 -1
- D이고 커서변수가 L+1이 아니면 커서변수 +1
- B이고 커서변수가 0이 아니면 문자열[커서변수-1] 삭제, 커서변수 -1
- P $이면 커서변수인덱스에 문자열 추가, 커서변수 +1 

두번째- cursor를 없애버리자.
이터레이터가 가르키는 게 커서의 왼쪽이라고 생각

B -> (이터레이터-1)을 삭제


*/