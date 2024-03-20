#include <iostream>
#include <algorithm>
using namespace std;


int nA,nB ;

int arrA[500001];
int arrB[500001];
int isExisted[500001];

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> nA >> nB ;
    
    for(int i = 0 ; i < nA ; i++){
        cin >> arrA[i];
    }
    for(int i = 0 ; i < nB ; i++){
        cin >> arrB[i];
    }
    sort(arrB,arrB+nB);

    for(int i = 0 ; i < nA ; i++){
        isExisted[i] = binary_search(arrB,arrB+nB, arrA[i]);
    }
    
    int cnt = 0 ;
    vector<int> v; 
    for(int i = 0 ; i < nA ; i++){
        if(isExisted[i]) continue;
            cnt++;
            v.push_back(arrA[i]);
        
    }
    sort(v.begin(),v.end());
    
    cout << cnt <<'\n';
    for(auto e : v) cout << e << ' ';

}

/*
[해결전략 참고]

[시작]

[배울 점]

[문제 이해]
- 몇 개의 자연수로 이루어진 두 집합 A,B
- 집합 A에 속하면서 집합 B에는 속하지 않는 모든 원소

[입력]
- 첫째 줄은 A의 원소의 개수, B의 원소의 개수
[제약]
- 1<= n(A), n(B) <= 500,000
- 둘째줄은 A의 원소
- 셋째줄은 B의 원소
- 집합의 원소는 2147483647 이하의 자연수
- 하나의 집합에 속하는 모든 원소의 값은 다르다.

[출력]
- 집합 A에는 속하면서 집합 B에는 속하지 않는 원소으로 개수 출려
- 그 원소를 증가하는 순서로 출력
- 만약 없다면 0 출력 

[풀이전략]
- 집합 B를 정렬시킨다.
- 집합 A의 원소를 하나씩 꺼내서 이분탐색
- 유무여부 배열만들어서 탐색되면 true. 탐색성공마다 cnt++;
- 유무여부 배열을 이용해서 출력 정렬추가
*/
