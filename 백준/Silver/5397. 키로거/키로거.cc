
#include <algorithm>
#include <iostream>
#include <list> 
#include <sstream>
#include <string>
#include <string>


using namespace std;



int n, l; 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);   
    cin >> n ; 
    for(int i = 0 ; i < n ; i++) {
        string str;

        cin >> str ;
        list<char> s;
        list<char>::iterator it ;
        

        l = str.length();
        it = s.begin();

        for(int j = 0 ; j < l ; j++) {
            if(str[j] == '<') {
                if(it != s.begin()) {
                    it-- ;
                }
            }
            else if(str[j] == '>') {
                 if( it != s.end()) {
                    it++ ;
                }
            } else if(str[j] == '-') {
                if(it != s.begin()) {
                    it--;
                    it = s.erase(it);
                }
            } else {
                // alphabet
                it = s.insert(it,str[j]);
                it++;
            }
        }

         for(it = s.begin(); it != s.end(); it++){ 
        cout<< *it; 
        //원소 접근은 *it을 이용
        }  
        cout << '\n';
    }
}

/*
[해결전략 참고]

[시작]
// 1월 22일 월 2시 5분 시작
// 3시 27분인데 아직도 못품 -> 실패
// 3시 49분 완성 -> 실패

[배울 점]
- 커서를 사용한다면 연결리스트를 떠올릴 것!
- getline()은 왜 <<나 -를 입력으로 못받고 에러를 방출하지?
[문제 이해]
- 키로거는 키보드를 누른 명령 모두 기록
- 강산이가 백스페이스 -> '-'
- 화살표는 -> '>' '<' -> 커서의 위치 이동시킴
[입력]
- 첫쨰줄은 테스트 케이스 개수
- 각 테스트 케이스는 한줄(길이는 L임)

[제약]c
- 화살표나 백스페이스를 입력해도 정확한 비밀번호 얻을 수 있음
- 키는 알파벳 대문자,소문자,숫자, 백스페이스, 화살표 
- 1=< L =< 백만
- 이때 커서 바로 앞에 글자가 존재한다면 글자를 지운다? 
- 커서위치가 마지막이 아니면 -> 커서 및 커서 오른쪽의 모든 문자는 오른쪽으로 한 칸 이동한다???? 무슨말이야. 밀린다는 의미인듯 => 입력시
[출력]
- 비밀번호 출력
abc
[풀이전략]
커서를 사용하니까 결국 연결리스트를 사용해야겠구나!
이터레이터가 가리키는게 커서의 왼쪽이라 가정
- TestCase 개수 입력 받고 For문
- 이터레이터, for문 돌 때마다 이터레이터++, 화살표에따라 이터레이터 +-
- 알파벳이 아닌 입력을 받았을 경우
    - "<": 이터레이터가 처음이 아니라면 커서--
    - ">": 이터레이터가 끝이 null이 아니라면 이터레이터++
    - "-": 이터레이터의 값이 존재한다면 삭제, 단 이터레이터가 처음이라면 삭제불가 

실패

기존 문자열은 납두고 돌면서 연결리스트에 추가하는 형태로.
*/
