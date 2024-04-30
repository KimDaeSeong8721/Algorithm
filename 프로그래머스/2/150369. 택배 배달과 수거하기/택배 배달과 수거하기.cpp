#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int dmi = n-1 ;
    int pmi = n-1 ;

    
    while(dmi >= 0 || pmi >= 0 ) {
        
        while(deliveries[dmi] == 0 && dmi >= 0) dmi--;
        while(pickups[pmi] == 0 && pmi >=0 ) pmi--;
        
        answer += (max(dmi,pmi)+1)*2;
        int tmp1 = cap ;
        int tmp2 = cap ;
        
        while(tmp1 > 0  && dmi >= 0) {
            if(tmp1 - deliveries[dmi] >= 0) {
                tmp1 -= deliveries[dmi];
                deliveries[dmi] = 0 ;
            } else {
                deliveries[dmi] -= tmp1 ;
                tmp1 = 0 ;
                break;
            }
            dmi-- ;

        }
        while(tmp2 > 0 && pmi >= 0) {
            if(tmp2 - pickups[pmi] >= 0) {
                 tmp2 -= pickups[pmi];
                pickups[pmi] = 0 ;
            } else {
                pickups[pmi] -= tmp2 ;
                tmp2 = 0 ;
                break;
            }
            pmi-- ;

        }
    }
    return answer;
}

/*
시간
-10:22 ~ 

문제 접근
- i번째 집은 0에서 i거리 떨어짐.
- 트럭은 최대 cap 실을 수 있습니다.

일단 읽을수록 와 쉽지 않겠네 라는 생각이 드네여.
돌아오면서 수거를 다 해버리네.

시간제약이 없다  -> 백트래킹으로 풀어도 가능할지도.


제약
- 1 <= i < = j < = n
- n은 10만이하.
- cap은 50이하.
- 각 집에 배달할 물류창고의 개수는 50이하, 각 집이 가지고 있는 빈 물류창고의 개수도 50이하

풀이 전략
- 가장 먼 집까지 먼저 가야함.
- 가장 먼 물류창고를 들고 (cap - 가장 먼 물류창고의 개수)를 다음으로 먼 물류창고의 개수를 포함되면 또 든다.
- 물류창고로 돌아오면서 가장 먼집에 있는 빈 물류창고부터 회수한다.
- 회수하면서 (cap - 가장 먼 집에 있는 빈 물류창고의 개수)를 다음으로 먼 물류창고의 개수를 포함되면 또 들고 물류창고까지 간다.
- 반복한다.
- 

너 머리를 의심하지마.
너 똑똑해. 이 문제를 계속 풀지 못했던 이유는
일단 최근 너의 집중력이 많이 낮아졌음.
문제의 예제를 분석해서 제약조건을 찾지 못함.
그래서 계속 안풀림 . 왜 안풀림 무한 악순환. 


































*/