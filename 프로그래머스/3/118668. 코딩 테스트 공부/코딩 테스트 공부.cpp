#include <string>
#include <vector>
using namespace std;

int dp[151][151];

const int INF = 20'000'000 ; // 임의로 작성

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int alp_max = -1, cop_max = -1 ; // 문제에서 무조건 가장 작은 임의 값으로 설정함
    for(auto problem : problems) {
	    alp_max = max(alp_max, problem[0]);
	    cop_max = max(cop_max, problem[1]);
    }
    // 이미 모든 문제를 풀 수 있는 상황의 예외처리 고려 
    alp = min(alp,alp_max); 
    cop = min(cop,cop_max);
    
    for(int i = 0 ; i <= alp_max; i++) fill(dp[i],dp[i]+cop_max+1,INF);
    dp[alp][cop] = 0 ; // dp 초기값
    
    // 본격적으로 바텀업방식으로 dp원소들 채우기
    for(int i = alp ; i<=alp_max ; i++){
	    for(int j = cop ; j<=cop_max ; j++){
		    dp[i+1][j] = min(dp[i+1][j],dp[i][j]+1); // 점화식 1번
				dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1); // 점화식 2번
		    
		    for(auto problem: problems) {
			    int alp_req, cop_req, alp_rwd, cop_rwd, cost;
			    alp_req= problem[0];
			    cop_req= problem[1];
			    alp_rwd= problem[2];
			    cop_rwd= problem[3];
			    cost= problem[4];
			    if(i < alp_req || j < cop_req) continue;
			    dp[min(alp_max,i+alp_rwd)][min(cop_max, j+cop_rwd)] = min(dp[min(alp_max,i+alp_rwd)][min(cop_max, j+cop_rwd)], dp[i][j]+cost); // 점화식 3번
		    }
	    }
	    
    }

    
    return dp[alp_max][cop_max];
}