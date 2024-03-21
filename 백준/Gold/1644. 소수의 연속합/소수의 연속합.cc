#include <iostream>
#include <algorithm>
using namespace std;


int cnt ; 
int n ; 
const int MXM = 4000002; 
vector<int> primes; 
vector<bool> seive(MXM,true);
void findPrime() {
    for(int i = 2 ; i*i < MXM; i++){
        if(!seive[i]) continue;
        for(int j = i * i ; j < MXM; j+= i)
            seive[j] = false;
    }
    for(int i = 2 ; i < MXM ; i++) if(seive[i]) primes.push_back(i);
    
}

int main() {
  ios::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n ;

    findPrime();

  int st = 0 ; int end = 1 ; 
  int sum = primes[0] ;
    while (1)
    {  
      if(n == sum) cnt++;
      if(n >= sum) sum += primes[end++];
      else if(n < sum) sum -= primes[st++];
      
    if(end == primes.size()+1) break;
    }
        cout << cnt ;

}


/*
[해결전략 참고]
https://github.com/encrypted-def/basic-algo-lecture/blob/master/0x14/solutions/1644.cpp
[시작]
- 시간 초과 
[배울 점]
- 소수 판별방법은 ? 제곱근을 이용하지 않으면 시간초과. -> 시간초과 -> 에라토스테네스의 체 이용

[문제 이해]
- 하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수
- 3 : 3
- 41 : 2 3 5 7 11 13 = 11 13 17 = 41
- 53 : 5 7 11 13 17 
[입력]
1줄 : 자연수 N

[제약]
- 연속된 소수들이어야 함.
- 소수는 반드시 한번만 사용가능.
- 1<= N <= 4백만.
[출력]
- 이 자연수를 소수의 합으로 나타낼 수 있는 경우의 수 작성하기

[풀이전략]
- 400백만까지 소수를 구해서 배열에서 소수여부를 저장한다.
    - 소수 판별 여부
        for(int i = 2 ; i <= n % 2 ; i++)
            if(n % i == 0) return false;
        return true ;

- 투 포인터를 이용
    - int cnt = 0 ;
    - st = 2, en = 3 ;
    - 만약 target > st ~en까지의 소수의 합 -> en++;
    - 만약 target < st ~en까지의 소수의 합 -> st++;
    - same하면 cnt++;en++ ; 
    - while(st <= en)하고 만약 en == n+1이면 break;

*/
