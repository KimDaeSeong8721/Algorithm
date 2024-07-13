#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int solution(string s) {
    int answer = 1001;
    if(s.length() == 1) return 1 ;
    for(int i = 1 ; i <= (s.length() / 2) ; i++) {
        string prevStr = s.substr(0, i);
        int cnt = 1 ; 
        string compressed = "";
        for(int j = i ; j < s.length() ; j+=i) {
            string tmpStr = s.substr(j, i);
            
            if(prevStr != tmpStr) {
                compressed += (cnt > 1) ? to_string(cnt) + prevStr : prevStr;
                prevStr = tmpStr;
                cnt = 1 ;  
            } else {
                cnt++;
            }
        }
        
    compressed += (cnt > 1) ? to_string(cnt) + prevStr : prevStr; 
        
    if(compressed.length() < answer) answer = compressed.length() ; 
    }
    return answer;
}

/*
[문제 접근]
문자열에서 같은 값이 연속해서 나타나는 것을 문자의 개수와 반복되는 값으로 표현하여 더 짧은 문자열로 줄여서 표현하는 알고리즘
문자열을 1개 이상의 단위로 잘라서 압축하는 방법을 찾고자함.
가장 짧게 압축할 수 있는 방법이 좋음.

1개 이상 단위로 문자열을 잘라 압축하여 표현한 문자열 중 가장 짧은 것의 길이 리턴

일단 단위길이는 최대 전체길이의 절반.

1.전체 - 1개
2. 전체 / 2 마다 - 2개
3. 전체 / 3 마다 - 3개 
4. 전체 / 4 마다 - 4개
...
나머지는 붙이셈.


[제약]

[풀이 전략]
1.s의 길이를 for문을 사용하여 나눠준다.

*/